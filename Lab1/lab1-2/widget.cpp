#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timeLabel = new QLabel(this);
    timeLabel->setGeometry(0, 0, 150, 30);
    this->setWindowTitle("window1");
    this->resize(winWidth, winHight);
    this->move(200, 100);

    QTimer *timer = new QTimer (this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);
    timeLabel->show();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerUpdate(void)
{
    timeLabel->setText(QDateTime::currentDateTime().toString("hh"));
}
