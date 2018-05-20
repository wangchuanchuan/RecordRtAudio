#include "Recording.h"
#include "ui_Recording.h"

Recording::Recording(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recording)
{
    ui->setupUi(this);
}

Recording::~Recording()
{
    delete ui;
}

//左声道
void Recording::on_btnLeftChannel_clicked()
{
    if (Thread.isRunning())
        Thread.exit(0);
    Thread.flag = true;
    Thread.num = 0;
    Thread.start();
}

//右声道
void Recording::on_btnRightChannel_clicked()
{
    if (Thread.isRunning())
            Thread.exit(0);
        Thread.flag = true;
        Thread.num = 1;
        Thread.start();
}

//单声道
void Recording::on_btnSingleChannel_clicked()
{
    if (Thread.isRunning())
            Thread.exit(0);
        Thread.flag = true;
        Thread.num = 2;
        Thread.start();
}

//停止
void Recording::on_btnStop_clicked()
{
    Thread.flag = false;
    if (Thread.isRunning())
    {
        Thread.exit(0);
        qDebug() << "The end.";
    }
}
