#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
struct Node{
	char data;
	struct Node* next;
	struct Node* before;
};

struct Node* createNode(int data)
{
	struct Node* CNode = (struct Node*)malloc(sizeof(struct Node));
	CNode->data = data;
	CNode->next = NULL;
	CNode->before = NULL;
return CNode;
}

void printallNode(struct Node* flgNode)
{
	struct Node* pMove = flgNode;
	while (pMove)
	{
  printf("%p %d\r\n",pMove,pMove->data);
  pMove=pMove->next;
  }
	printf("\n");
}

struct Node* insNodeahead(struct Node* flgNode,int data)
{
	struct Node* iNode = createNode(data);
	iNode->next = flgNode->next;
	flgNode->next = iNode;
return iNode;
}

void deletNode(struct Node* flgNode,struct Node* dNode)
{

}
