#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    if(argc != 3)
    {
        printf("parameters num is wrong!\n");
        exit(-1);
    }

    syscall(327, argv[1], argv[2]);

    return 0;
}
