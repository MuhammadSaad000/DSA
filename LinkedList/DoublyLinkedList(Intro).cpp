#include<iostream>
using namespace std;


class Node
{
public:
	int data;
	Node* prev;
	Node* next;
	Node(int data)
	{
		this->data = data;
		prev = NULL;
		next = NULL;
	}
	~Node()
	{
		if (next != NULL) {
			delete next;
			next = NULL;
		}
	}
};


//Problems Discussed: Doubly Linked List 
//File Completed On : December 21, 2022. author : Muhammad Saad
void InsertAtHead(Node*& head, int data);
void InsertAtTail(Node*& tail, int data);
void InsertAtPosition(Node*& head, Node*& tail, int data, int position);
int GetLength(Node*& head);
void PrintList(Node*& head);
void DeleteAtValue(Node*& head, int value);
void DeleteAtPosition(Node*& head, int position);


void PrintList(Node*& head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << endl;
}

int GetLength(Node*& head)
{
	if (head == NULL) {
		return 0;
	}
	if (head->next == NULL) {
		return 1;
	}
	else {
		Node* temp = head;
		int count = 0;
		while (temp != NULL) {
			temp = temp->next;
			count++;
		}
		return count;
	}
}


void InsertAtHead(Node*& head, int data)
{
	if(head == NULL)	// there is no node LinkedList is empty
	{
		Node* newNode = new Node(data);
		head = newNode;
	}
	else
	{
		Node* newNode = new Node(data);
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	return;
}

void InsertAtTail(Node*& tail, int data)
{
	Node* temp = tail;
	if (tail == NULL)
	{
		Node* newNode = new Node(data);
		tail = newNode;
	}
	else
	{
		Node* newNode = new Node(data);
		tail->next = newNode;	//linking next pointer of tail node to the newNode address
		newNode->prev = tail;	//linking previous pointer of the newNode to the tail 
		tail = newNode;	// now newNode is tail
	}
}

void InsertAtPosition(Node*& head, Node*& tail, int data, int position)
{
	Node* temp = head;
	if (position == 1)
	{
		InsertAtHead(head, data);
	}
	int count = 1;
	while (count < position - 1)
	{
		temp = temp->next;
		count++;
	}
	
	Node* newNode = new Node(data);
	//inserting at last position
	if (temp->next == NULL)
	{
		InsertAtTail(tail, data);
	}
	else {
		newNode->prev = temp;
		newNode->next = temp->next;
		temp->next->prev = newNode;
		temp->next = newNode;
	}
	
}

void DeleteAtPosition(Node*& head,int position)
{
	Node* temp = head;
	//deleting first node
	if (position == 1) {
		temp->next->prev = NULL;
		head = temp->next;
		temp->next = NULL;
		delete temp;
	}

	//deleting in-between & last node 
	else {
		int count = 1;
		Node* back = NULL;
		Node* curr = head;
		while (count < position )
		{
			back = curr;	//moving previous pointer 
			curr = curr->next;	//moving current pointer 
			count++;
		}
		back->next = curr->next;
		curr->next = back;
		curr->prev = NULL;
		curr->next = NULL;
		delete curr;
	}

}

void DeleteAtValue(Node*& head, int value)
{
	Node* back = NULL;
	Node* curr = head;
	if (curr->data == value) { //checking for first node's value
		curr->next->prev = NULL;
		head = curr->next;	//head is now at the address of current node next 
		curr->next = NULL;
		delete curr;
	}
	else {
		while (curr->data != value && curr!=NULL) {
			back = curr;
			curr = curr->next;
		}
		back->next = curr->next;
		curr->next = back;
		curr->prev = NULL;
		curr->next = NULL;
		delete curr;
	}
}



int main()
{
	Node* n1 = new Node(5);
	Node* head = n1;
	Node* tail = n1;

	PrintList(head);
	cout << GetLength(head) << endl;
	
	cout << "Inserting at Head : " << endl;
	InsertAtHead(head,1);

	PrintList(head);
	cout << GetLength(head) << endl;

	InsertAtTail(tail, 6);
	PrintList(head);

	InsertAtPosition(head, tail, 4, 2);
	PrintList(head);

	DeleteAtPosition(head, 4);
	PrintList(head);

	DeleteAtValue(head, 1);
	PrintList(head);

	return 0;
}