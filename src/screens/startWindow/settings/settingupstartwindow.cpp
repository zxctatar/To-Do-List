#include "src/screens/startWindow/settings/settingupstartwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

SettingUpStartWindow::SettingUpStartWindow(){}

void SettingUpStartWindow::settingUpWidgets(Ui::StartWindow* ui) // настройка виджетов главного окна
{
    QVBoxLayout* layoutTodayV = new QVBoxLayout(ui->scrollAreaWidgetContents_today);
    QVBoxLayout* layoutUpComingV = new QVBoxLayout(ui->scrollAreaWidgetContents_upcoming);
    QVBoxLayout* layoutCompletedV = new QVBoxLayout(ui->scrollAreaWidgetContents_completed);

    layoutTodayV->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    layoutUpComingV->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    layoutCompletedV->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    ui->scrollAreaWidgetContents_today->setLayout(layoutTodayV);
    ui->scrollAreaWidgetContents_upcoming->setLayout(layoutUpComingV);
    ui->scrollAreaWidgetContents_completed->setLayout(layoutCompletedV);

    ui->scrollAreaWidgetContents_today->layout()->setSpacing(10);
    ui->scrollAreaWidgetContents_upcoming->layout()->setSpacing(10);
    ui->scrollAreaWidgetContents_completed->layout()->setSpacing(10);
}
