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


//Problems Discussed : Reverse Linked list using Recursion 
// https://leetcode.com/problems/reverse-linked-list/

Node* ReverseLinkedList(Node*& head);

// Reversal using Recursion
void Reverse(Node* head, Node* curr, Node* prev);


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

int LengthOfList(Node*& head)
{
	Node* temp = head;
	int count = 1;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}

void InsertAtMid(Node*& head, Node* tail, int position, int data)
{
	Node* newNode = new Node(data);
	Node* temp = head;

	//handling position 1 
	int len = LengthOfList(head);
	if (position > len) {
		cout << "Length of list is : " << len - 1 << endl;
	}

	else if (position == 1) {
		InsertAtHead(head, data);
		return;	//exit point
	}

	else if (temp->next == NULL) {
		InsertAtTail(tail, data);
		return;
	}

	else {
		int count = 1;
		while (count < position - 1) { //iterate while count is less than position
			temp = temp->next;
			count++;
		}
		newNode->next = temp->next;		//storing address of temp in next of newNode to 
		temp->next = newNode; //linking current node with newNode 
	}
}

void DeleteAt(Node*& head, int position)
{
	if (position == 1)
	{
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	else {
		Node* curr = head;
		Node* prev = NULL;
		int count = 1;
		while (count < position) {
			prev = curr;
			curr = curr->next;
			count++;
		}
		prev->next = curr->next;
		curr->next = NULL;
		delete curr;
	}

}


Node* ReverseLinkedList(Node*& head)
{
	//base case if there is no node or single node
	if (head == NULL || head->next == NULL) {
		return head;
	}

	Node* prev = NULL;
	Node* curr = head;
	Node* forward = NULL; //initially storing address of 2nd node in forward pointer
	
	while (curr != NULL) {	//simply moving to the last node/end of list
		forward = curr->next;	
		curr->next = prev; //pointing the current node to address of previous initially firstnode will point at NULL
		prev = curr;	//moving 
		curr = forward;	//moving forward pointer 
	}
	return prev;	//now head will be at prev pointer node
}

//reversal using recursion
void Reverse(Node* head, Node* curr, Node* prev)
{
	//base case
	if (curr == NULL) {
		head = prev;
		return;
	}
	Node* forward = curr->next;

	Reverse(head, forward, curr);	//moving pointers using recursive call
	curr->next = prev;	//moving last pointer

	PrintList(head);
}


int main()
{
	Node* head = NULL;
	InsertAtHead(head, 4);
	InsertAtHead(head, 1);
	InsertAtHead(head, 8);
	cout << "Before Reversal : ";
	PrintList(head);

	cout << "After Reversal : ";
	head = ReverseLinkedList(head);
	PrintList(head);


	return 0;
}
