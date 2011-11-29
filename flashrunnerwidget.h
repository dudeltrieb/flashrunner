#ifndef FLASHRUNNERWIDGET_H
#define FLASHRUNNERWIDGET_H

#include <QWidget>
#include <QtGui>
#include "ftinterface.h"

class FlashRunnerWidget : public QWidget
{
    Q_OBJECT

public:
    FlashRunnerWidget(QWidget *parent = 0);
    void setInterface(FtInterface *interface);

public slots:
    void setStatus(const QString& status);
    void messageReceived(const QString& message);

private slots:
    void sendCommand();

private:
    QLabel *_statusLabel;
    QLineEdit *_commandLineEdit;
    QPlainTextEdit *_logTextEdit;
    FtInterface *_interface;
};

#endif // FLASHRUNNERWIDGET_H
