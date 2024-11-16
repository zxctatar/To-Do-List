#include "addtaskcontroller.h"

AddTaskController::AddTaskController(StartWindow* window, TaskListModel* taskListModel, QObject* parent)
    :  QObject(parent), window(window), taskListModel(taskListModel)
{
    connect(taskListModel, &TaskListModel::newTask, window, &StartWindow::showNewTask, Qt::UniqueConnection);
}

void AddTaskController::handleAddNewTask(quint64 id, QString& name, QString& dateTime, QString& description, bool done) const
{
    taskListModel->addNewTask(id, name, dateTime, description, done);
}
