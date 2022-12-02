#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> ReverseQueue(queue<int>);


int main()
{
	queue<int> q1;
	q1.push(4);
	q1.push(1);
	q1.push(3);
	q1.push(2);

	ReverseQueue(q1);

	return 0;

}


queue<int> ReverseQueue(queue<int> que)
{
	stack<int> st;
	while (!que.empty()) {
		int element = que.front();
		que.pop();
		st.push(element);
	}

	while (!st.empty()) {
		int element = st.top();
		st.pop();
		que.push(element);
	}

	while (!que.empty()) {
		cout << que.front() << '\t';
		que.pop();
	}
	cout << endl;


	return que;
}