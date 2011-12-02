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
    QString getStatus();

signals:
    void messageReceived(const QString& message);

public slots:
    void send(const QString& message);

protected:
    void timerEvent(QTimerEvent *);

private:
    FT_HANDLE _ftHandle;
    char description[64];
};

#endif // FTINTERFACE_H
