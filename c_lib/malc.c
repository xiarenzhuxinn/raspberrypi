#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>//包含malloc函数的头文件

struct Item//定义结构体
{
	char name[20];
	int num;	
};

struct Item *I;//申请Item类型的指针

void A()//进行内存申请
{
	;//申请的数量
	I=(struct Item*)malloc(sizeof(struct Item));
}

void Input()//数据输入函数
{
A();
	{
		printf("Name:\n");
		scanf("%s",(char*)&(I->name));
		printf("num:\n");
		scanf("%d",(int*)&(I->num));
	}
}

void output()//数据输出函数
{
Input();
		printf("Name:%s  ",I->name);
		printf("num:%d\n",I->num);
}

int main()
{
	output();
	return 0;
}
