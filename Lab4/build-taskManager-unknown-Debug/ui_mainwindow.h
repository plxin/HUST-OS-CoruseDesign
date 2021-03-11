/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *user_tab;
    QLabel *osLabel1;
    QLabel *osLabel2;
    QLabel *label_3;
    QLabel *label;
    QLabel *userLabel;
    QLabel *label_2;
    QPushButton *powerOffButton;
    QLabel *label_7;
    QLabel *startTimeLabel;
    QLabel *label_10;
    QLabel *runningTimeLabel;
    QWidget *process_tab;
    QWidget *cpu_tab;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLabel *cpuNameLabel;
    QLabel *label_6;
    QLabel *cpuMhz;
    QLabel *label_5;
    QLabel *cpuCacheSizeLabel;
    QLabel *label_8;
    QLabel *cpuUsed;
    QGraphicsView *graphicsView;
    QProgressBar *progressBar;
    QWidget *mem_tab;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *memTotalLabel;
    QLabel *memFreeLabel;
    QLabel *memUsageLabel;
    QLabel *label_13;
    QLabel *memAvailableLabel;
    QProgressBar *memProgressBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 424);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        user_tab = new QWidget();
        user_tab->setObjectName(QString::fromUtf8("user_tab"));
        osLabel1 = new QLabel(user_tab);
        osLabel1->setObjectName(QString::fromUtf8("osLabel1"));
        osLabel1->setGeometry(QRect(103, 33, 171, 17));
        osLabel2 = new QLabel(user_tab);
        osLabel2->setObjectName(QString::fromUtf8("osLabel2"));
        osLabel2->setGeometry(QRect(103, 56, 181, 17));
        osLabel2->setScaledContents(true);
        label_3 = new QLabel(user_tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(9, 56, 78, 17));
        label = new QLabel(user_tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 9, 74, 17));
        userLabel = new QLabel(user_tab);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));
        userLabel->setGeometry(QRect(103, 9, 171, 17));
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        userLabel->setFont(font);
        label_2 = new QLabel(user_tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(9, 33, 67, 17));
        powerOffButton = new QPushButton(user_tab);
        powerOffButton->setObjectName(QString::fromUtf8("powerOffButton"));
        powerOffButton->setGeometry(QRect(470, 320, 89, 25));
        label_7 = new QLabel(user_tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 80, 81, 17));
        startTimeLabel = new QLabel(user_tab);
        startTimeLabel->setObjectName(QString::fromUtf8("startTimeLabel"));
        startTimeLabel->setGeometry(QRect(100, 80, 221, 17));
        label_10 = new QLabel(user_tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 100, 121, 17));
        runningTimeLabel = new QLabel(user_tab);
        runningTimeLabel->setObjectName(QString::fromUtf8("runningTimeLabel"));
        runningTimeLabel->setGeometry(QRect(120, 100, 211, 17));
        tabWidget->addTab(user_tab, QString());
        process_tab = new QWidget();
        process_tab->setObjectName(QString::fromUtf8("process_tab"));
        tabWidget->addTab(process_tab, QString());
        cpu_tab = new QWidget();
        cpu_tab->setObjectName(QString::fromUtf8("cpu_tab"));
        formLayout = new QFormLayout(cpu_tab);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_4 = new QLabel(cpu_tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        cpuNameLabel = new QLabel(cpu_tab);
        cpuNameLabel->setObjectName(QString::fromUtf8("cpuNameLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cpuNameLabel);

        label_6 = new QLabel(cpu_tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        cpuMhz = new QLabel(cpu_tab);
        cpuMhz->setObjectName(QString::fromUtf8("cpuMhz"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cpuMhz);

        label_5 = new QLabel(cpu_tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        cpuCacheSizeLabel = new QLabel(cpu_tab);
        cpuCacheSizeLabel->setObjectName(QString::fromUtf8("cpuCacheSizeLabel"));

        formLayout->setWidget(2, QFormLayout::FieldRole, cpuCacheSizeLabel);

        label_8 = new QLabel(cpu_tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_8);

        cpuUsed = new QLabel(cpu_tab);
        cpuUsed->setObjectName(QString::fromUtf8("cpuUsed"));

        formLayout->setWidget(3, QFormLayout::FieldRole, cpuUsed);

        graphicsView = new QGraphicsView(cpu_tab);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        formLayout->setWidget(5, QFormLayout::SpanningRole, graphicsView);

        progressBar = new QProgressBar(cpu_tab);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        formLayout->setWidget(4, QFormLayout::SpanningRole, progressBar);

        tabWidget->addTab(cpu_tab, QString());
        mem_tab = new QWidget();
        mem_tab->setObjectName(QString::fromUtf8("mem_tab"));
        label_9 = new QLabel(mem_tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 10, 91, 17));
        label_11 = new QLabel(mem_tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 30, 91, 17));
        label_12 = new QLabel(mem_tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 70, 91, 17));
        memTotalLabel = new QLabel(mem_tab);
        memTotalLabel->setObjectName(QString::fromUtf8("memTotalLabel"));
        memTotalLabel->setGeometry(QRect(110, 10, 161, 17));
        memFreeLabel = new QLabel(mem_tab);
        memFreeLabel->setObjectName(QString::fromUtf8("memFreeLabel"));
        memFreeLabel->setGeometry(QRect(110, 30, 161, 17));
        memUsageLabel = new QLabel(mem_tab);
        memUsageLabel->setObjectName(QString::fromUtf8("memUsageLabel"));
        memUsageLabel->setGeometry(QRect(110, 70, 161, 17));
        label_13 = new QLabel(mem_tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 50, 111, 17));
        memAvailableLabel = new QLabel(mem_tab);
        memAvailableLabel->setObjectName(QString::fromUtf8("memAvailableLabel"));
        memAvailableLabel->setGeometry(QRect(130, 50, 67, 17));
        memProgressBar = new QProgressBar(mem_tab);
        memProgressBar->setObjectName(QString::fromUtf8("memProgressBar"));
        memProgressBar->setGeometry(QRect(20, 90, 541, 23));
        memProgressBar->setValue(24);
        tabWidget->addTab(mem_tab, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        osLabel1->setText(QCoreApplication::translate("MainWindow", "ostypes", nullptr));
        osLabel2->setText(QCoreApplication::translate("MainWindow", "version", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "OS Version:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Hostname:", nullptr));
        userLabel->setText(QCoreApplication::translate("MainWindow", "hostname", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "OS Types:", nullptr));
        powerOffButton->setText(QCoreApplication::translate("MainWindow", "Power Off", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Start time:", nullptr));
        startTimeLabel->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Running time:", nullptr));
        runningTimeLabel->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(user_tab), QCoreApplication::translate("MainWindow", "USER", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(process_tab), QCoreApplication::translate("MainWindow", "Process", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "CPU:", nullptr));
        cpuNameLabel->setText(QCoreApplication::translate("MainWindow", "cpu info", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "CPU Mhz:", nullptr));
        cpuMhz->setText(QCoreApplication::translate("MainWindow", "number", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Cache Size:", nullptr));
        cpuCacheSizeLabel->setText(QCoreApplication::translate("MainWindow", "number", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "CPU used:", nullptr));
        cpuUsed->setText(QCoreApplication::translate("MainWindow", "used", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(cpu_tab), QCoreApplication::translate("MainWindow", "CPU", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "mem total:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "mem free:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "mem usage:", nullptr));
        memTotalLabel->setText(QCoreApplication::translate("MainWindow", "00000", nullptr));
        memFreeLabel->setText(QCoreApplication::translate("MainWindow", "00000", nullptr));
        memUsageLabel->setText(QCoreApplication::translate("MainWindow", "00000", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "mem available:", nullptr));
        memAvailableLabel->setText(QCoreApplication::translate("MainWindow", "00000", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(mem_tab), QCoreApplication::translate("MainWindow", "Memory", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
