#include "widget2.h"

widget2::widget2(QWidget *parent) : QWidget(parent)
{
    timeLabel = new QLabel(this);
    timeLabel->setGeometry(0, 0, 150, 30);

    this->setWindowTitle("window2");
    this->resize(winWidth, winHight);
    this->move(600, 100);

    QTimer *timer = new QTimer (this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);
    timeLabel->show();
}

void widget2::timerUpdate(void)
{
    timeLabel->setText(QDateTime::currentDateTime().toString("mm"));
}
