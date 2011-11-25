#ifndef READINGTHREAD_H
#define READINGTHREAD_H

#include <QThread>
#include "runnergui.h"

class ReadingThread : public QThread
{
    Q_OBJECT

private:
    void run();
};

#endif // READINGTHREAD_H

