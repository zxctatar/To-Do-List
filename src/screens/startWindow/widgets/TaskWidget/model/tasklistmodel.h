#ifndef TASKLISTMODEL_H
#define TASKLISTMODEL_H

#include <QList>
#include <QObject>
#include <QPair>
#include <QJsonArray>
#include <QMutex>
#include "src/screens/startWindow/widgets/TaskWidget/view/task.h"

class StartWindow;

class TaskListModel : public QObject
{
    Q_OBJECT

public:
    explicit TaskListModel(StartWindow* startWindow, QObject* parent);

    void loadTasks(const QJsonArray& jsonArray); // загрузка задач
    void addNewTask(quint64 id, QString& name, QString& description, QString& dateTime, bool done); // добавление новой задачи

    QList<Task*> getAllTasks() const; // получить список всех задач
    QList<Task*> getUpComingTasks() const; // получить список предстоящих задач

signals:
    void loadDone(QList<Task*>& taskList);
    void newTask(Task* task);
    void completeTheTaskSignal();

public slots:
    void removeUpComingTask(const Task* task); // убрать предстоящую задачу
    void deleteTask(Task* task);
    void completeTheTask(Task* task);

private:
    StartWindow* startWindow;

    QList<Task*> allTasks;
    QList<Task*> upComingTasks;

    void addUpComingTask(Task* task);

    mutable QMutex mutex;
};

#endif // TASKLISTMODEL_H
