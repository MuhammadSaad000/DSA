#include<iostream>
#include<stack>
using namespace std;

//File completed on November 14,2022.
//https://www.codingninjas.com/codestudio/problem-details/redundant-brackets_975473
bool RedundantBrackets(string& s);

int main()
{
	string s = "((a)*b)";
	cout << RedundantBrackets(s) << endl;
	return 0;
}

bool RedundantBrackets(string& s)
{
	stack<char> st;
	bool isRedundant = false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			isRedundant = true;
			while (st.top() != '(') {
				char tmp = st.top();
				if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/') {
					isRedundant = false;
				}
				st.pop();
			}
			if (isRedundant == true)
				return true;
			st.pop();
		}
	}
	return false;
}
