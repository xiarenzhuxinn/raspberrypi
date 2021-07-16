KERN_DIR = /work/system/linux-2.6.22.6

all:
	make -C $(KERN_DIR) M=`pwd` modules //M='pwd'表示当前目录。这句话的意思是利用内核目录下的Makefile规则来编译当前目录下的模块

clean:
	make -C $(KERN_DIR) M=`pwd` modules clean
	rm -rf modules.order

obj-m   +=first_drv.o//调用内核目录下Makefile编译时需要用到这个参数
