#ifndef WIDGET3_H
#define WIDGET3_H

#include <QWidget>
#include "public.h"

class widget3 : public QWidget
{
    Q_OBJECT
public:
    explicit widget3(QWidget *parent = nullptr);

signals:

private:
    QLabel *timeLabel;
public slots:
    void timerUpdate(void);
};

#endif // WIDGET3_H
