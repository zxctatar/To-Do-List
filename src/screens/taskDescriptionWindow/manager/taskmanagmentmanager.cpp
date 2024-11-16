#include "taskmanagmentmanager.h"
#include "src/screens/startWindow/view/startwindow.h"
#include "src/screens/startWindow/widgets/TaskWidget/view/task.h"
#include "src/screens/startWindow/widgets/TaskWidget/model/tasklistmodel.h"

TaskManagmentManager::TaskManagmentManager(TaskListModel* taskListModel, StartWindow* startWindow, QObject* parent)
    : QObject(parent)
    , startWindow(startWindow)
    , taskListModel(taskListModel)
{
    connect(this, &TaskManagmentManager::deleteTaskSignal, taskListModel, &TaskListModel::deleteTask);
    connect(this, &TaskManagmentManager::deleteTaskSignal, startWindow, &StartWindow::deleteTask);

    connect(this, &TaskManagmentManager::completeTheTaskSignal, taskListModel, &TaskListModel::completeTheTask);
    connect(this, &TaskManagmentManager::completeTheTaskSignal, startWindow, &StartWindow::completeTheTask);
}

void TaskManagmentManager::deleteTask(Task* task)
{
    emit deleteTaskSignal(task);
}

void TaskManagmentManager::completeTheTask(Task* task)
{
    emit completeTheTaskSignal(task);
}
