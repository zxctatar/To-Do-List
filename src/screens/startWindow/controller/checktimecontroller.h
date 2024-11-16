#ifndef CHECKTIMECONTROLLER_H
#define CHECKTIMECONTROLLER_H

#include <QObject>
#include <QList>
#include <QTimer>

class StartWindow;
class Task;
class TaskListModel;

class CheckTimeController : public QObject
{
    Q_OBJECT

public:
    CheckTimeController(StartWindow* window, TaskListModel* taskListModel, QObject* parent = nullptr);

    bool getWork();

signals:
    void updateTaskInWidget(Task* task);
    void removeTaskInList(Task* task);
    void updateTimer();

public slots:
    void checkTimeSlot();
    void stopTimer();
    void startTimer();

private:
    void checkTime(const QList<Task*>& upComingTaskList);

    QTimer* timer;
    StartWindow* window;
    TaskListModel* taskListModel;

    bool b_work;
};

#endif // CHECKTIMECONTROLLER_H
