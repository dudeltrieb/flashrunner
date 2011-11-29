#ifndef RUNNERGUI_H
#define RUNNERGUI_H

#include <QWidget>
#include <QtGui>
#include "ftinterface.h"


class RunnerGUI : public QWidget
{
    Q_OBJECT

public:
    RunnerGUI(QWidget *parent = 0);
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


#endif // RUNNERGUI_H
