#include<iostream>
using namespace std;

// File completed on : December 29, 2022.
// Detect / Delete nth node from last  
// Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
int kthNodeFromLast(Node*& head, int k);
int kthFromLast(Node*& head, int k);
Node* DeleteKthNode(Node*& head, int k);

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

//Approach-I : If length is known (length - k)th node is kth last node 
int kthNodeFromLast(Node*& head, int k)
{
	int len = SizeOfList(head);

	if (k <= len && head != NULL)
	{
		Node* temp = head;
		int count = 0;
		while (count < len) {
			if ((len - k) == count) {
				break;
			}
			else {
				temp = temp->next;
			}
			count++;
		}
		return temp->data;
	}
	else
		return NULL;
}

//Approach-II : If length is not known Recursive Solutions (ctci - pg # 209)
int kthFromLast(Node*& head, int k)
{
	if (head == NULL)
		return 0;

	int idx = kthFromLast(head->next, k) + 1;
	if (idx == k) {
		cout << "Eqaul : ";
		cout << head->data << endl; 
	}
	else {
		cout << "My index " << idx << endl;
	}
	return idx;
}

Node* DeleteKthNode(Node*& head, int k)
{
	Node* prev = NULL;
	Node* curr = head;
	int len = SizeOfList(head);
	if (k <= len && head != NULL)
	{
		int count = 0;
		while (count < len) {
			if ((len - k) == count) {
				if (count > 0)
					prev->next = curr->next;
				else
				{
					Node* temp = head;
					head = head->next;
					temp->next = NULL;
					delete temp;
				}
				break;
			}
			else {
				prev = curr;
				curr = curr->next;
			}
			count++;
		}
		return head;
	}
	else
		return NULL;
}

int main()
{

	Node* head = NULL;

	InsertAtHead(head, 6);
	InsertAtHead(head, 5);
	InsertAtHead(head, 5);
	InsertAtHead(head, 5);
	InsertAtHead(head, 4);
	InsertAtHead(head, 3);
	InsertAtHead(head, 3);

	PrintList(head);

	cout << kthNodeFromLast(head, 2) << endl;
	//cout << kthFromLast(head, 5) << endl;

	DeleteKthNode(head, 7);
	PrintList(head);

	return 0;
}