#include <QtGui/QApplication>

#include "flashrunnerwidget.h"
#include "ftinterface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FtInterface ftInterface;
    if (!ftInterface.open(1)) {
        qDebug() << ftInterface.lastError();
        return -1;
    }

    FlashRunnerWidget flashRunnerWidget;
    flashRunnerWidget.setInterface(&ftInterface);
    flashRunnerWidget.show();

    return a.exec();
}
