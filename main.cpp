#include <QtGui/QApplication>

#include "runnergui.h"
#include "readingthread.h"
#include "ftd2xxinterface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Ftd2xxInterface comClass;

    RunnerGUI runnerGUI;
    runnerGUI.Init(&comClass);
    runnerGUI.show();

    ReadingThread readingThread;
    readingThread.start();
    qDebug() << "hello from GUI thread " << a.thread()->currentThreadId();

    return a.exec();
}
