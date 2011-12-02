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

    setMinimumSize(500, 800);

    setLayout(layout);


    connect(_commandLineEdit, SIGNAL(returnPressed()), this, SLOT(sendCommand()));

}

void FlashRunnerWidget::setInterface(FtInterface *ftInterface)
{
    _interface = ftInterface;
    connect(_interface, SIGNAL(messageReceived(QString)), this, SLOT(messageReceived(QString)));

    _statusLabel->setText(_interface->getStatus());
}

void FlashRunnerWidget::sendCommand()
{
    QString command = _commandLineEdit->text();
    _commandLineEdit->clear();
    _commandLineEdit->setFocus(Qt::OtherFocusReason);

    _interface->send(command);

    if (command.length() > 0)
        _logTextEdit->appendPlainText(command);
}

void FlashRunnerWidget::messageReceived(const QString& message)
{
    _logTextEdit->appendPlainText(message);
}











