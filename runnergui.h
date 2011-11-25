#ifndef RUNNERGUI_H
#define RUNNERGUI_H

#include <QWidget>
#include <QtGui>
#include "comclass.h"


class RunnerGUI : public QWidget
{
    Q_OBJECT

public:
    RunnerGUI(QWidget *parent = 0);
    void Init(COMClass *comClass);


public slots:
    void MessageEntered();
    void MessageReceived(QString Message);
    void SetDescription(QString Desc);

private:
    QLabel *COMName;
    QLineEdit *COMLine;
    QPlainTextEdit *COMBox;
    COMClass *comClass;

};


#endif // RUNNERGUI_H
