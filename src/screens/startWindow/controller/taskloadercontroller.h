#ifndef TASKLOADERCONTROLLER_H
#define TASKLOADERCONTROLLER_H

#include <QObject>
#include <QJsonArray>
#include <src/screens/startWindow/view/startwindow.h>
#include <src/screens/startWindow/widgets/TaskWidget/model/tasklistmodel.h>

class TaskLoaderController : public QObject
{
    Q_OBJECT

public:
    explicit TaskLoaderController(StartWindow* window, TaskListModel* taskListModel, QObject* parent = nullptr);

    void loadTasksFromJson(const QJsonArray& jsonArray) const; // загрузка задач из Json

private:
    StartWindow* window;
    TaskListModel* taskListModel;
};

#endif // TASKLOADERCONTROLLER_H
