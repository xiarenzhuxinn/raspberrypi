#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>//包含malloc函数的头文件

struct Item//定义结构体
{
	char name[20];
	int num;	
};

struct Item *I;//申请Item类型的指针

int A()//进行内存申请
{
	int n;//申请的数量
	scanf("%d",&n);
	I=(struct Item*)malloc(sizeof(struct Item)*n);
	return n;	
}

int Input()//数据输入函数
{
	int n=A();
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d Name:",i+1);
		scanf("%s",(char*)&I[i].name);
		printf("num:\n");
		scanf("%d",(int*)&I[i].num);
	}
	return n;	
}

void output()//数据输出函数
{
	int n=Input();
	for(int i=0;i<n;i++)
	{
		printf("%d   |",i);
		printf("Name:%s  ",I[i].name);
		printf("num:%d\n",I[i].num);
	}
}

int main()
{
	output();
	free(I);
	return 0;
}
