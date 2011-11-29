#include <QtGui/QApplication>

#include "flashrunnerwidget.h"
#include "ftinterface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FtInterface interface;

    FlashRunnerWidget flashRunnerWidget;
    flashRunnerWidget.setInterface(&interface);
    flashRunnerWidget.show();

    return a.exec();
}
