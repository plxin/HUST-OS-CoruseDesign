#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/uaccess.h>

#if CONFIG_MODVERSIONS == 1
#define MODVERSIONS
#include <linux/version.h>
#endif

#define DEVICE_NUM 0

static int device_num = 0;
static char buffer[1024] = "This is my driver";
static int open_nr = 0;

static int mydriver_open(struct inode *inode, struct file *filp);
static int mydriver_release(struct inode *inode, struct file *filp);
static ssize_t mydriver_read(struct file *file, char __user *buf, size_t count, loff_t *f_pos);
static ssize_t mydriver_write(struct file *file, const char __user *buf, size_t count, loff_t *f_pos);

static struct file_operations mydriver_fops = {
    .read = mydriver_read,
    .write = mydriver_write,
    .open = mydriver_open,
    .release = mydriver_release,
};


static int mydriver_open(struct inode *inode, struct file *filp)
{
    printk("\nMain device is %d, and the slave device is %d\n", MAJOR(inode->i_rdev), MINOR(inode->i_rdev));
    if(open_nr == 0)
    {
        open_nr++;
        try_module_get(THIS_MODULE);
        return 0;
    }  
    else
    {
        printk(KERN_ALERT"Another process has opened this char device.\n");
        return -1;
    }
}


static int mydriver_release(struct inode *inode, struct file *filp)
{
    open_nr--;
    printk("The device is released!\n");
    module_put(THIS_MODULE);

    return 0;
}
static ssize_t mydriver_read(struct file *file, char __user *buf, size_t count, loff_t *f_pos)
{
    // if(buf == NULL) return 0;
    if(copy_to_user(buf, buffer, sizeof(buffer)))
        return -1;

    return sizeof(buffer);
}
static ssize_t mydriver_write(struct file *file, const char __user *buf, size_t count, loff_t *f_pos)
{
    
    // if(buf == NULL) return 0;
    if(copy_from_user(buffer, buf, sizeof(buffer)))
        return -1;

    return sizeof(buffer);
    
}


static int __init mydriver_init(void)
{
    int result;
    printk(KERN_ALERT"Begin to init Char Device");

    result = register_chrdev(DEVICE_NUM, "mydriver", &mydriver_fops);

    if(result < 0)
    {
        printk(KERN_WARNING"mydriver: register failure\n");
        return -1;
    }
    else
    {
        printk("mydriver : register success\n");
        device_num = result;
        return 0;
    }
}

static void __exit mydriver_exit(void)
{
    printk(KERN_ALERT"Unloading...\n");
    unregister_chrdev(device_num, "mydriver");
    printk("unregister success\n");
}


module_init(mydriver_init);
module_exit(mydriver_exit);

MODULE_LICENSE("GPL");
