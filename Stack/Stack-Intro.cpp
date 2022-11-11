#include<iostream>
using namespace std;

//File Completed on : November 11,2022.
//Stack Data Structure

class Stack
{
private:
	int* arr;
	int top;
	int size;	//size of stack

	//Functions 
	
public:
	Stack(int size) {
		top = -1;	//when stack will be created no element will be there
		this->size = size;
		arr = new int[size]; //dynamically allocating memory for stack
	}
	void Push(int value);
	void Pop();
	int Peak();	
	bool IsEmpty();


};

void Stack::Push(int value)
{
	if (size - top > 1){	//top represent the index of most upper element in stack(array)
		arr[top] = value;
		top++;
	}
	else {
		cout << "Stack Overflow " << endl;
	}
}

void Stack::Pop()
{
	if ( top >= 0 ) {
		//if stack is full top will be (size + 1) hence arr[top] will give garbarge value
		cout << "Element to be deleted is : " << arr[top - 1] << endl;	
		top--;
	}
	else {
		cout << "No element is present in stack " << endl;
	}
}

int Stack::Peak()
{
	if (!IsEmpty())
		return arr[top - 1];
	else
	{
		cout << "No element in stack " << endl;
		return -1;
	}
}

bool Stack::IsEmpty() 
{
	if (top == -1)
		return true;
	else
		return false;
}


int main()
{

	Stack st(5);
	st.Push(4);
	st.Push(11);
	st.Push(20);
	st.Push(21);
	st.Push(16);

	st.Pop();
	st.Pop();
	

	cout << st.IsEmpty() ? "Yes" : "No" ;
	cout << endl;
	cout << "Element at the top of stack is : " << st.Peak() << endl;


	return 0;
}