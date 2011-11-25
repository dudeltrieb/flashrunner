#ifndef COMCLASS_H
#define COMCLASS_H

#include <QtGui>
#include "windows.h"
#include "ftd2xx.h"

class COMClass
{
public:
    COMClass();
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

#endif // COMCLASS_H
