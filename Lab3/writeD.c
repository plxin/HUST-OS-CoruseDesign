#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
int main()
{
    int fd;
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    // open the device
    fd = open("/dev/mydriver", O_RDWR, S_IRUSR | S_IWUSR);
    if(fd > 0)
    {
        printf("please enter a string you want to input to mydriver:\n");
        scanf("%s", buf);
        // write to device
        write(fd, buf, strlen(buf));
        close(fd);
    }
    else
    {
        perror("open device");
        exit(1);
    }
    // release the device
    return 0;
}
