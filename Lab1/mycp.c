// open()
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
// close()
#include <unistd.h>
// perror errno
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        perror("Parameter's number is wrong!");
        exit(-1);
    }

    int source_fd, destination_fd;
    char buf[BUF_SIZE];
    ssize_t read_bytes, write_bytes;
    // char *temp;

    source_fd = open(argv[1], O_RDONLY);
    if(source_fd < 0)
    {
        perror("Open source file error!");
        exit(-1);
    }

    destination_fd = open(argv[2], O_CREAT | O_WRONLY, 0664);    
    if(destination_fd < 0)
    {
        perror("Open destination file error!");
        exit(-1);
    }

    // ready to write
    while(1)
    {
        read_bytes = read(source_fd, buf, BUF_SIZE);
        if(read_bytes < 0)
        {
            perror("Read fail!");
            exit(-1);
        }
        else if(read_bytes == 0)
            break;
        else
        {
            write_bytes = write(destination_fd, buf, read_bytes);
            if(write_bytes < 0)
            {
                perror("Write fail!");
                exit(-1);
            }
            else if(write_bytes == 0)
            {
                break;
            }
        }
    }

    close(source_fd);
    close(destination_fd);

    return 0;
}
