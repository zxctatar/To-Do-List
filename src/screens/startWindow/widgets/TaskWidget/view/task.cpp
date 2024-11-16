#include "src/screens/startWindow/widgets/TaskWidget/view/task.h"
#include "src/screens/startWindow/view/startwindow.h"

#include <QTextDocument>
#include <QTextOption>

Task::Task(StartWindow* startWindow, quint64 id, QString& name, QString& dateTime, QString& description, bool done, QWidget *parent)
    : QWidget{parent}
    , startWindow(startWindow)
    , id(id)
    , name(name)
    , dateTime(dateTime)
    , description(description)
    , done(done)
    , ui(new Ui::Task)
{
    ui->setupUi(this);

    if(dateTime == "0")
    {
        ui->label_time->hide();
    }
    else
    {
        ui->label_time->setText(dateTime);
    }

    ui->label_name->setText(name);

    connect(this, &Task::taskClicked, startWindow, &StartWindow::createTaskDescriptionWindow);

    this->setCursor(Qt::PointingHandCursor);
}

Task::Task(const Task& other) :
    QWidget{other.parentWidget()},
    id(other.id),
    name(other.name),
    dateTime(other.dateTime),
    description(other.description),
    done(other.done),
    ui(new Ui::Task)
{
    ui->setupUi(this);

    if(dateTime == "0")
    {
        ui->label_time->hide();
    }
    else
    {
        ui->label_time->setText(dateTime);
    }

    ui->label_name->setText(name);

    connect(this, &Task::taskClicked, startWindow, &StartWindow::createTaskDescriptionWindow);

    this->setCursor(Qt::PointingHandCursor);
}

Task& Task::operator=(const Task& other)
{
    if(this != &other)
    {
        id = other.id;
        name = other.name;
        dateTime = other.dateTime;
        description = other.description;
        done = other.done;

        this->setParent(other.parentWidget());
    }

    return *this;
}

bool Task::isDone() const
{
    return done;
}

QString Task::getDateTime() const
{
    return dateTime;
}

QString Task::getName() const
{
    return name;
}

QString Task::getDescription() const
{
    return description;
}

quint64 Task::getId() const
{
    return id;
}

void Task::mousePressEvent(QMouseEvent* event)
{
    emit taskClicked(this);
    event->accept();
}

void Task::complete()
{
    if(!done)
    {
        done = true;
    }
}

Task::~Task()
{
    emit close();
}
