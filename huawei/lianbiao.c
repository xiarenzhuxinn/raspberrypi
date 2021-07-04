/*约瑟夫环*/
#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
int data;
struct node *next;
}LNode;
main()
{
LNode* Create(int,int);
LNode* GetNode(LNode *);
int Print(LNode *,int);
LNode *p;
int n,k,m;
do
{
printf ( "输入总人数 ");
scanf ( "%d ",&n);
}
while (n <=0);
do
{
printf ( "输入开始人的序号(1~%d) ",n);
scanf ( "%d ",&k);
}
while (k <=0 || k> n);
do
{
printf ( "输入间隔数字 ");
scanf ( "%d ",&m);
}
while(m <=0);
p=Create(n,k);
Print(p,m);
return 0;
}
LNode* Create(int n,int k)/*创建循环链表*/
{
int start=k-1;
LNode *s,*p,*L=0,*t;
if (start==0) start=n;
while (n!=0)
{
s=(LNode *)malloc(sizeof(LNode));
if (L==0) p=s;
if (n==start) t=s;
s-> data=n;
s-> next=L;
L=s;
n--;
}
p-> next=L;
return t;
}
LNode* GetNode(LNode *p)/*出队函数*/
{
LNode *q;
for (q=p;q-> next!=p;q=q-> next);
q-> next=p-> next;
free (p);
return (q);
}
Print(LNode *p,int m)/*输出函数*/
{
int i;
printf ( "出队编号:\n ");
while (p-> next!=p)
{
for (i=1;i <=m;i++)
p=p-> next;
printf ( "%d ",p-> data);
p=GetNode(p);
}
printf( "%d\n ",p-> data);
return 0;
}
