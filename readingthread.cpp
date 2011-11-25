#include "readingthread.h"

void ReadingThread::run()
{
    qDebug() << "hello from worker thread " << thread()->currentThreadId();

    //this->runnerGUI = runnerGUI;

    for (int i=0; i<1000; i++)
    {
      //  runnerGUI.MessageReceived("Hallo");
    }
}
