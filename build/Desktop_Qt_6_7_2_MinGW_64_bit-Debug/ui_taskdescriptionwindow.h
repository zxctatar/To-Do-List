/********************************************************************************
** Form generated from reading UI file 'taskdescriptionwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKDESCRIPTIONWINDOW_H
#define UI_TASKDESCRIPTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskDescriptionWindow
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_dateTime;
    QLineEdit *lineEdit_date;
    QLabel *label_description;
    QTextBrowser *textBrowser_description;
    QFormLayout *formLayout;
    QPushButton *pushButton_done;
    QPushButton *pushButton_delete;

    void setupUi(QWidget *TaskDescriptionWindow)
    {
        if (TaskDescriptionWindow->objectName().isEmpty())
            TaskDescriptionWindow->setObjectName("TaskDescriptionWindow");
        TaskDescriptionWindow->resize(420, 480);
        TaskDescriptionWindow->setMinimumSize(QSize(320, 320));
        TaskDescriptionWindow->setMaximumSize(QSize(420, 480));
        verticalLayout = new QVBoxLayout(TaskDescriptionWindow);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_name = new QLabel(TaskDescriptionWindow);
        label_name->setObjectName("label_name");
        QFont font;
        font.setPointSize(12);
        label_name->setFont(font);
        label_name->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(label_name);

        lineEdit_name = new QLineEdit(TaskDescriptionWindow);
        lineEdit_name->setObjectName("lineEdit_name");
        QFont font1;
        font1.setPointSize(10);
        lineEdit_name->setFont(font1);
        lineEdit_name->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_name->setMaxLength(50);
        lineEdit_name->setReadOnly(true);

        verticalLayout_2->addWidget(lineEdit_name);

        label_dateTime = new QLabel(TaskDescriptionWindow);
        label_dateTime->setObjectName("label_dateTime");
        label_dateTime->setFont(font);
        label_dateTime->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(label_dateTime);

        lineEdit_date = new QLineEdit(TaskDescriptionWindow);
        lineEdit_date->setObjectName("lineEdit_date");
        lineEdit_date->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lineEdit_date->setReadOnly(true);

        verticalLayout_2->addWidget(lineEdit_date);

        label_description = new QLabel(TaskDescriptionWindow);
        label_description->setObjectName("label_description");
        label_description->setFont(font);
        label_description->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(label_description);

        textBrowser_description = new QTextBrowser(TaskDescriptionWindow);
        textBrowser_description->setObjectName("textBrowser_description");
        textBrowser_description->setFont(font1);
        textBrowser_description->setMouseTracking(true);
        textBrowser_description->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        textBrowser_description->setTabChangesFocus(false);
        textBrowser_description->setReadOnly(true);

        verticalLayout_2->addWidget(textBrowser_description);


        verticalLayout->addLayout(verticalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setFormAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        pushButton_done = new QPushButton(TaskDescriptionWindow);
        pushButton_done->setObjectName("pushButton_done");
        pushButton_done->setMinimumSize(QSize(70, 30));
        pushButton_done->setMaximumSize(QSize(70, 30));

        formLayout->setWidget(0, QFormLayout::LabelRole, pushButton_done);

        pushButton_delete = new QPushButton(TaskDescriptionWindow);
        pushButton_delete->setObjectName("pushButton_delete");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_delete->sizePolicy().hasHeightForWidth());
        pushButton_delete->setSizePolicy(sizePolicy);
        pushButton_delete->setMinimumSize(QSize(70, 30));
        pushButton_delete->setMaximumSize(QSize(70, 30));
        pushButton_delete->setAutoDefault(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, pushButton_delete);


        verticalLayout->addLayout(formLayout);


        retranslateUi(TaskDescriptionWindow);

        QMetaObject::connectSlotsByName(TaskDescriptionWindow);
    } // setupUi

    void retranslateUi(QWidget *TaskDescriptionWindow)
    {
        TaskDescriptionWindow->setWindowTitle(QCoreApplication::translate("TaskDescriptionWindow", "TaskDescriptionWindow", nullptr));
        label_name->setText(QCoreApplication::translate("TaskDescriptionWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_dateTime->setText(QCoreApplication::translate("TaskDescriptionWindow", "\320\224\320\260\321\202\320\260", nullptr));
        label_description->setText(QCoreApplication::translate("TaskDescriptionWindow", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        pushButton_done->setText(QCoreApplication::translate("TaskDescriptionWindow", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("TaskDescriptionWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskDescriptionWindow: public Ui_TaskDescriptionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKDESCRIPTIONWINDOW_H
