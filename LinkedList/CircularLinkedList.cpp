#include<iostream>
using namespace std;

//Circular Linked List 
//File Completed On : December 25,2022.

class Node
{
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

//functions created ..../
void InsertAtHead(Node*& head, int data);
void InsertAtTail(Node*& head, int data);
void DeleteHead(Node*& head);
void DeleteTail(Node*& head);
void PrintList(Node*& head);

void InsertAtHead(Node* &head, int data) {
	if (head == NULL) {
		Node* newNode = new Node(data);
		newNode->next = newNode;
		head = newNode;
	}
	else {
		Node* temp = head;
		Node* newNode = new Node(data);
		while (temp->next != head) {
			temp = temp->next;
		}
		newNode->next = head;
		temp->next = newNode;
		head = newNode;
	}
	return;
}

void InsertAtTail(Node*& head, int data)
{
	if (head == NULL) {
		Node* newNode = new Node(data);
		newNode->next = newNode;
		head = newNode;
	}
	else {
		Node* temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}
		Node* newNode = new Node(data);
		temp->next = newNode;
		newNode->next = head;
	}
	return;
}

void DeleteHead(Node*& head)
{
	if (head == NULL)
		cout << "Linked list is empty " << endl;
	else {
		Node* prev = NULL;
		Node* curr = head;
		while (curr->next != head) {
			prev = curr;
			curr = curr->next;
		}
		curr->next = head->next;
		head = head->next;	//now head will point to a newNode
		prev = NULL;
		delete prev;
	}
	return;
}

void DeleteTail(Node*& head)
{
	if (head == NULL) {
		cout << "Linked List is empty " << endl;
	}
	else {
		Node* prev = NULL;
		Node* curr = head;
		while (curr->next != head) {
			prev = curr;	
			curr = curr->next;
		}
		prev->next = head;
		curr = NULL;
		delete curr;
	}
}

void PrintList(Node*& head)
{
	Node* temp = head;
	if (head == NULL) {
		cout << "List is empty";
	}
	else {
		while (temp->next != head)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << temp->data << "->";
		cout << endl;
	}	
	return;
}


int main()
{
	Node* head = NULL;
	InsertAtHead(head, 5);
	InsertAtHead(head, 1);
	PrintList(head);

	InsertAtHead(head, 6);
	PrintList(head);

	InsertAtTail(head, 3);
	PrintList(head);

	DeleteTail(head);
	PrintList(head);
	
	DeleteHead(head);
	PrintList(head);


	return 0;
}