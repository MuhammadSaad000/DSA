#include<iostream>
using namespace std;

// File completed on : December 29, 2022.
// Detect / Delete middle node from last  without length of linked list 
// Problem Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

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

//declarations
void InsertAtHead(Node*& head, int data);
void PrintList(Node*& head);
int SizeOfList(Node*& head);
Node* DeleteMid(Node*& head);

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
int SizeOfList(Node*& head)
{
	Node* temp = head;
	int len = 0;
	while (temp != NULL){
		len++;
		temp = temp->next;
	}
	return len;
}


// Approach : Using Fast and slow pointers
Node* DeleteMid(Node*& head)
{
	//if there is a single element in linked list 
	if (head == NULL || head->next == NULL)
		return NULL;


	Node* slow = head;
	Node* fast = head;
	Node* temp = NULL;	//pointer to contain linking address of prev and next node bw mid node
	while (fast->next != NULL) {
		temp = slow;
		slow = slow->next;
		fast = fast->next;
		if (fast->next != NULL) {
			fast = fast->next;
		}
	}

	//now slow is at the middle node of linked list
	temp->next = slow->next;
	delete slow;	//as slow is pointing to the middle of linked list 

	return head;
}


int main()
{

	Node* head = NULL;

	InsertAtHead(head, 2);
	InsertAtHead(head, 1);
	InsertAtHead(head, 3);
	InsertAtHead(head, 5);
	InsertAtHead(head, 4);
	InsertAtHead(head, 6);
	InsertAtHead(head, 7);

	PrintList(head);

	head = DeleteMid(head);
	PrintList(head);



	return 0;
}