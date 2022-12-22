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


//Problems Discussed: Reverse a Doubly Linked List 
//File Completed On : December 22, 2022. author : Muhammad Saad
void InsertAtHead(Node*& head, int data);
void PrintList(Node*& head);
Node* ReverseLinkedList(Node*& head);	//same for singly linkedlist


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

void InsertAtHead(Node*& head, int data)
{
	if (head == NULL)	// there is no node LinkedList is empty
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

//same code for singly linked list 
Node* ReverseLinkedList(Node*& head)
{
	//base case if there is no node or single node
	if (head == NULL || head->next == NULL) {
		return head;
	}

	Node* back = NULL;
	Node* curr = head;
	Node* forward = NULL; //initially storing address of 2nd node in forward pointer

	while (curr != NULL) {	//simply moving to the last node/end of list
		forward = curr->next;
		curr->next = back; //pointing the current node to address of previous initially firstnode will point at NULL
		back = curr;	//moving 
		curr = forward;	//moving forward pointer 
	}
	return back;	//now head will be at prev pointer node
}



int main()
{

	Node* head = NULL;

	InsertAtHead(head, 1);
	InsertAtHead(head, 5);
	InsertAtHead(head, 2);

	
	PrintList(head);
	head = ReverseLinkedList(head);
	PrintList(head);

	return 0;
}