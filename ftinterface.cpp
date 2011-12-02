#include "ftinterface.h"
#include "ftd2xx.h"

FtInterface::FtInterface(QObject *parent)
    : QObject(parent)
{
    FT_STATUS ftStatus;
    FT_DEVICE ftDevice;
    DWORD deviceID;
    char serialNumber[16];    

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

    startTimer(20);    // fires a timerEvent every 100 milliseconds
}

QString FtInterface::getStatus()
{
    return QString::fromAscii(description);
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

void FtInterface::timerEvent(QTimerEvent * event)
{
    Q_UNUSED(event)

    FT_STATUS ftStatus;

    DWORD EventDWord;
    DWORD RxBytes;
    DWORD TxBytes;
    DWORD BytesReceived;
    char RxBuffer[1024] = "";

    ftStatus = FT_GetStatus(_ftHandle, &RxBytes, &TxBytes, &EventDWord);

    if (RxBytes > 0)
    {
        ftStatus = FT_Read(_ftHandle, RxBuffer, RxBytes, &BytesReceived);

        if (ftStatus == FT_OK)
        {
            QString Messages = QString::fromAscii(RxBuffer);
            messageReceived(Messages);
        }
        else
        {
            qDebug("Error on Reading Messages");
        }
    }
}
