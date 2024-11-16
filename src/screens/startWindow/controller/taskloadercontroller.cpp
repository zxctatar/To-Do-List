#include "taskloadercontroller.h"

TaskLoaderController::TaskLoaderController(StartWindow* window, TaskListModel* taskListModel, QObject* parent)
    : QObject(parent), window(window), taskListModel(taskListModel)
{
    connect(taskListModel, &TaskListModel::loadDone, window, &StartWindow::showTasks);
}

void TaskLoaderController::loadTasksFromJson(const QJsonArray& jsonArray) const // загрузка задач из Json
{
    taskListModel->loadTasks(jsonArray);
}
