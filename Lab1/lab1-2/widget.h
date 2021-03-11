#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "widget2.h"
#include "widget3.h"
#include "public.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    widget2 win2;
    widget3 win3;
    QLabel *timeLabel;

public slots:
    void timerUpdate(void);
};
#endif // WIDGET_H
