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
}*circuit_Node,cNode;

Ndata add_data(char name,long V,int* I);
void printallNode(cNode flgNode);
cNode createNode(Ndata data);

int main()
{
        int a[]={5,4,3,3,3,4,1,4,2,0};
        Ndata data0=add_data('a',5,a);
        int b[]={5,4,1,4,2,0};
        Ndata data1=add_data('b',3,b);
        int c[]={5,6,4,2,3,2,0};
        Ndata data2=add_data('c',3,c);
        cNode Node0=createNode(data0);
        cNode Node1=createNode(data1);
        cNode Node2=createNode(data2);
        Node0.next[0]=Node1;
        Node1.next[0]=Node2;
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
//free(data0);
//free(data1);
//free(data2);
return 0;
}
