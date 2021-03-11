#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

int main()
{
    syscall(326);
}
