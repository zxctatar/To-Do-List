#ifndef ADDTASKCONTROLLER_H
#define ADDTASKCONTROLLER_H

#include <QObject>
#include "src/screens/startWindow/view/startwindow.h"
#include "src/screens/startWindow/widgets/TaskWidget/model/tasklistmodel.h"

class AddTaskController  : public QObject
{
    Q_OBJECT

public:
    explicit AddTaskController (StartWindow* window, TaskListModel* taskListModel, QObject* parent = nullptr);

    void handleAddNewTask(quint64 id, QString& name, QString& dateTime, QString& description, bool done) const;

private:
    StartWindow* window;
    TaskListModel* taskListModel;
};

#endif // ADDTASKCONTROLLER_H
