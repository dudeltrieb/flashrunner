#ifndef FTINTERFACE_H
#define FTINTERFACE_H

#include <QtCore/QObject>

#ifdef Q_WS_WIN
#include <windows.h>    // not sure why if this is required on Windows
#endif
#include "ftd2xx.h"

class FtInterface : public QObject
{
    Q_OBJECT

public:
    FtInterface(QObject *parent = 0);
    virtual ~FtInterface();
    bool open(int channel);
    bool isOpen() const;
    bool close();
    QString description() const;
    QString lastError() const;

    bool send(const QString& message);

signals:
    void messageReceived(const QString& message);

protected:
    void timerEvent(QTimerEvent *);

private:
    FT_HANDLE _ftHandle;
    QString _description;
    int _receiverTimerId;
    QString _lastError;
};

#endif // FTINTERFACE_H
