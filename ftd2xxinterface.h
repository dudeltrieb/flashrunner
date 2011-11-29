#ifndef FTD2XXINTERFACE_H
#define FTD2XXINTERFACE_H

#include <QtGui>
#ifdef Q_WS_WIN
#include "windows.h"
#endif
#include <ftd2xx.h>

class Ftd2xxInterface
{
public:
    Ftd2xxInterface();
    FT_HANDLE ftHandle;
    FT_DEVICE ftDevice;
    FT_STATUS ftStatus;

public slots:
    void SendString(QString Message);

private:
    DWORD deviceID;
    char serialNumber[16];
    char description[64];
};

#endif // FTD2XXINTERFACE_H
