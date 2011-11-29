#include "runnergui.h"
#ifdef Q_WS_WIN
#include "windows.h"
#endif
#include <ftd2xx.h>
#include "ftinterface.h"


RunnerGUI::RunnerGUI(QWidget *parent) : QWidget(parent)
{
    COMName = new QLabel("no connection");
    COMLine = new QLineEdit();
    COMBox = new QPlainTextEdit();
    COMBox->setReadOnly(true);

    connect(COMLine, SIGNAL(returnPressed()), this, SLOT(MessageEntered()));

    QGridLayout *layout1 = new QGridLayout;
    layout1->addWidget(COMName);
    layout1->addWidget(COMLine);
    layout1->addWidget(COMBox);

    setLayout(layout1);
    setWindowTitle("flashrunner");
}

void RunnerGUI::Init(FtInterface *comClass)
{
    this->comClass = comClass;
}

void RunnerGUI::SetDescription(QString Desc)
{
    COMName->setText(Desc);
}

void RunnerGUI::MessageEntered()
{
    QString Message = COMLine->text();
    COMLine->clear();
    COMLine->setFocus(Qt::OtherFocusReason);

    comClass->send(Message);

    COMBox->appendPlainText(Message);

}

void RunnerGUI::MessageReceived(QString Message)
{
    COMBox->appendPlainText("Message");
}











