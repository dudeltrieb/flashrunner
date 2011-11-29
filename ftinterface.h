#ifndef FTINTERFACE_H
#define FTINTERFACE_H

#include <QtGui>
#ifdef Q_WS_WIN
#include "windows.h"    // not sure why if this is required on Windows
#endif
#include <ftd2xx.h>

class FtInterface
{
public:
    FtInterface();

public slots:
    void send(const QString& message);

private:
    FT_HANDLE _ftHandle;
};

#endif // FTINTERFACE_H
