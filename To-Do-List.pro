QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/manager/filemanager.cpp \
    src/manager/threadmanager.cpp \
    src/screens/createTaskWindow/controller/addtaskcontroller.cpp \
    src/screens/createTaskWindow/view/createtask.cpp \
    src/screens/startWindow/controller/checktimecontroller.cpp \
    src/screens/startWindow/controller/taskloadercontroller.cpp \
    src/screens/startWindow/settings/settingupstartwindow.cpp \
    src/screens/startWindow/view/startwindow.cpp \
    src/screens/startWindow/widgets/TaskWidget/model/tasklistmodel.cpp \
    src/screens/startWindow/widgets/TaskWidget/view/task.cpp \
    src/screens/taskDescriptionWindow/manager/taskmanagmentmanager.cpp \
    src/screens/taskDescriptionWindow/view/taskdescriptionwindow.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    src/screens/createTaskWindow/view/createtask.ui \
    src/screens/startWindow/view/startwindow.ui \
    src/screens/startWindow/widgets/TaskWidget/view/task.ui \
    src/screens/taskDescriptionWindow/view/taskdescriptionwindow.ui

HEADERS += \
    src/manager/filemanager.h \
    src/manager/threadmanager.h \
    src/screens/createTaskWindow/controller/addtaskcontroller.h \
    src/screens/createTaskWindow/view/createtask.h \
    src/screens/startWindow/controller/checktimecontroller.h \
    src/screens/startWindow/controller/taskloadercontroller.h \
    src/screens/startWindow/settings/settingupstartwindow.h \
    src/screens/startWindow/view/startwindow.h \
    src/screens/startWindow/widgets/TaskWidget/model/tasklistmodel.h \
    src/screens/startWindow/widgets/TaskWidget/view/task.h \
    src/screens/taskDescriptionWindow/manager/taskmanagmentmanager.h \
    src/screens/taskDescriptionWindow/view/taskdescriptionwindow.h
