#include "flashrunnerwidget.h"
#ifdef Q_WS_WIN
#include "windows.h"
#endif
#include <ftd2xx.h>
#include "ftinterface.h"


FlashRunnerWidget::FlashRunnerWidget(QWidget *parent) : QWidget(parent)
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

void FlashRunnerWidget::setInterface(FtInterface *interface)
{
    _interface = interface;
}

void FlashRunnerWidget::setStatus(const QString &status)
{
    _statusLabel->setText(status);
}

void FlashRunnerWidget::sendCommand()
{
    QString command = _commandLineEdit->text();
    _commandLineEdit->clear();
    _commandLineEdit->setFocus(Qt::OtherFocusReason);

    _interface->send(command);

    _logTextEdit->appendPlainText(command);
}

void FlashRunnerWidget::messageReceived(const QString& message)
{
    _logTextEdit->appendPlainText("Message");
}











