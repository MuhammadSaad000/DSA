#include<iostream>
using namespace std;

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


//Problem Discussed : Find Mid of Linked List 
// https://leetcode.com/problems/middle-of-the-linked-list/
//File Completed on : December 23,2022 ;author: Muhammad Saad
Node* ReverseKGroup(Node*& head,int k);
void InsertAtHead(Node*& head, int data);
void PrintList(Node*& head);

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

Node* ReverseKGroup(Node*& head,int k)
{
	// base case of recursive call
	if (head == NULL)
	{
		return NULL;
	}

	Node* prev = NULL;
	Node* curr = head;
	Node* forward = NULL;

	int count = 0;
	while (curr != NULL && count < k){	//reversing first k nodes iteratively
		forward = curr->next;
		curr->next = prev;
		prev = curr;	//moving prev node
		curr = forward;	//MOVING curr pointer
		count++;
	}

	//after reversing first k-nodes head will be at forward 
	if (forward != NULL) {
		head->next = ReverseKGroup(forward, k);
	}

	//after reversing all groups of head will be at previous
	return prev;	
}


int main()
{
	Node* head = NULL;

	InsertAtHead(head, 1);
	InsertAtHead(head, 3);
	InsertAtHead(head, 7);
	InsertAtHead(head, 11);
	InsertAtHead(head, 8);
	PrintList(head);

	head = ReverseKGroup(head, 3);
	PrintList(head);

	return 0;
}