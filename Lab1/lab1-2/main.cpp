#include "widget.h"
#include "widget2.h"
#include "widget3.h"
#include "public.h"
#include <QApplication>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    pid_t pid1, pid2, pid3;

    if((pid1 = fork()) == 0)
    {
        QApplication a(argc, argv);
        Widget win1;
        win1.show();
        a.exec();
        exit(0);
    }
    else if(pid1 < 0)
        perror("Process win1");
    if((pid2 = fork()) == 0)
    {
        QApplication a(argc, argv);
        widget2 win2;
        win2.show();
        a.exec();
        exit(0);
    }
    else if(pid2 < 0)
        perror("Process win2");
    if((pid3 = fork()) == 0)
    {
        QApplication a(argc, argv);
        widget3 win3;
        win3.show();
        a.exec();
        exit(0);
    }
    else if(pid3 < 0)
        perror("Process win3");

    return 0;
}
