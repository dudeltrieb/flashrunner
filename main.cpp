#include <QtGui/QApplication>

#include "flashrunnerwidget.h"
#include "ftinterface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FtInterface ftInterface;

    FlashRunnerWidget flashRunnerWidget;
    flashRunnerWidget.setInterface(&ftInterface);
    flashRunnerWidget.show();

    return a.exec();
}
