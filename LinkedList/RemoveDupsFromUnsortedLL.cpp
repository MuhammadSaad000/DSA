#include<iostream>
#include<stack>
using namespace std;

// File completed on : December 28, 2022.
// Remove Duplicates from a Unsorted Linked List 
// Problem Link: https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/
//approach used : Brute Force


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
		if (this->next != NULL) {
			delete next;
			this->next = NULL;
		}
	}
};

//declarations
void InsertAtHead(Node*& head, int data);
void PrintList(Node*& head);
Node* RemoveFromUnsorted(Node*& head);


//definitions
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

Node* RemoveFromUnsorted(Node*& head)
{
	if (head == NULL)
		return NULL;

	Node* curr = head;
	while (curr != NULL) {
		Node* runner = curr;	//pointer for inner loop 
		while (runner->next != NULL)
		{
			if (runner->next->data == curr->data) {
				Node* nodetoDel = runner->next;	//node which contains duplicate data
				runner->next = runner->next->next;
				nodetoDel->next = NULL;
				delete nodetoDel;
			}
			else {
				runner = runner->next;
			}
		}
		curr = curr->next;
	}
	return head;
}


int main()
{

	Node* head = NULL;

	InsertAtHead(head, 6);
	InsertAtHead(head, 4);
	InsertAtHead(head, 6);
	InsertAtHead(head, 5);
	InsertAtHead(head, 4);
	InsertAtHead(head, 3);
	InsertAtHead(head, 3);

	PrintList(head);
	head = RemoveFromUnsorted(head);

	PrintList(head);
	
	return 0;
}