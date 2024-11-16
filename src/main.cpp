#include <QApplication>
#include "src/screens/startWindow/view/startwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    StartWindow* window = new StartWindow();
    window->show();

    return app.exec();
}
