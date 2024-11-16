/********************************************************************************
** Form generated from reading UI file 'createtask.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETASK_H
#define UI_CREATETASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateTask
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_dateTime;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_description;
    QTextEdit *textEdit_description;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_done;

    void setupUi(QWidget *CreateTask)
    {
        if (CreateTask->objectName().isEmpty())
            CreateTask->setObjectName("CreateTask");
        CreateTask->resize(420, 480);
        CreateTask->setMinimumSize(QSize(320, 320));
        CreateTask->setMaximumSize(QSize(420, 480));
        CreateTask->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(CreateTask);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_name = new QLabel(CreateTask);
        label_name->setObjectName("label_name");
        QFont font;
        font.setPointSize(12);
        label_name->setFont(font);
        label_name->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_name);

        lineEdit_name = new QLineEdit(CreateTask);
        lineEdit_name->setObjectName("lineEdit_name");
        QFont font1;
        font1.setPointSize(10);
        lineEdit_name->setFont(font1);
        lineEdit_name->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_name->setMaxLength(50);

        verticalLayout->addWidget(lineEdit_name);

        label_dateTime = new QLabel(CreateTask);
        label_dateTime->setObjectName("label_dateTime");
        label_dateTime->setFont(font);
        label_dateTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_dateTime);

        dateTimeEdit = new QDateTimeEdit(CreateTask);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(dateTimeEdit);

        label_description = new QLabel(CreateTask);
        label_description->setObjectName("label_description");
        label_description->setFont(font);
        label_description->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(label_description);

        textEdit_description = new QTextEdit(CreateTask);
        textEdit_description->setObjectName("textEdit_description");
        textEdit_description->setFont(font1);
        textEdit_description->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(textEdit_description);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_done = new QPushButton(CreateTask);
        pushButton_done->setObjectName("pushButton_done");
        pushButton_done->setMinimumSize(QSize(70, 30));
        pushButton_done->setMaximumSize(QSize(70, 30));
        pushButton_done->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(pushButton_done, 0, Qt::AlignmentFlag::AlignHCenter);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(CreateTask);

        QMetaObject::connectSlotsByName(CreateTask);
    } // setupUi

    void retranslateUi(QWidget *CreateTask)
    {
        CreateTask->setWindowTitle(QCoreApplication::translate("CreateTask", "CreateTask", nullptr));
        label_name->setText(QCoreApplication::translate("CreateTask", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_dateTime->setText(QCoreApplication::translate("CreateTask", "\320\224\320\260\321\202\320\260", nullptr));
        dateTimeEdit->setDisplayFormat(QCoreApplication::translate("CreateTask", "dd.MM.yyyy HH:mm", nullptr));
        label_description->setText(QCoreApplication::translate("CreateTask", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        pushButton_done->setText(QCoreApplication::translate("CreateTask", "\320\223\320\276\321\202\320\276\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateTask: public Ui_CreateTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETASK_H
