#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QCloseEvent>
#include "ui_startwindow.h"
#include "src/manager/filemanager.h"
#include "src/screens/startWindow/widgets/TaskWidget/model/tasklistmodel.h"
#include "src/screens/startWindow/controller/checktimecontroller.h"
#include "src/manager/threadmanager.h"
#include "src/screens/taskDescriptionWindow/view/taskdescriptionwindow.h"

class StartWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit StartWindow(QWidget *parent = nullptr);

    ~StartWindow();

signals:
    void stopTimer();
    void stopThread();
    void deleteTaskInFileSignal(quint64 id, QString& fileDir);
    void completeTaskInFileSignal(quint64 id, QString& fileDir);

private slots:
    void on_pushButton_createTask_clicked();

public slots:
    void showTasks(QList<Task*>& taskList); // отображение задач
    void showNewTask(Task* task); // отображение новой задачи
    void moveTaskToToday(Task* task); // переметстиь задачу в "Сегодня"
    void createTaskDescriptionWindow(Task* task); // создание окна с информацие о задаче
    void deleteTask(Task* task); // удаление задачи
    void completeTheTask(Task* task); // завершение задачи
    void moveTaskToCompleted(Task* task); // переместить задачу в "Завершённые"

private:
    Ui::StartWindow* ui;

    TaskListModel* taskListModel;
    FileManager* fileManager;
    ThreadManager* threadManager;
    QThread* checkTimeThread;

    void buttonControl(int index); // управление кнопкой добавления задачи
    void loadingExistingTasks(); // загрузка существующих задач
    void gettingTasks(const QJsonArray& jsonArray); // получение задач
    void updateId(const quint64& id); // обновление значения lastId
    void startCheckTimeInThread(); // начало проверки времени задач

    bool b_createTaskIsOpen;
    quint64 lastId;

    QString fileDir;

};

#endif // STARTWINDOW_H
