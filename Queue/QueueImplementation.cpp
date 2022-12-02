#include<iostream>
using namespace std;

class Queue
{
public:
	int* arr;
	int front;	//two pointers approach to track front and back elements of queue
	int rear;	
	int size;
	 
	Queue(int size)
	{
		this->size = size;
		arr = new int[size];
		front = 0;
		rear = 0;
	}

	void Enqueue(int n)
	{
		if (!isFull()) {
			arr[rear] = n;
			rear++;
		}
		else
			cout << "Queue is full " << endl;
	}

	int Dequeue()
	{
		if (!isEmpty()) {
			int ans = arr[front];
			arr[front] = -1;
			front++;
			if (front == rear) {
				front = 0;
				rear = 0;
			}
			return ans;
		}
		else
			return -1;
	}

	bool isEmpty()
	{
		return front == rear;
	}

	bool isFull()
	{
		return rear == size;
	}

	int Size(){
		return rear - front;
	}

};





int main()
{
	Queue q1(5);
	cout << "Is queue empty? " << q1.isEmpty() << endl;
	q1.Enqueue(12);
	q1.Enqueue(22);
	cout << "What is the size of queue now? " << q1.Size() << endl;
	q1.Enqueue(11);
	q1.Enqueue(21);

	cout << "Is queue full?  " << q1.isFull() << endl;
	q1.Enqueue(5);


	int ans = q1.Dequeue();	//delete first/front element from queue
	cout << "Pop front " << ans << endl;
	cout << "Now which entry is being entertained? " << q1.front << endl;
	q1.Dequeue();
	cout << "Pop front " << ans << endl;
	cout << "Size of queue after deleting 2 elements : " << q1.Size() << endl;



	return 0;
}