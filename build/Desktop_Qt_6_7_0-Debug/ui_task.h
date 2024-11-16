/********************************************************************************
** Form generated from reading UI file 'task.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_name;
    QLabel *label_date;

    void setupUi(QWidget *Task)
    {
        if (Task->objectName().isEmpty())
            Task->setObjectName("Task");
        Task->resize(250, 290);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Task->sizePolicy().hasHeightForWidth());
        Task->setSizePolicy(sizePolicy);
        Task->setMinimumSize(QSize(170, 210));
        Task->setMaximumSize(QSize(250, 290));
        Task->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 193, 241);"));
        gridLayout = new QGridLayout(Task);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(Task);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(170, 210));
        frame->setMaximumSize(QSize(250, 290));
        frame->setStyleSheet(QString::fromUtf8("border: 2px solid black;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_name = new QLabel(frame);
        label_name->setObjectName("label_name");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_name->setFont(font);
        label_name->setStyleSheet(QString::fromUtf8("border: none;\n"
"color: black;"));
        label_name->setWordWrap(true);

        verticalLayout_2->addWidget(label_name);

        label_date = new QLabel(frame);
        label_date->setObjectName("label_date");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_date->sizePolicy().hasHeightForWidth());
        label_date->setSizePolicy(sizePolicy1);
        label_date->setMinimumSize(QSize(0, 50));
        label_date->setMaximumSize(QSize(16777215, 50));
        label_date->setFont(font);
        label_date->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border: 2px rgb(153, 193, 241);\n"
"border-top: 2px solid black;"));
        label_date->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_date);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(Task);

        QMetaObject::connectSlotsByName(Task);
    } // setupUi

    void retranslateUi(QWidget *Task)
    {
        Task->setWindowTitle(QCoreApplication::translate("Task", "Task", nullptr));
        label_name->setText(QString());
        label_date->setText(QCoreApplication::translate("Task", "\320\221\320\273\320\260\320\221\320\273\320\260\320\261\320\273\320\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Task: public Ui_Task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
