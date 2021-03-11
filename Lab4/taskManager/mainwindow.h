#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QDateTime>
#include <QLabel>
#include <QString>
#include <QTimer>
#include <QFile>
#include <QIODevice>
#include <QProcess>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <QDebug>
#include <QChart>
#include <QChartView>
#include <QLineSeries>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_CHARTS_USE_NAMESPACE
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel *timeLabel;
    float cpuUsage;
    double cpuTotal;
    double cpuUsed;

    long int memTotal;
    float memUsage;
    long int memFree;
    long int memAvailable;

//    QLineSeries *memLine;
//    QChart *memChart;
//    QChartView *memChartView;
//    int flag;

public slots:
    void timerUpdate(void);
    void cpuUpdate(void);

private slots:
    void on_powerOffButton_clicked();
};
#endif // MAINWINDOW_H
