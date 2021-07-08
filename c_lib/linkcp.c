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
int i=0,num_circle;
while(*(I+i))
{
i++;
}
num_circle=i;
//printf("%d",num_circle);
Ndata data = (Ndata)malloc(num_circle*(num_circle+1)+1);
data->name = name;
data->V = V;
//data->I[0] = *I;
int j;
for (j=0;j<num_circle;j++)
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
void printallNode(circuit_Node flgNode)
{
	circuit_Node pMove = flgNode;
	int j=0,i=0,num;
	while (flgNode->data->I[i])
	{
	i++;
	}
	num=i;
//	printf("%d\r\n",num);
	while (pMove)
	{
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
	int a[]={4,2,9,3,5,3};
	Ndata data0=add_data('a',5,a);
	circuit_Node Node0=createNode(data0);
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
	return 0;
}
