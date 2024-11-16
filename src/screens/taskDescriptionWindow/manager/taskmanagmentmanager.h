#ifndef TASKMANAGMENTMANAGER_H
#define TASKMANAGMENTMANAGER_H

#include <QObject>

class StartWindow;
class Task;
class TaskListModel;

class TaskManagmentManager : public QObject
{
    Q_OBJECT

public:
    TaskManagmentManager(TaskListModel* taskListModel, StartWindow* startWindow, QObject* parent = nullptr);

    void deleteTask(Task* task);
    void completeTheTask(Task* task);

signals:
    void deleteTaskSignal(Task* task);
    void completeTheTaskSignal(Task* task);

private:
    StartWindow* startWindow;
    TaskListModel* taskListModel;
};

#endif // TASKMANAGMENTMANAGER_H
