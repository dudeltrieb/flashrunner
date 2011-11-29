#include "ftinterface.h"

FtInterface::FtInterface()
{
    FT_STATUS ftStatus;
    FT_DEVICE ftDevice;
    DWORD deviceID;
    char serialNumber[16];
    char description[64];

    ftStatus = FT_Open(1, &_ftHandle);
    if(ftStatus != FT_OK) { // FT_Open failed
        return;
    }
    ftStatus = FT_GetDeviceInfo( _ftHandle,
                                 &ftDevice,
                                 &deviceID,
                                 serialNumber,
                                 description,
                                 NULL );

    ftStatus = FT_SetBaudRate(_ftHandle, 115200);
    ftStatus = FT_SetDataCharacteristics(_ftHandle, 8, 1, 0);
    ftStatus = FT_SetTimeouts(_ftHandle, 5000, 0);

    qDebug() << "hello from GUI thread " << description;

}

void FtInterface::send(const QString& message)
{
    FT_STATUS ftStatus;

    const QChar carriageReturn('\r');
    QString messageWithCarriageReturn(message + carriageReturn);

    DWORD numBytesWritten;
    ftStatus = FT_Write(_ftHandle,
                    messageWithCarriageReturn.toAscii().data(),
                    messageWithCarriageReturn.toAscii().length(),
                    &numBytesWritten);
}
