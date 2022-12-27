#include<iostream>
using namespace std;

//File completed on : December 27, 2022.
//Detect and Remove cycle in Linked List 

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
Node* RemoveFromSorted(Node*& head);

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
Node* RemoveFromSorted(Node*& head)
{
	if (head == NULL)
		return NULL;
	else {
		Node* curr = head;
		while (curr->next != NULL) {
			if (curr->data == curr->next->data) {
				Node* nextX = curr->next->next;
				Node* nodetoDel = curr->next;
				curr->next = nextX;
				nodetoDel->next = NULL;
				delete nodetoDel;
			}
			else {
				curr = curr->next;
			}
		}
	}
	return head;
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
	Node* newHead = RemoveFromSorted(head);

	PrintList(newHead);

	return 0;
}