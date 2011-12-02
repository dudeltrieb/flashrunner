#ifndef FLASHRUNNERWIDGET_H
#define FLASHRUNNERWIDGET_H

#include <QWidget>
#include <QtGui>

class FtInterface;

class FlashRunnerWidget : public QWidget
{
    Q_OBJECT

public:
    FlashRunnerWidget(QWidget *parent = 0);
    void setInterface(FtInterface *ftInterface);

public slots:
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
