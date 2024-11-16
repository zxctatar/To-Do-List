/********************************************************************************
** Form generated from reading UI file 'task.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task
{
public:
    QGridLayout *gridLayout;
    QLabel *label_name;
    QLabel *label_time;

    void setupUi(QWidget *Task)
    {
        if (Task->objectName().isEmpty())
            Task->setObjectName("Task");
        Task->resize(500, 60);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Task->sizePolicy().hasHeightForWidth());
        Task->setSizePolicy(sizePolicy);
        Task->setMinimumSize(QSize(500, 60));
        Task->setMaximumSize(QSize(16777215, 60));
        Task->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: rgb(153, 193, 241); \n"
"}"));
        gridLayout = new QGridLayout(Task);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_name = new QLabel(Task);
        label_name->setObjectName("label_name");
        label_name->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_name->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_name->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_name, 0, 0, 1, 1);

        label_time = new QLabel(Task);
        label_time->setObjectName("label_time");
        label_time->setMaximumSize(QSize(150, 16777215));
        label_time->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_time->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_time, 0, 1, 1, 1);


        retranslateUi(Task);

        QMetaObject::connectSlotsByName(Task);
    } // setupUi

    void retranslateUi(QWidget *Task)
    {
        Task->setWindowTitle(QCoreApplication::translate("Task", "Task", nullptr));
        label_name->setText(QString());
        label_time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Task: public Ui_Task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
