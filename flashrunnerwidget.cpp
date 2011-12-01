#include "flashrunnerwidget.h"

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

void FlashRunnerWidget::setInterface(FtInterface *ftInterface)
{
    _interface = ftInterface;
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











