#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include "src/screens/startWindow/controller/checktimecontroller.h"
#include <QObject>
#include <QThread>

class StartWindow;

class ThreadManager : public QObject
{
    Q_OBJECT
public:
    explicit ThreadManager(TaskListModel* taskListModel, StartWindow* window, QObject* parent = nullptr);

    ~ThreadManager();

public slots:
    void stopChecking();

private:
    StartWindow* window;
    TaskListModel* taskListModel;
    CheckTimeController* checkTimeController;
    QThread* checkTimeThread;

    void startCheckingTime();
};

#endif // THREADMANAGER_H
