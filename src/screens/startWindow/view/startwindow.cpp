#include "startwindow.h"
#include "src/screens/startWindow/settings/settingupstartwindow.h"
#include "src/screens/createTaskWindow/view/createtask.h"
#include "src/screens/startWindow/widgets/TaskWidget/view/task.h"
#include "src/screens/startWindow/controller/taskloadercontroller.h"

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow{parent}
    , ui(new Ui::StartWindow)
    , taskListModel(new TaskListModel(this, this))
    , fileManager(new FileManager())
    , b_createTaskIsOpen(false)
    , lastId(0)
    , fileDir("task.json")
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    SettingUpStartWindow settings;
    settings.settingUpWidgets(ui);

    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [=](){
        buttonControl(ui->tabWidget->currentIndex());
    });

    connect(this, &StartWindow::deleteTaskInFileSignal, fileManager, &FileManager::deleteTaskInFile, Qt::DirectConnection);
    connect(this, &StartWindow::completeTaskInFileSignal, fileManager, &FileManager::completeTaskInFile, Qt::DirectConnection);
    
    if(fileManager->checkFile(fileDir) && !fileManager->fileIsEmpty(fileDir))
    {
        loadingExistingTasks();
    }
}

void StartWindow::loadingExistingTasks() // загрузка существующих задач
{
    QJsonArray jsonArray = fileManager->readTaskFromFile(fileDir);

    gettingTasks(jsonArray);
}

void StartWindow::gettingTasks(const QJsonArray& jsonArray) // получение задач
{
    TaskLoaderController taskLoaderController(this, taskListModel, this);
    taskLoaderController.loadTasksFromJson(jsonArray);
}

void StartWindow::showTasks(QList<Task*>& taskList) // отображение задач
{
    for(auto& task : taskList)
    {
        if(task->isDone())
        {
            task->setParent(ui->scrollAreaWidgetContents_completed);
            task->setAttribute(Qt::WA_DeleteOnClose);
            ui->scrollAreaWidgetContents_completed->layout()->addWidget(task);
        }
        else
        {
            if(task->getDateTime() == "0")
            {
                task->setParent(ui->scrollAreaWidgetContents_today);
                task->setAttribute(Qt::WA_DeleteOnClose);
                ui->scrollAreaWidgetContents_today->layout()->addWidget(task);
            }
            else
            {
                QDateTime taskDateTime = QDateTime::fromString(task->getDateTime(), "dd.MM.yyyy HH:mm");
                QDateTime currentDateTime = QDateTime::currentDateTime();

                if(taskDateTime > currentDateTime)
                {
                    task->setParent(ui->scrollAreaWidgetContents_upcoming);
                    task->setAttribute(Qt::WA_DeleteOnClose);
                    ui->scrollAreaWidgetContents_upcoming->layout()->addWidget(task);
                }
                else
                {
                    task->setParent(ui->scrollAreaWidgetContents_today);
                    task->setAttribute(Qt::WA_DeleteOnClose);
                    ui->scrollAreaWidgetContents_today->layout()->addWidget(task);
                }
            }
        }
        if(task == taskList.last())
        {
            updateId(task->getId());
        }
    }
    startCheckTimeInThread();
}

void StartWindow::on_pushButton_createTask_clicked()
{
    if(b_createTaskIsOpen)
    {
        qDebug() << "Окно уже открыто";
        return;
    }

    QMessageBox::StandardButton butt = QMessageBox::question(this, "Вопрос", "Запланировать дату и время?", QMessageBox::Yes | QMessageBox::No);

    bool b_createDateTime;

    if(butt == QMessageBox::Yes)
    {
        b_createDateTime = true;
    }
    else
    {
        b_createDateTime = false;
    }

    CreateTask* newTask = new CreateTask(fileManager, taskListModel, fileDir, lastId, b_createDateTime, this);

    newTask->setWindowFlag(Qt::Window);
    newTask->setAttribute(Qt::WA_DeleteOnClose);
    newTask->show();

    b_createTaskIsOpen = true;

    connect(newTask, &CreateTask::closeWindow, this, [=](){
        b_createTaskIsOpen = false;
    });
}

void StartWindow::buttonControl(int index) // управление кнопкой добавления задачи
{
    if(index == 2)
    {
        ui->pushButton_createTask->hide();
    }
    else
    {
        ui->pushButton_createTask->show();
    }
}

void StartWindow::showNewTask(Task* task) // отображение новой задачи
{
    lastId++;

    if(task->getDateTime() == "0")
    {
        task->setParent(ui->scrollAreaWidgetContents_today);
        task->setAttribute(Qt::WA_DeleteOnClose);
        ui->scrollAreaWidgetContents_today->layout()->addWidget(task);
    }
    else
    {
        QDateTime taskDateTime = QDateTime::fromString(task->getDateTime(), "dd.MM.yyyy HH:mm");
        QDateTime currentDateTime = QDateTime::currentDateTime();

        if(taskDateTime > currentDateTime)
        {
            task->setParent(ui->scrollAreaWidgetContents_upcoming);
            task->setAttribute(Qt::WA_DeleteOnClose);
            ui->scrollAreaWidgetContents_upcoming->layout()->addWidget(task);
        }
        else
        {
            task->setParent(ui->scrollAreaWidgetContents_today);
            task->setAttribute(Qt::WA_DeleteOnClose);
            ui->scrollAreaWidgetContents_today->layout()->addWidget(task);
        }
    }
}

void StartWindow::updateId(const quint64& id) // обновление значения lastId
{
    lastId = id;
}

void StartWindow::moveTaskToToday(Task* task) // переметстиь задачу в "Сегодня"
{
    ui->scrollAreaWidgetContents_upcoming->layout()->removeWidget(task);

    task->setParent(ui->scrollAreaWidgetContents_today);
    task->setAttribute(Qt::WA_DeleteOnClose);
    ui->scrollAreaWidgetContents_today->layout()->addWidget(task);
}

void StartWindow::startCheckTimeInThread() // начало проверки времени задач
{
    threadManager = new ThreadManager(taskListModel, this, this);

    connect(this, &StartWindow::stopThread, threadManager, &ThreadManager::stopChecking);
}

void StartWindow::createTaskDescriptionWindow(Task* task) // создание окна с информацие о задаче
{
    TaskDescriptionWindow* taskDescriptionWindow = new TaskDescriptionWindow(taskListModel, this, task, this);

    connect(task, &Task::close, taskDescriptionWindow, &TaskDescriptionWindow::deleteLater);

    taskDescriptionWindow->setWindowFlag(Qt::Window);
    taskDescriptionWindow->setAttribute(Qt::WA_DeleteOnClose);
    taskDescriptionWindow->show();
}

void StartWindow::deleteTask(Task* task) // удаление задачи
{
    emit deleteTaskInFileSignal(task->getId(), fileDir);

    task->deleteLater();
}

void StartWindow::completeTheTask(Task* task) // завершение задачи
{
    emit completeTaskInFileSignal(task->getId(), fileDir);

    moveTaskToCompleted(task);
}

void StartWindow::moveTaskToCompleted(Task* task) // переместить задачу в "Заверешённые"
{
    task->setParent(ui->scrollAreaWidgetContents_completed);
    task->setAttribute(Qt::WA_DeleteOnClose);
    ui->scrollAreaWidgetContents_completed->layout()->addWidget(task);
}

StartWindow::~StartWindow()
{
    emit stopTimer();
    emit stopThread();

    if(fileManager)
    {
        delete fileManager;
        fileManager = nullptr;
    }
}
