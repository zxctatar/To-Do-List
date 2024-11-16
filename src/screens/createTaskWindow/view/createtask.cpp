#include "createtask.h"

CreateTask::CreateTask(FileManager* fileManager, TaskListModel* taskListModel, QString& fileDir, quint64 lastId, bool createDateTime, QWidget *parent)
    : QWidget{parent}
    , ui(new Ui::CreateTask)
    , taskListModel(taskListModel)
    , fileManager(fileManager)
    , lastId(lastId)
    , createDateTime(createDateTime)
    , fileDir(fileDir)
{
    ui->setupUi(this);

    StartWindow* parentWindow = dynamic_cast<StartWindow*>(parent);
    if(!parentWindow)
    {
        qDebug() << "Error CreateTask parentWindow";
    }

    addTaskController = new AddTaskController(parentWindow, taskListModel, this);

    if(!createDateTime)
    {
        ui->dateTimeEdit->hide();
        ui->label_dateTime->hide();
    }
}

CreateTask::~CreateTask()
{}

void CreateTask::closeEvent(QCloseEvent* event)
{
    emit closeWindow();

    event->accept();
}

bool CreateTask::validateInput() // проверка на ввод данных
{
    if(ui->lineEdit_name->text() == "")
    {
        showError(QString::fromStdString("Заполните название"));
        return false;
    }
    if(ui->textEdit_description->toPlainText() == "")
    {
        showError(QString::fromStdString("Заполнить описание"));
        return false;
    }
    return true;
}

void CreateTask::showError(const QString& error) // уведомление об ошибке
{
    message.setWindowTitle("Ошибка");
    message.setText(error);
    message.exec();
}

void CreateTask::on_pushButton_done_clicked()
{
    if(!validateInput())
    {
        return;
    }

    if(!fileManager->checkFile(fileDir))
    {
        fileManager->createJsonFile(fileDir);
    }

    QFile file(fileDir);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Ошибка открытия файла чтения createTask" << file.errorString();
        return;
    }

    QString name = ui->lineEdit_name->text();
    QString dateTime;
    QString description = ui->textEdit_description->toPlainText();
    bool done = false;

    if(!createDateTime)
    {
        dateTime = "0";
    }
    else
    {
        dateTime = ui->dateTimeEdit->text();
    }

    lastId++;

    fileManager->createNewTask(fileDir, lastId, name, dateTime, description, done);

    addTaskController->handleAddNewTask(lastId, name, dateTime, description, done);

    this->close();
}

