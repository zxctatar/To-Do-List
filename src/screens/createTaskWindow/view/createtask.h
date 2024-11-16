#ifndef CREATETASK_H
#define CREATETASK_H

#include <QWidget>
#include <QMessageBox>
#include <QCloseEvent>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>
#include <QFile>
#include "src/manager/filemanager.h"
#include "src/screens/startWindow/widgets/TaskWidget/model/tasklistmodel.h"
#include "src/screens/createTaskWindow/controller/addtaskcontroller.h"
#include "ui_createtask.h"

class CreateTask : public QWidget
{
    Q_OBJECT
public:
    explicit CreateTask(FileManager* fileManager, TaskListModel* taskListModel, QString& fileDir, quint64 lastId, bool createDateTime, QWidget *parent = nullptr);

    ~CreateTask();

signals:
    void closeWindow();

private slots:
    void on_pushButton_done_clicked();

private:
    Ui::CreateTask* ui;

    AddTaskController* addTaskController;
    TaskListModel* taskListModel;
    QMessageBox message;
    FileManager* fileManager;

    bool validateInput(); // проверка на ввод данных
    void showError(const QString& error); // уведомление об ошибке

    quint64 lastId;
    void closeEvent(QCloseEvent* event) override;
    bool createDateTime;

    QString fileDir;
};

#endif // CREATETASK_H
