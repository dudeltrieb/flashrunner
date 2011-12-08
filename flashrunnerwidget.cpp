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

<<<<<<< HEAD
    _statusLabel->setText(_interface->description());
=======
    _statusLabel->setText(_interface->getStatus());
>>>>>>> 37b1c7b8b0ba58bf5fea5abda9070042a1dd556d
}

void FlashRunnerWidget::sendCommand()
{
    QString command = _commandLineEdit->text();
    _commandLineEdit->clear();

    // required because we use insertPlainText() below instead of appendPlainText()
    // which also inserts line feeds we don´t want
    _logTextEdit->moveCursor(QTextCursor::End);

    if (!_interface->send(command)) {
        _logTextEdit->insertPlainText("Couldn´t send command: " + _interface->lastError());
    }

    if (command.length() > 0)
<<<<<<< HEAD
        _logTextEdit->insertPlainText(command);
=======
        _logTextEdit->appendPlainText(command);
>>>>>>> 37b1c7b8b0ba58bf5fea5abda9070042a1dd556d
}

void FlashRunnerWidget::messageReceived(const QString& message)
{
    _logTextEdit->appendPlainText(message);
}











