#include "mainwindow.h"
#include "ui_mainwindow.h"

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // time show
    timeLabel = new QLabel(this);
    QTimer *timer = new QTimer (this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));

    // hostname and os type... show
    QFile userFile("/proc/sys/kernel/hostname");
    userFile.open(QIODevice::ReadOnly);
    QString *userInfo = new QString(userFile.readAll());
    ui->userLabel->setText(*userInfo);

    QFile osType("/proc/sys/kernel/ostype");
    QFile osRelease("/proc/sys/kernel/osrelease");
    osType.open(QIODevice::ReadOnly);
    osRelease.open(QIODevice::ReadOnly);
    QString *osTypeInfo = new QString(osType.readAll());
    QString *osReleaseInfo = new QString(osRelease.readAll());
    ui->osLabel1->setText(*osTypeInfo);
    ui->osLabel2->setText(*osReleaseInfo);

    userFile.close();
    osType.close();
    osRelease.close();

    cpuUsage = 0;
    ui->cpuUsed->setText(QString::number(cpuUsage));
    QFile cpuFile("/proc/cpuinfo");
    cpuFile.open(QIODevice::ReadOnly);
    QString temp;
    int pos;
    while(1)
    {
        temp = cpuFile.readLine();
        if(pos = temp.indexOf("model name"), pos != -1)
        {
            pos += 12;
            QString *cpuType = new QString(temp.mid(pos, temp.length() - 12));
            ui->cpuNameLabel->setText(*cpuType);
            break;

        }
    }
    pos = 0;
    while(1)
    {
        temp = cpuFile.readLine();
        if(pos = temp.indexOf("cpu MHz"), pos != -1)
        {
            pos += 11;
            QString *cpuMhz = new QString(temp.mid(pos, temp.length() - 11));
            ui->cpuMhz->setText(*cpuMhz);
            break;
        }
    }
    pos = 0;
    while(1)
    {
        temp = cpuFile.readLine();
        if(pos = temp.indexOf("cache size"), pos != -1)
        {
            pos += 12;
            QString *cpuCacheSize = new QString(temp.mid(pos, temp.length() - 12));
            ui->cpuCacheSizeLabel->setText(*cpuCacheSize);
            break;
        }
    }

    cpuFile.close();
    connect(timer, SIGNAL(timeout()), this, SLOT(cpuUpdate()));

    struct sysinfo info;
    time_t cur_time=0;
    time_t boot_time=0;
    struct tm *ptm=nullptr;
    if(sysinfo(&info)) return;
    time(&cur_time);
    boot_time=cur_time-info.uptime;
    ptm=localtime(&boot_time);
    char boottime_buf[30];
    sprintf(boottime_buf,"%d.%d.%d %02d:%02d:%02d",ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday,
                    ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
    ui->startTimeLabel->setText(QString(boottime_buf));




    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerUpdate(void)
{
    timeLabel->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    ui->statusbar->addWidget(timeLabel);
    struct sysinfo info;
    sysinfo(&info);
    struct tm *ptm=nullptr;
    ptm=gmtime(&info.uptime);
    char time_buf[30];
    sprintf(time_buf,"%02d:%02d:%02d",ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
    ui->runningTimeLabel->setText(QString(time_buf));

    // mem
    QFile memFile("/proc/meminfo");
    memFile.open(QIODevice::ReadOnly);
    QString memT, memF, memA;
    memT = memFile.readLine();
    memT.remove(QRegExp("[A-Za-z]"));
    memT.replace(":", "");
    memT.replace(" ", "");
    ui->memTotalLabel->setText(memT+"kB");
    memTotal = memT.toLong();
    // qDebug() << memTotal;
    memF = memFile.readLine();
    memF.remove(QRegExp("[A-Za-z]"));
    memF.replace(":", "");
    memF.replace(" ", "");
    ui->memFreeLabel->setText(memF+"kB");
    memFree = memF.toLong();
    // qDebug() << memFree;

    memA = memFile.readLine();
    memA.remove(QRegExp("[A-Za-z]"));
    memA.replace(":", "");
    memA.replace(" ", "");
    ui->memAvailableLabel->setText(memA + "kB");
    memAvailable = memA.toLong();
    // qDebug() << memAvailable;

    memUsage = 100.0 * (memTotal - memAvailable) / memTotal;
    // qDebug()<<memUsage;
    ui->memUsageLabel->setText(QString::number(memUsage)+"%");
    ui->memProgressBar->setFormat(QString::number(memUsage)+"%");

//    memLine = new QLineSeries(ui->mem_tab);
//    memChart = new QChart();
//    memChartView = new QChartView(ui->mem_tab);
//    memLine->append(flag, memUsage);
//    flag++;
//    memChart->addSeries(memLine);
//    memChart->createDefaultAxes();

}


void MainWindow::cpuUpdate(void)
{
    QProcess process;
    process.start("cat /proc/stat");
    process.waitForFinished();
    QString str = process.readLine();
    str.replace("\n", "");
    str.replace(QRegExp("(){1,}"), " ");
    auto lst = str.split(" ");
    if(lst.size() > 3)
    {
        double use = lst[1].toDouble() + lst[2].toDouble() + lst[3].toDouble();
        double total = 0;
        for(int i = 1; i < lst.size(); ++i)
            total += lst[i].toDouble();
        if(total - cpuTotal > 0)
        {
            cpuUsage = (use - cpuUsed) / (total - cpuTotal) * 100.0;
            ui->cpuUsed->setText(QString::number(cpuUsage));
            cpuTotal = total;
            cpuUsed = use;
        }
    }
}

void MainWindow::on_powerOffButton_clicked()
{
    system("shutdown -h");
}
