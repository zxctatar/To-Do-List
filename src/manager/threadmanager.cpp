#include "threadmanager.h"
#include "src/screens/startWindow/view/startwindow.h"

ThreadManager::ThreadManager(TaskListModel* taskListModel, StartWindow* window, QObject* parent)
    : QObject(parent), window(window), taskListModel(taskListModel), checkTimeController(new CheckTimeController(window, taskListModel)), checkTimeThread(new QThread(this))
{
    checkTimeController->moveToThread(checkTimeThread);

    connect(checkTimeThread, &QThread::finished, checkTimeThread, &QObject::deleteLater);
    connect(this, &StartWindow::destroyed, checkTimeThread, &QThread::quit);
    connect(checkTimeThread, &QThread::finished, checkTimeController, &QObject::deleteLater);

    startCheckingTime();
}

void ThreadManager::startCheckingTime()
{
    connect(checkTimeThread, &QThread::started, checkTimeController, &CheckTimeController::startTimer);

    checkTimeThread->start();
}

void ThreadManager::stopChecking()
{
    checkTimeThread->quit();
    checkTimeThread->wait();

    checkTimeController->disconnect();
    checkTimeController->deleteLater();
}

ThreadManager::~ThreadManager()
{
    if(checkTimeController)
    {
        checkTimeController->deleteLater();
    }
}
