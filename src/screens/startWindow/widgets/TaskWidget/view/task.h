#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QString>
#include <QMouseEvent>
#include "ui_task.h"

class StartWindow;

class Task : public QWidget
{
    Q_OBJECT
public:
    explicit Task(StartWindow* startWindow, quint64 id, QString& name, QString& dateTime, QString& description, bool done, QWidget *parent = nullptr);

    Task(const Task& other);

    Task& operator=(const Task& other);

    quint64 getId() const;
    QString getDateTime() const;
    QString getName() const;
    QString getDescription() const;
    bool isDone() const;

    ~Task();

signals:
    void taskClicked(Task* task);
    void close();

public slots:
    void complete();

private:
    StartWindow* startWindow;
    quint64 id;
    QString name;
    QString dateTime;
    QString description;
    bool done;
    Ui::Task* ui;

    void mousePressEvent(QMouseEvent* event);
};

#endif // TASK_H
