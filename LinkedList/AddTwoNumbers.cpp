#include<iostream>
using namespace std;

//Problem Solved: Leetcode 2: Add Two Numbers
//Problem link : https://leetcode.com/problems/add-two-numbers/

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

// function prototypes
void PrintList(Node*& head);
Node* AddTwoNumbers(Node*& root1, Node*& root2);
void InsertAtHead(Node*& head, int data);
Node* ReverseLinkedList(Node*& head);

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

void insertAtTail(Node*& head,Node*& tail, int val) {

	Node* temp = new Node(val);
	//empty list
	if (head == NULL) {
		head = temp;
		tail = temp;
		return;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

Node* Sum(Node*& first, Node* second) 
{
	int carry = 0;
	Node* ansHead = NULL;
	Node* ansTail = NULL;
	while (first != NULL || second != NULL || carry!=0) {


		//getting value from first linked list
		int val1 = 0;
		if (first != NULL)
			val1 = first->data;

		//getting value from second linked list
		int val2 = 0;
		if (second != NULL)
			val2 = second->data;

		int sum = carry + val1 + val2;	//how sum is calculated 
		int digit = sum % 10;	//getting the digit to be placed 
		insertAtTail(ansHead, ansTail, digit);		//inserting the digit at tail of new Linkedlist
		carry = sum / 10;

		if (first != NULL)
			first = first->next;
		if (second != NULL)
			second = second->next;
	}
	return ansHead;
};

Node* AddTwoNumbers(Node*& head1, Node*& head2)
{
	Node* first = ReverseLinkedList(head1);
	Node* second = ReverseLinkedList(head2);

	//add two linked list
	Node* ans = Sum(first, second);
	ans = ReverseLinkedList(ans);
	return ans;
}


int main()
{
	Node* h1 = new Node(9);
	InsertAtHead(h1, 9);
	InsertAtHead(h1, 9);

	Node* h2 = nullptr;
	InsertAtHead(h2, 9);
	InsertAtHead(h2, 9);
	InsertAtHead(h2, 9);
	
	PrintList(h1);
	PrintList(h2);

	Node* ans = AddTwoNumbers(h1, h2);

	PrintList(ans);
	return 0;
}