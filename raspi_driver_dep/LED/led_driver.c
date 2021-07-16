#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <asm/io.h>        //含有iomap函数iounmap函数
#include <asm/uaccess.h>//含有copy_from_user函数
#include <linux/device.h>//含有类相关的处理函数



static struct class *firt_drv_class;//类
static struct class_device *firt_drv_class_dev[4];//类下面的设备
static int Firstmajor;

static unsigned long *gpfcon = NULL;
static unsigned long *gpfdat = NULL;

static int first_ledsdrv_open(struct inode *inode, struct file *file)
{
    int minor = MINOR(inode->i_rdev);//取得次设备号，根据次设备号来配置IO端口

    switch(minor)
        {
            case 0:
                *gpfcon &= ~((3 << 8)  | (3 << 10) | (3 << 12));//先清0 :8,9,10,11,12,13
                *gpfcon |= ((1 << 8)  | (1 << 10) | (1 << 12));//再置1:8,10,12break;
                printk("initialize leds\n");
                break;
            case 1:
                *gpfcon &= ~((3 << 8) );//先清0 :8,9,10,11,12,13
                *gpfcon |= ((1 << 8));//再置1:8,10,12break;
                printk("initialize led1\n");
                break;
            case 2:
                *gpfcon &= ~( (3 << 10));//先清0 :8,9,10,11,12,13
                *gpfcon |= ( (1 << 10) );//再置1:8,10,12break;
                printk("initialize led2\n");
                break;
            case 3:
                *gpfcon &= ~((3 << 12));//先清0 :8,9,10,11,12,13
                *gpfcon |= ((1 << 12));//再置1:8,10,12break;
                printk("initialize led3\n");
                break;
            default:break;
        }
    
    
//    printk("hello this is open\n");
    return 0;
}


static ssize_t first_ledsdrv_write(struct file *file, const char __user *buf, size_t count, loff_t * ppos)
{
    char val;
    int ret;
    int minor = MINOR(file->f_dentry->d_inode->i_rdev);//根据文件取出次设备号
    
    ret = copy_from_user(&val, buf, count);//ret返回0表示拷贝成功

    if(!ret)
    {
        switch(minor)
        {
            case 0:
                if(val==1)
                {
                    *gpfdat &= ~((1 << 4) | (1<<5) | (1<<6));//点灯
                     printk("leds on\n");
                }
                else if(val == 0)
                {
                    *gpfdat |= ((1 << 4) | (1<<5) | (1<<6));//灭灯
                    printk("leds off\n");
                }
                break;
            case 1:
                if(val==1)
                {
                    *gpfdat &= ~((1 << 4));//点灯
                     printk("led1 on\n");
                }
                else if(val == 0)
                {
                    *gpfdat |= ((1 << 4));//灭灯
                    printk("led1 off\n");
                }
                break;
            case 2:
                if(val==1)
                {
                    *gpfdat &= ~((1<<5));//点灯
                     printk("led2 on\n");
                }
                else if(val == 0)
                {
                    *gpfdat |= ((1<<5));//灭灯
                    printk("led2 off\n");
                }
                break;
            case 3:
                if(val==1)
                {
                    *gpfdat &= ~((1<<6));//点灯
                     printk("led3 on\n");
                }
                else if(val == 0)
                {
                    *gpfdat |= ((1<<6));//灭灯
                    printk("led3 off\n");
                }
                break;
            default:break;
        }
    }
    else
        printk("copy from user wrong!!!!%d  %d\n",ret,count);
//    printk("hello this is write\n");
    return 0;
}


static struct file_operations first_drv_fops = {
    .owner  =   THIS_MODULE,    /* 这是一个宏，推向编译模块时自动创建的__this_module变量 */
    .open   =   first_ledsdrv_open,     
    .write    =    first_ledsdrv_write,       
};


/*
 * 执行insmod命令时就会调用这个函数 
 */
static int __init first_ledsdrv_init(void)
{
    int minor;//次设备号
    Firstmajor = register_chrdev(0, "firstled_drv", &first_drv_fops);//注册first_drv_fops结构体到字符设备驱动表,0表示自动分配主设备号
    if(Firstmajor<0)
    {
              printk(" first_drv can't register major number\n");
              return Firstmajor;
        }

    firt_drv_class = class_create(THIS_MODULE, "leds");//创建类 
    
    firt_drv_class_dev[0] = class_device_create(firt_drv_class, NULL, MKDEV(Firstmajor, 0), NULL, "leds");//创建设备节点
    if (unlikely(IS_ERR(firt_drv_class_dev[0])))
            return PTR_ERR(firt_drv_class_dev[0]);

    for(minor=1;minor<4;minor++)
    {
        firt_drv_class_dev[minor] = class_device_create(firt_drv_class, NULL, MKDEV(Firstmajor, minor), NULL, "led%d",minor);//创建设备节点
        if (unlikely(IS_ERR(firt_drv_class_dev[minor])))
            return PTR_ERR(firt_drv_class_dev[minor]);
    }

    gpfcon = ioremap(0x56000050 , 16);//重映射，将物理地址变换为虚拟地址
    gpfdat = gpfcon + 1;
    
    printk("firstdrv module insmoded\n");
    return 0;
}

/*
 * 执行rmmod命令时就会调用这个函数 
 */
static void __exit first_ledsdrv_exit(void)
{
    int i;
    for(i=0;i<4;i++)
        class_device_unregister(firt_drv_class_dev[i]);//删除设备节点
        
    class_destroy(firt_drv_class);//删除类

    iounmap(gpfcon);//删除重映射分配的地址
    
    unregister_chrdev(Firstmajor, "firstled_drv");//将rst_drv_fops结构体从字符设备驱动表中删除
    printk("firstdrv module rmmod\n");
}


/* 这两行指定驱动程序的初始化函数和卸载函数 */
module_init(first_ledsdrv_init);
module_exit(first_ledsdrv_exit);


MODULE_LICENSE("GPL");//不加的话加载会有错误提醒
MODULE_AUTHOR("andylu");//作者
MODULE_VERSION("0.0.0");//版本
MODULE_DESCRIPTION("S3C2410/S3C2440 LED Driver");//简单的描述
