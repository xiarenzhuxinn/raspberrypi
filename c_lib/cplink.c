#include <stdio.h>
#include <stdlib.h>

#define num_node 2
#define num_circle 5

typedef struct Node_data
{
char name;
int V;
int I[];
}*Ndata,data;

typedef struct Node
{
	Ndata data;
	struct Node *next;
}*circuit_Node,CNode;

circuit_Node createNode(Ndata data)
{
	circuit_Node CNode = (circuit_Node)malloc(sizeof(CNode));
	CNode->data = data;
	CNode->next = NULL;
	/*
circuit_Node NNode[num];
circuit_Node *NNodep = (circuit_Node *)malloc(num*sizeof(CNode));
NNode[num] = *NNodep;

CNode->next = *NNode;

for (j=0;j<num_circle;j++)
{
printf("ljxnb ");
//circuit_Node *NNode[j] = (circuit_Node)malloc(sizeof(CNode));
*NNode[j]->data->I[j]=CNode->data->I[j];
printf("%d \r\n",NNode[j]->data->I[j]);
}
*/
return CNode;
}
/*
int Is_END_node(circuit_Node flgNode)
{
	return (flgNode->next == NULL);
}
*/
int count_num_circle(circuit_Node flgNode)
{
int num=0,i;
for (i=0;i<num_circle;i++)
{
	if (flgNode->data->I[i])
	{
  num++;
  }
}
return num;
}

void printallNode(circuit_Node flgNode)
{
	circuit_Node pMove = flgNode;
	int i;
	while (pMove)
	{
	for (i=0;i<num_circle;i++)
	{
	printf("%d ",pMove->data->I[i]);
	}
	printf("%c ",pMove->data->name);
	printf("%d\r\n",pMove->data->V);
	pMove=pMove->next;
  }
}
/*
circuit_Node insNodeahead(circuit_Node flgNode,Ndata data)
{
	circuit_Node iNode = createNode(data);
	iNode->next = flgNode->next;
	flgNode->next = iNode;
return iNode;
}

void deletNode(struct Node* flgNode,struct Node* dNode)
{

}
*/
int KCL(circuit_Node flgNode)
{
int i;
float sum=0;
for (i=0;i<num_circle;i++)
{
sum += *(int*)&flgNode->data[i];
}
return -sum;
}

Ndata add_data(char name,long V,int *I)
{
Ndata data = (Ndata)malloc(4*(num_circle+1)+1);
data->name = name;
data->V = V;
//data->I[0] = *I;
int i;
for (i=0;i<num_circle;i++)
{
data->I[i]=*(I+i);
//printf("ljx_nb %d,%d\r\n",data->I[i],*(I+i));
}
return data;
}

int main()
{
	int a[num_circle]={7,4,0,5,9};
	Ndata data0=add_data('a',5,a);
	circuit_Node Node0=createNode(data0);
//	printf("%d\r\n",count_num_circle(Node0));
//printf("%d\r\n",data0->I[2]);
/*
	struct Node* Node1=createNode(1);Node0->next = Node1;
	struct Node* Node2=createNode(2);Node1->next = Node2;
	struct Node* Node3=createNode(3);Node2->next = Node3;
	struct Node* oNode=insNodeahead(Node2,25);
	struct Node* tNode=insNodeahead(Node2,25);
*/
//printf("I= %d\r\n",KCL(Node0));
//printallNode(Node0);
free (data0);
free (Node0);
	return 0;
}
