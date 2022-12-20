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

void InsertAtHead(Node*& head, int data);
void InsertAtMid(Node*& head, Node* tail, int position, int data);
void InsertAtTail(Node*& tail, int data);
void PrintList(Node*& head);
void DeleteAt(Node*& head, int position);
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

void InsertAtMid(Node*& head,Node* tail, int position, int data)
{
	Node* newNode = new Node(data);
	Node* temp = head;

	//handling position 1 
	int len = LengthOfList(head);
	if (position > len ) {
		cout << "Length of list is : " << len - 1 << endl;
	}

	else if (position == 1) {
		InsertAtHead(head,data);
		return;	//exit point
	}

	else if (temp->next == NULL ) {
		InsertAtTail(tail, data);
		return;
	}

	else  {
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
	else{
		Node* curr = head;
		Node* prev = NULL;
		int count = 1;
		while (count < position){
			prev = curr;
			curr = curr->next;
			count++;
		}
		prev->next = curr->next;
		curr->next = NULL;
		delete curr;
	}

}

int main()
{
	Node* n1 = new Node(4);
	cout << n1->data << endl;
	cout << n1->next << endl;

	Node* head = n1;
	PrintList(head);
	
	InsertAtHead(head, 5);
	PrintList(head);

	Node* tail = n1;
	InsertAtTail(tail, 6);
	PrintList(head);


	InsertAtMid(head,tail ,4, 11);
	PrintList(head);

	DeleteAt(head, 1);
	PrintList(head);


	return 0;
}