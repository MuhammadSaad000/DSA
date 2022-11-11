#include<iostream>
#include<stack>
using namespace std;

//File completed on : November 11,2022.
// Problems Discussed : Two Stack / Implement two stacks in one array
//https://www.codingninjas.com/codestudio/problems/two-stacks_983634?leftPanelTab=0

class TwoStack {
private:
	int size;
	int* arr;
	int top1;
	int top2;
public:
	TwoStack(int s)
	{
		this->size = s;
		top1 = -1;
		top2 = size;
		arr = new int[s];
	}

	//pushing into stack one
	void Push1(int value)
	{
		if (top2 - top1 > 1) {
			top1++;
			arr[top1] = value;
		}
		else {
			cout << "Stack overflow" << endl;
		}
	}

	void Push2(int value)
	{
		if (top2 - top1 > 1) {
			top2--;
			arr[top2] = value;
		}
		else {
			cout << "Stack overflow" << endl;
		}
	}

	int Pop1() {
		if (top1 >= 0) //at least one element is present in stack
		{
			return arr[top1];
			top1--;
		}
		else {
			return -1;
		}
	}

	int Pop2() {
		if (top2 < size) {
			return arr[top2];
			top2++;
		}
		else
			return -1;
	}

};


int main()
{
	TwoStack st(7);
	st.Push1(3);
	st.Push2(5);
	st.Push1(1);
	st.Push1(4);
	st.Push2(2);
	st.Push2(11);
	st.Push2(10);

	//last element of stack1 & stack 2 will be printed
	cout << st.Pop1() << endl;
	cout << st.Pop2() << endl;



	return 0;
}