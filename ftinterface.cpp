#include "ftinterface.h"
#include "ftd2xx.h"

FtInterface::FtInterface(QObject *parent)
    : QObject(parent),
      _ftHandle(0),
      _receiverTimerId(-1)
{
}

FtInterface::~FtInterface()
{
    close();
}

bool FtInterface::open(int channel)
{
    FT_STATUS ftStatus;
    FT_DEVICE ftDevice;
    DWORD deviceID;
    char serialNumber[16];    

    if (isOpen()) {
        close();
    }

    ftStatus = FT_Open(channel, &_ftHandle);
    if(ftStatus != FT_OK) {
        _lastError = "Could not open channel.";
        return false;
    }

    ftStatus = FT_GetDeviceInfo( _ftHandle,
                                 &ftDevice,
                                 &deviceID,
                                 serialNumber,
                                 description,
                                 NULL );

    if (ftStatus != FT_OK) {
        _lastError = "Could not get device info.";
        return false;
    }

    _description = QString::fromAscii(description);

    ftStatus = FT_SetBaudRate(_ftHandle, 115200);
    if (ftStatus != FT_OK) {
        _lastError = "Could not set baud rate.";
        return false;
    }

    ftStatus = FT_SetDataCharacteristics(_ftHandle, 8, 1, 0);
    if (ftStatus != FT_OK) {
        _lastError = "Could not set data characteristics.";
        return false;
    }

    ftStatus = FT_SetTimeouts(_ftHandle, 5000, 0);
    if (ftStatus != FT_OK) {
        _lastError = "Could not set timeouts.";
        return false;
    }

    _receiverTimerId = startTimer(0);    // fires a timerEvent every 100 milliseconds

    return isOpen();
}

bool FtInterface::isOpen() const
{
    return (_ftHandle != 0);
}

bool FtInterface::close()
{
    FT_STATUS ftStatus = FT_OK;
    if (isOpen()) {
        if (_receiverTimerId != -1) {
            killTimer(_receiverTimerId);
            _receiverTimerId = -1;
        }
        ftStatus = FT_Close(_ftHandle);
        _ftHandle = 0;
    }
    return (ftStatus == FT_OK);
}

QString FtInterface::description() const
{
    return _description;
}

QString FtInterface::lastError() const
{
    return _lastError;
}

bool FtInterface::send(const QString& message)
{
    FT_STATUS ftStatus;

    const QChar carriageReturn('\r');
    QString messageWithCarriageReturn(message + carriageReturn);

    DWORD numBytesWritten;
    ftStatus = FT_Write(_ftHandle,
                    messageWithCarriageReturn.toAscii().data(),
                    messageWithCarriageReturn.toAscii().length(),
                    &numBytesWritten);

    if (ftStatus != FT_OK) {
        _lastError = "Could not send.";
    }

    return (ftStatus == FT_OK);
}

void FtInterface::timerEvent(QTimerEvent * event)
{
    Q_UNUSED(event)

    FT_STATUS ftStatus;

    DWORD ftEvent;
    DWORD numBytesReceived;
    DWORD numBytesToSend;

    ftStatus = FT_GetStatus(_ftHandle, &numBytesReceived, &numBytesToSend, &ftEvent);

    if ((ftStatus == FT_OK) && (numBytesReceived > 0))
    {
        DWORD numBytesRead;
        char buffer[numBytesReceived];

        ftStatus = FT_Read(_ftHandle, buffer, numBytesReceived, &numBytesRead);

        if (ftStatus == FT_OK) {
            messageReceived(QString::fromLatin1(buffer, numBytesRead));
        } else {
            qDebug("Error on Reading Messages");
        }
    }
}
