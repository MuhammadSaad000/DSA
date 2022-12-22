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
int LengthOfList(Node*& head);


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


int LengthOfList(Node*& head)
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

Node* MidOfLinkedList(Node*& head)
{
	Node* temp = head;
	int len = LengthOfList(head);
	int count = 0;
	while (count < (len / 2))
	{
		temp = temp->next;
		count++;
	}
	//cout << len << endl;
	//cout << temp->data << endl;
	return temp;
}


int main()
{
	Node* head = NULL;

	InsertAtHead(head, 1);
	InsertAtHead(head, 3);
	InsertAtHead(head, 2);
	InsertAtHead(head, 7);
	InsertAtHead(head, 11);
	InsertAtHead(head, 8);


	Node* ans = MidOfLinkedList(head);
	cout << ans->data << endl;


	return 0;
}