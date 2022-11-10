#include<iostream>
#include<typeinfo>	//check the type of variable using builtin function
using namespace std;

//File Completed On : November 10,2022.
//Insert at start,end and middle of singly linked list
//Delete node at a given position 

class Node {
public:
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
	~Node()
	{
		int value = this->data;
		if (this->next != NULL) {
			delete next;
			this->next = NULL;
		}
	}

};

//Insert Element at the start of linked list
void InsertAtHead(Node*& head,int data) 
{
	Node* temp = new Node(data);
	//cout << typeid(temp).name() << endl;
	temp->next = head;
	head = temp;
}

//how to traverse a Linked List
void Print(Node*& head)
{	
	Node* temp = head;
	//cout << typeid(temp).name() << endl;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << endl;
}

//Insert Element at the last of linked list
void InsertAtTail(Node*& tail,int data)
{
	Node* temp = new Node(data);
	tail->next = temp;
	tail = temp;
}

void InsertAtPosition(Node* &head,int position, int data)
{
	Node* temp = head;
	//counting head node as 1
	int count = 1;
	while (count < position - 1) {
		temp = temp->next;
		count++;
	}

	Node* newNode = new Node(data);
	newNode->next = temp->next;
	temp->next = newNode;	//temp m newNode ka address rakhwa den 

}

void DeleteAt(Node*& head, int position)
{
	if (position == 1)
	{
		Node* temp = head; //storing head in a temp node 
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	else
	{
		Node* curr = head;
		Node* prev = NULL;
		int count = 1;
		while (count < position)
		{
			prev = curr;
			curr = curr->next;
			count++;
		}
		prev->next = curr->next;
		curr->next = NULL;
		delete curr;
	}
}

int main()
{
	Node* n1 = new Node(3);
	
	Node* head = n1;
	Node* tail = n1;

	InsertAtTail(tail, 5);
	Print(head);
	InsertAtHead(head, 1);
	Print(head);
	InsertAtPosition(head, 3, 2);
	Print(head);
	DeleteAt(head, 1);
	Print(head);

	return 0;
}