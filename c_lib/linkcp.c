#include <stdio.h>
#include <stdlib.h>

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

Ndata add_data(char name,long V,int* I)
{
int i=0,num;
while(*(I+i))
{
i++;
}
num=i;
//printf("%d",num);
Ndata data = (Ndata)malloc(5*(num+3));
data->name = name;
data->V = V;
//data->I[0] = *I;
int j;
for (j=0;j<num;j++)
{
data->I[j]=*(I+j);
//printf("ljx_nb %d,%d\r\n",data->I[i],*(I+i));
}
return data;
}


circuit_Node createNode(Ndata data)
{
	circuit_Node CNode = (circuit_Node)malloc(sizeof(CNode));
	CNode->data = data;
//	CNode->next = NULL;
	int i=0,j,num;
	while (data->I[i])
	{
	i++;
	}
	num=i;
//	printf("%d ",num);
circuit_Node NNode[num];
circuit_Node *CNNode = (circuit_Node *)malloc(sizeof(CNode));
for(j=0;j<num;j++)
{
NNode[j]=*(CNNode+j);
}
*NNode = *CNNode;
CNode->next = *NNode;
//circuit_Node *NNode[j] = (circuit_Node)malloc(sizeof(CNode));
return CNode;
}

/*
int Is_END_node(circuit_Node flgNode)
{
	return (flgNode->next == NULL);
}
*/
void printallNode(circuit_Node flgNode)
{
	circuit_Node pMove = flgNode;
	//printf("%d\r\n",num);
	while (pMove)
	{
	int num=0,j=0,i=0;
	while (pMove->data->I[i])
	{
	i++;
	}
	num=i;
//	printf("%d ",num);
	for (;j<num;j++)
	{
  printf("%d ",pMove->data->I[j]);
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
*/

int main()
{
	int a[]={5,4,3,3,3,4,1,4,2,0};
	Ndata data0=add_data('a',5,a);
	circuit_Node Node0=createNode(data0);
	int b[]={5,4,1,4,2,0};
	Ndata data1=add_data('b',3,b);
	circuit_Node Node1=createNode(data1);
	Node0->next=Node1;
//printf("%f\r\n",a[0]);
//printf("%d\r\n",data0->I[2]);
/*
	struct Node* Node1=createNode(1);Node0->next = Node1;
	struct Node* Node2=createNode(2);Node1->next = Node2;
	struct Node* Node3=createNode(3);Node2->next = Node3;
	struct Node* oNode=insNodeahead(Node2,25);
	struct Node* tNode=insNodeahead(Node2,25);
*/
//printf("I= %d\r\n",KCL(Node0));
printallNode(Node0);
free (data0);
free (Node0);
free (data1);
free (Node1);
return 0;
}
