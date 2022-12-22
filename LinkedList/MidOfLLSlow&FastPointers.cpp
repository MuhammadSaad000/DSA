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
//File Completed on : December 22,2022 ;author: Muhammad Saad
Node* MidOfLinkedList(Node*& head);
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

/// <Fast AND Slow Pointers>
/// consider two runners a and b. b is twice fast as a means if b takes 2 step a takes only one (s(a) = s(b)/2) 
/// so when b has reached the end point a is still at the middle of the running track.

Node* MidOfLinkedList(Node*& head)
{
	if (head == NULL || head->next == NULL) {
		return head;
	}
	Node* slow = head;	//move a single step at a time
	Node* fast = head->next;	//moves 2-steps at a time

	while (fast != NULL) {
		fast = fast->next;	//moving first step 
		if (fast != NULL) {		//checking there is place to take second step
			fast = fast->next;	//moving second step
		} 
		slow = slow->next;
	}

	return slow;
}


int main()
{
	Node* head = NULL;

	InsertAtHead(head, 1);
	InsertAtHead(head, 3);
	InsertAtHead(head, 7);
	InsertAtHead(head, 11);
	InsertAtHead(head, 8);


	Node* ans = MidOfLinkedList(head);
	cout << ans->data << endl;

	return 0;
}