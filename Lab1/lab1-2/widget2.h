#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>
#include "public.h"

class widget2 : public QWidget
{
    Q_OBJECT
public:
    explicit widget2(QWidget *parent = nullptr);

signals:

private:
    QLabel *timeLabel;
public slots:
    void timerUpdate(void);

};

#endif // WIDGET2_H
