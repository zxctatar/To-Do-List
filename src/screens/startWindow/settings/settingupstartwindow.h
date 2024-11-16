#ifndef SETTINGUPSTARTWINDOW_H
#define SETTINGUPSTARTWINDOW_H

#include "src/screens/startWindow/view/startwindow.h"

class SettingUpStartWindow
{
public:
    explicit SettingUpStartWindow();

    void settingUpWidgets(Ui::StartWindow* ui); // настройка виджетов главного окна
};

#endif // SETTINGUPSTARTWINDOW_H
