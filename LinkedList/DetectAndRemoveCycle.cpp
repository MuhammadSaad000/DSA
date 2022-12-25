#include<iostream>
using namespace std;

//File completed on : December 25, 2022.
//Detect and Remove cycle in Linked List 


class Node {
public:
	int data;
	Node* next;	//storing address of next node 

	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
	~Node() {
		int value = this->data;
		if (this->next != NULL) {
			delete next;
			this->next = NULL;
		}
	}
};

void InsertAtHead(Node*& head, int data);
void InsertAtTail(Node*& tail, int data);
void PrintList(Node*& head);
Node* FloydCycle(Node*& head);	//detecting floyd's cycle

void InsertAtHead(Node*& head, int data)
{
	Node* newNode = new Node(data); //create a node and insert data in it
	newNode->next = head;	//pointing(storing) address of head newNode
	head = newNode;	//now head will point at newNode 
}

void PrintList(Node*& head)
{
	Node* temp = head; //storing address of head in temporary node
	while (temp != NULL) {
		cout << temp->data << "->"; //printing data of head currently pointed by temp 
		temp = temp->next;	//storing address of next node in temp 
	}
	cout << endl;
}

void InsertAtTail(Node*& tail, int data)
{
	Node* newNode = new Node(data);
	tail->next = newNode;	//updating address of tail node to newNode address
	newNode->next = NULL;	//storing NULL in next of newNode (as newNode is tail now)
	tail = newNode;		//upadating tail variable in original list 
}


//Floyd cycle uses fast and slow pointer concept
Node* FloydCycle(Node*& head)
{
	if (head == NULL)
		return NULL;

	Node* slow = head;
	Node* fast = head;
	while (slow != NULL && fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			fast = fast->next;
		}
		slow = slow->next;
		if (slow == fast) {
			return slow;	//this will be the node where loop occurs
		}
	}
	return NULL;
}

Node* GetStartingNode(Node*& head)
{
	if (head == NULL)
		return NULL;

	Node* intersectionPoint = FloydCycle(head);
	if (intersectionPoint == NULL)
		return NULL;
	Node* slow = head;
	while (slow != intersectionPoint) {
		slow = slow->next;
		intersectionPoint = intersectionPoint->next;
	}
	return slow;
}

void RemoveLoop(Node*& head)
{
	if (head == NULL)
		return;
	Node* start = GetStartingNode(head);
	if (start == NULL) 
		return;
	Node* temp = start;
	while (temp->next != start)
	{
		temp = temp->next;
	}
	temp->next = NULL;
}



int main()
{
	Node* n1 = new Node(2);
	
	Node* head = n1;
	Node* tail = n1;

	InsertAtHead(head, 5);
	InsertAtHead(head, 1);
	InsertAtHead(head, 4);

	PrintList(head);

	InsertAtTail(tail, 6);

	PrintList(head);

	//pointing tail to the second node to create cycle
	tail->next = head->next->next;

	FloydCycle(head);
	Node* loop = GetStartingNode(head);
	cout << "Loop starts from " << loop->data << endl;

	RemoveLoop(loop);
	cout << FloydCycle(head)->data << endl;

	return 0;
}