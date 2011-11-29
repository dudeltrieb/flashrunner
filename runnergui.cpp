#include "runnergui.h"
#ifdef Q_WS_WIN
#include "windows.h"
#endif
#include <ftd2xx.h>
#include "ftinterface.h"


RunnerGUI::RunnerGUI(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("flashrunner");

    _statusLabel = new QLabel("no connection");
    _commandLineEdit = new QLineEdit();
    _logTextEdit = new QPlainTextEdit();
    _logTextEdit->setReadOnly(true);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(_statusLabel);
    layout->addWidget(_commandLineEdit);
    layout->addWidget(_logTextEdit);

    setLayout(layout);

    connect(_commandLineEdit, SIGNAL(returnPressed()), this, SLOT(sendCommand()));
}

void RunnerGUI::setInterface(FtInterface *interface)
{
    _interface = interface;
}

void RunnerGUI::setStatus(const QString &status)
{
    _statusLabel->setText(status);
}

void RunnerGUI::sendCommand()
{
    QString command = _commandLineEdit->text();
    _commandLineEdit->clear();
    _commandLineEdit->setFocus(Qt::OtherFocusReason);

    _interface->send(command);

    _logTextEdit->appendPlainText(command);
}

void RunnerGUI::messageReceived(const QString& message)
{
    _logTextEdit->appendPlainText("Message");
}











