#include "ftd2xxinterface.h"

Ftd2xxInterface::Ftd2xxInterface()
{
    ftStatus = FT_Open(1, &ftHandle);
    if(ftStatus != FT_OK) { // FT_Open failed
        return;
    }
    ftStatus = FT_GetDeviceInfo( ftHandle,
                                 &ftDevice,
                                 &deviceID,
                                 serialNumber,
                                 description,
                                 NULL );

    ftStatus = FT_SetBaudRate(ftHandle, 115200);
    ftStatus = FT_SetDataCharacteristics(ftHandle, 8, 1, 0);
    ftStatus = FT_SetTimeouts(ftHandle, 5000, 0);

    qDebug() << "hello from GUI thread " << description;

}

void Ftd2xxInterface::SendString(QString Message)
{
    char neu[1024] = "";
    strcpy(neu, (Message+ "\r").toAscii().data());

    DWORD Out;
    ftStatus = FT_Write(ftHandle, neu, strlen(neu), &Out);
}
