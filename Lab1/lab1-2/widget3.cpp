#include "widget3.h"

widget3::widget3(QWidget *parent) : QWidget(parent)
{
    timeLabel = new QLabel(this);
    timeLabel->setGeometry(0, 0, 150, 30);

    this->setWindowTitle("window3");
    this->resize(winWidth, winHight);
    this->move(1000, 100);

    QTimer *timer = new QTimer (this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);
    timeLabel->show();

}


void widget3::timerUpdate(void)
{
    timeLabel->setText(QDateTime::currentDateTime().toString("ss"));
}
