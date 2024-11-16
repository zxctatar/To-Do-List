#include "taskdescriptionwindow.h"
#include <QStyleFactory>
#include "src/screens/startWindow/widgets/TaskWidget/model/tasklistmodel.h"

TaskDescriptionWindow::TaskDescriptionWindow(TaskListModel* taskListModel, StartWindow* startWindow, Task* task, QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::TaskDescriptionWindow)
    , task(task)
    , startWindow(startWindow)
    , taskManagmentManager(new TaskManagmentManager(taskListModel, startWindow, this))
    , taskListModel(taskListModel)
{
    ui->setupUi(this);

    if(!checkDateTime())
    {
        ui->label_dateTime->hide();
        ui->lineEdit_date->hide();
    }

    if(task->isDone())
    {
        ui->pushButton_done->hide();
    }

    loadTaskDescription();

    connect(ui->pushButton_delete, &QPushButton::clicked, this, &TaskDescriptionWindow::on_pushButton_delete_clicked);
    connect(ui->pushButton_done, &QPushButton::clicked, this, &TaskDescriptionWindow::on_pushButton_done_clicked);
}

bool TaskDescriptionWindow::checkDateTime() const
{
    return task->getDateTime() == "0" ? false : true;
}

void TaskDescriptionWindow::loadTaskDescription() const
{
    ui->lineEdit_name->setText(task->getName());

    if(checkDateTime())
    {
        ui->lineEdit_date->setText(task->getDateTime());
    }

    ui->textBrowser_description->setText(task->getDescription());
}

void TaskDescriptionWindow::on_pushButton_delete_clicked()
{
    taskManagmentManager->deleteTask(task);
}

void TaskDescriptionWindow::on_pushButton_done_clicked()
{
    taskManagmentManager->completeTheTask(task);

    ui->pushButton_done->hide();
}

