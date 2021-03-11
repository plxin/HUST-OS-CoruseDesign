SYSCALL_DEFINE0(mysyscall)
{
        printk("This is plx's syscall!");

        return 0;
}

SYSCALL_DEFINE2(mycp, const char __user *, souce_file, const char __user *, target_file)
{
        int source_fd, target_fd, write_bytes, read_bytes;
        const int BUF_SIZE = 512;
        char buf[BUF_SIZE];
        mm_segment_t fs;

        if((source_fd = sys_open(source_file, O_RDONLY, 0) == -1)
        {
                printk("open source file error!");
                sys_exit(-1);
        }

        if((target_fd = sys_open(target_file, O_CREAT | O_WRONLY, 0664)) == -1)
        {
                printk("create target file error!");
                sys_exit(-1);
        }
        fs = get_fs();
        set_fs(get_ds());

        while(1)
        {
                read_bytes = sys_read(source_fd, buf, BUF_SIZE);
                if(read_bytes < 0)
                {
                        printk("Read fail!");
                        sys_exit(-1);
                }
                else if(read_bytes == 0)
                        break;
                else
                {
                        write_bytes = sys_write(target_fd, buf, read_bytes);
                        if(write_bytes < 0)
                        {
                                printk("Write fail!");
                                sys_exit(-1);
                        }
                        else if(write_bytes == 0)
                                break;
                }
        }
        set_fs(fs);

        sys_close(source_fd);
        sys_close(target_fd);
        return 0;
}

