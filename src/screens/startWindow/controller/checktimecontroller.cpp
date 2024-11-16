#include "checktimecontroller.h"
#include "src/screens/startWindow/view/startwindow.h"
#include "src/screens/startWindow/widgets/TaskWidget/view/task.h"
#include "src/screens/startWindow/widgets/TaskWidget/model/tasklistmodel.h"
#include <QTimer>
#include <QDateTime>

CheckTimeController::CheckTimeController(StartWindow* window, TaskListModel* taskListModel, QObject* parent)
    : QObject(parent), timer(new QTimer(this)), window(window), taskListModel(taskListModel), b_work(false)
{
    connect(this, &CheckTimeController::updateTaskInWidget, window, &StartWindow::moveTaskToToday, Qt::QueuedConnection);
    connect(this, &CheckTimeController::removeTaskInList, taskListModel, &TaskListModel::removeUpComingTask, Qt::DirectConnection);
    connect(window, &StartWindow::stopTimer, this, &CheckTimeController::stopTimer);
    connect(timer, &QTimer::timeout, this, &CheckTimeController::checkTimeSlot);
    connect(this, &CheckTimeController::updateTimer, this, &CheckTimeController::startTimer);
}

void CheckTimeController::checkTime(const QList<Task*>& upComingTaskList)
{
    for(const auto& i : upComingTaskList)
    {
        QDateTime taskDateTime = QDateTime::fromString(i->getDateTime(), "dd.MM.yyyy HH:mm");
        QDateTime currentDateTime = QDateTime::currentDateTime();

        if(taskDateTime == currentDateTime && !i->isDone())
        {
            emit updateTaskInWidget(i);
            emit removeTaskInList(i);
        }
    }
}

void CheckTimeController::checkTimeSlot()
{
    b_work = true;

    checkTime(taskListModel->getUpComingTasks());

    b_work = false;

    if (!QThread::currentThread()->isInterruptionRequested())
    {
        emit updateTimer();
    }
}

void CheckTimeController::startTimer()
{
    QTime currentTime = QTime::currentTime();

    int msecsToNextMinute = 60000 - currentTime.second() * 1000 - currentTime.msec();

    timer->start(msecsToNextMinute);
}

bool CheckTimeController::getWork()
{
    return b_work;
}

void CheckTimeController::stopTimer()
{
    if(!b_work)
    {
        timer->stop();
    }
    else
    {
        QTimer::singleShot(100, this, &CheckTimeController::stopTimer);
    }
}
