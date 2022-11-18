#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//File completed on : November 18,2022.
//Problems discussed : Next smaller element in stack

vector<int> NextSmallerElement(vector<int>&,int);


int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);

	v = NextSmallerElement(v, 4) ;
	for (int i = 0; i < 4; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}


vector<int> NextSmallerElement(vector<int>& arr,int n)
{
	stack<int> st;
	st.push(-1);
	vector<int> ans(n);

	for (int i = n - 1; i >= 0; i--) 
	{
		int curr = arr[i];
		while (st.top() >= curr) {
			st.pop();
		}
		ans[i] = st.top();
		st.push(curr);
	}
	return ans;
}
