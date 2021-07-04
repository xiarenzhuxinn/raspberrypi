#include "link.h"
int main()
{
	struct Node* Node0=createNode(0);
	struct Node* Node1=createNode(1);Node0->next = Node1;
	struct Node* Node2=createNode(2);Node1->next = Node2;
	struct Node* Node3=createNode(3);Node2->next = Node3;
	struct Node* oNode=insNodeahead(Node2,25);
	struct Node* tNode=insNodeahead(Node2,25);
	printallNode(Node0);
	return 0;
}
