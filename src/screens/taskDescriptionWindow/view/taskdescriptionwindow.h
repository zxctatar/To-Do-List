#ifndef TASKDESCRIPTIONWINDOW_H
#define TASKDESCRIPTIONWINDOW_H

#include <QWidget>
#include <ui_taskdescriptionwindow.h>
#include "src/screens/startWindow/widgets/TaskWidget/view/task.h"
#include "src/screens/taskDescriptionWindow/manager/taskmanagmentmanager.h"

class StartWindow;
class TaskListModel;

class TaskDescriptionWindow : public QWidget
{
public:
    TaskDescriptionWindow(TaskListModel* taskListModel, StartWindow* startWindow, Task* task, QWidget* parent = nullptr);

private slots:
    void on_pushButton_delete_clicked();

    void on_pushButton_done_clicked();

private:
    Ui::TaskDescriptionWindow* ui;

    Task* task;
    StartWindow* startWindow;
    TaskManagmentManager* taskManagmentManager;
    TaskListModel* taskListModel;

    bool checkDateTime() const;
    void loadTaskDescription() const;
};

#endif // TASKDESCRIPTIONWINDOW_H
