/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_createTask;
    QTabWidget *tabWidget;
    QWidget *tab_today;
    QGridLayout *gridLayout_5;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_today;
    QWidget *tab_upcoming;
    QGridLayout *gridLayout_4;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_upcoming;
    QWidget *tab_completed;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_completed;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName("StartWindow");
        StartWindow->resize(800, 600);
        StartWindow->setMinimumSize(QSize(800, 600));
        StartWindow->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"        background: rgb(255,255,255)\n"
"}"));
        centralwidget = new QWidget(StartWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        pushButton_createTask = new QPushButton(centralwidget);
        pushButton_createTask->setObjectName("pushButton_createTask");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_createTask->sizePolicy().hasHeightForWidth());
        pushButton_createTask->setSizePolicy(sizePolicy);
        pushButton_createTask->setMinimumSize(QSize(75, 75));
        pushButton_createTask->setMaximumSize(QSize(75, 75));
        pushButton_createTask->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        pushButton_createTask->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"        color: rgb(255, 255, 255);\n"
"        background-color: #008c43;\n"
"        border: 1px solid #ccc;\n"
"        border-radius: 15px;\n"
"}\n"
"\n"
"QPushButton::hover\n"
"{\n"
"        background: #99d1b4;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/kisspng-computer-icons-plus-and-minus-signs-clip-art-5b1e62a4baa424.2731478915287179887645 (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_createTask->setIcon(icon);
        pushButton_createTask->setIconSize(QSize(90, 90));

        gridLayout->addWidget(pushButton_createTask, 1, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8(" QTabWidget::pane {\n"
"     border-top: 2px solid #C2C7CB;\n"
" }\n"
"\n"
" QTabWidget::tab-bar {\n"
"     left: 5px;\n"
" }\n"
""));
        tab_today = new QWidget();
        tab_today->setObjectName("tab_today");
        tab_today->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        gridLayout_5 = new QGridLayout(tab_today);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(tab_today);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setStyleSheet(QString::fromUtf8("     border: 2px solid rgb(255,255,255);\n"
"         background: rgb(245,247,249);"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_today = new QWidget();
        scrollAreaWidgetContents_today->setObjectName("scrollAreaWidgetContents_today");
        scrollAreaWidgetContents_today->setGeometry(QRect(0, 0, 778, 467));
        scrollArea_2->setWidget(scrollAreaWidgetContents_today);

        gridLayout_5->addWidget(scrollArea_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_today, QString());
        tab_upcoming = new QWidget();
        tab_upcoming->setObjectName("tab_upcoming");
        gridLayout_4 = new QGridLayout(tab_upcoming);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        scrollArea_3 = new QScrollArea(tab_upcoming);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setStyleSheet(QString::fromUtf8("     border: 2px solid rgb(255,255,255);\n"
"         background: rgb(245,247,249);"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_upcoming = new QWidget();
        scrollAreaWidgetContents_upcoming->setObjectName("scrollAreaWidgetContents_upcoming");
        scrollAreaWidgetContents_upcoming->setGeometry(QRect(0, 0, 778, 467));
        scrollArea_3->setWidget(scrollAreaWidgetContents_upcoming);

        gridLayout_4->addWidget(scrollArea_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_upcoming, QString());
        tab_completed = new QWidget();
        tab_completed->setObjectName("tab_completed");
        gridLayout_3 = new QGridLayout(tab_completed);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(tab_completed);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8("     border: 2px solid rgb(255,255,255);\n"
"         background: rgb(245,247,249);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_completed = new QWidget();
        scrollAreaWidgetContents_completed->setObjectName("scrollAreaWidgetContents_completed");
        scrollAreaWidgetContents_completed->setGeometry(QRect(0, 0, 778, 467));
        scrollAreaWidgetContents_completed->setStyleSheet(QString::fromUtf8("     border: 2px solid rgb(255,255,255);\n"
"         background: rgb(245,247,249);"));
        scrollArea->setWidget(scrollAreaWidgetContents_completed);

        gridLayout_3->addWidget(scrollArea, 0, 0, 1, 1);

        tabWidget->addTab(tab_completed, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        StartWindow->setCentralWidget(centralwidget);

        retranslateUi(StartWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "StartWindow", nullptr));
        pushButton_createTask->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_today), QCoreApplication::translate("StartWindow", "\320\241\320\265\320\263\320\276\320\264\320\275\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_upcoming), QCoreApplication::translate("StartWindow", "\320\237\321\200\320\265\320\264\321\201\321\202\320\276\321\217\321\211\320\270\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_completed), QCoreApplication::translate("StartWindow", "\320\227\320\260\320\262\320\265\321\200\321\210\321\221\320\275\320\275\321\213\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
