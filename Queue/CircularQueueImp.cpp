#include<iostream>
using namespace std;

class CircularQueue
{
public:
	int* arr;
	int size;
	int front;
	int rear;
	CircularQueue(int size) 
	{
		this->size = size;
		arr = new int[size];
		front = -1;
		rear = -1;
	}

	bool isFull()
	{
		if ((front == 0 && rear == size - 1) || rear == ((front - 1) % (size - 1)))
			return true;
		else
			return false;
	}

	bool isEmpty() {
		return (rear == front == -1);
	}


	void Push(int data)
	{
		if (!isFull()) {
			if (front == -1) {		//queue is empty
				front = 0;
				rear = 0;
			}
			else if (rear == size - 1 && front != 0)	//front!=0 means queue isnt full in this case
				rear = 0;
			else
				rear++;
			arr[rear] = data;
		}
		else if (isFull()) {
			cout << "Queue is full " << endl;
		}

	}

	int Pop() 
	{
		if (front == -1)
		{
			cout << "Queue is empty " << endl;
			return -1;
		}
		
		else if (front == rear )	//single element is present in queue 
		{
			int ans = arr[front];
			arr[front] = -1;
			front = -1;
			rear = -1;
			return ans;
		}
		else if (front == size - 1)	//last element to delete 
		{	
			int ans = arr[front];
			arr[front] = -1;
			front = 0;	//maintain cyclic nature of queue 
			return ans;
		}
		else //normal case 
		{
			int ans = arr[front];
			arr[front] = -1;
			front++;
			return ans;
		}
		
	}
};





int main()
{
	CircularQueue cq(6);
	cq.Push(5);
	cq.Push(12);
	cq.Push(11);
	cq.Push(21);
	cq.Push(32);
	cq.Push(13);

	cout << cq.front << endl;
	cout << cq.rear << endl;

	//deleting 2 elements
	cout << "Deleting " << cq.Pop() << endl;	
	cout << "Deleting " << cq.Pop() << endl;

	//pushing 2 elements --> now they will be inserted at the start of queue
	cq.Push(3);
	cq.Push(23);

	cout << cq.rear << endl; 

	//deletion will continue from 3rd element 
	cout << "Deleting " << cq.Pop() << endl;

	return 0;
}