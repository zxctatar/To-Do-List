#include "tasklistmodel.h"
#include "src/screens/startWindow/view/startwindow.h"
#include <QJsonObject>
#include <QDateTime>
#include <QThread>

TaskListModel::TaskListModel(StartWindow* startWindow, QObject* parent) : QObject(parent), startWindow(startWindow)
{
}

void TaskListModel::loadTasks(const QJsonArray& jsonArray) // загрузка задач
{
    for(const auto& i : jsonArray)
    {
        if(i.isObject())
        {
            QJsonObject object = i.toObject();

            quint64 id = object["id"].toInt();
            QString name = object["name"].toString();
            QString description = object["description"].toString();
            QString dateTime = object["dateTime"].toString();
            bool done = object["done"].isBool();

            Task* task = new Task
                {
                    startWindow,
                    id,
                    name,
                    dateTime,
                    description,
                    done
                };

            allTasks.append(task);

            addUpComingTask(task);
        }
    }

    emit loadDone(allTasks);
}

void TaskListModel::addNewTask(quint64 id, QString& name, QString& dateTime, QString& description, bool done)
{
    Task* task = new Task
        {
            startWindow,
            id,
            name,
            dateTime,
            description,
            done
        };

    allTasks.append(task);

    addUpComingTask(task);

    emit newTask(task);
}

QList<Task*> TaskListModel::getAllTasks() const // получить список всех задач
{
    return allTasks;
}

QList<Task*> TaskListModel::getUpComingTasks() const // получить список предстоящих задач
{
    QMutexLocker locker(&mutex);

    return upComingTasks;
}

void TaskListModel::removeUpComingTask(const Task* task) // убрать предстоящую задачу
{
    QMutexLocker locker(&mutex);

    upComingTasks.removeOne(task);
}

void TaskListModel::deleteTask(Task* task)
{
    QMutexLocker locker(&mutex);

    allTasks.removeOne(task);

    if(upComingTasks.contains(task))
    {
        upComingTasks.removeOne(task);
    }
}

void TaskListModel::addUpComingTask(Task* task)
{
    QMutexLocker locker(&mutex);

    if(QDateTime::fromString(task->getDateTime(), "dd.MM.yyyy HH:mm") > QDateTime::currentDateTime())
    {
        upComingTasks.append(task);
    }
}

void TaskListModel::completeTheTask(Task* task)
{
    QMutexLocker locker(&mutex);

    if(upComingTasks.contains(task))
    {
        upComingTasks.removeOne(task);
    }

    connect(this, &TaskListModel::completeTheTaskSignal, task, &Task::complete, Qt::DirectConnection);

    emit completeTheTaskSignal();
}
