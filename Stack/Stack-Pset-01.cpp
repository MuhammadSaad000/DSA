#include<iostream>
#include<stack>
using namespace std;


//File Completed on : Nov 12,2022. -- Stack
// Problems discussed.
//Valid Parentheses: https://leetcode.com/problems/valid-parentheses/description/
//Reverse Stack using recursion, Insert Element at the bottom of stack


string ReverseString(string &s);
bool ValidParentheses(string &s);
bool MatchBrackets(char& a, char& b);	//utility function
void InsertAtBottom(stack<int>& st,int x);
void ReverseStack(stack<int>&);	

int main()
{

	string s = "tello";
	s = ReverseString(s);
	cout << s << endl;
	string z = "()";
	bool ans = ValidParentheses(z);
	cout << ans << endl;
	stack<int> st;
	st.push(1);
	st.push(3);
	st.push(4);
	st.push(2);
	ReverseStack(st);
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;

	return 0;

}

string ReverseString(string& s)
{
	string ans = "";
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		st.push(s[i]);	//populating stack with characters
	}
	while (!st.empty()) {
		char ch = st.top();	//pop last character out of stack
		ans.push_back(ch);
		st.pop();	//removing last element from stack
	}
	return ans;
}


bool ValidParentheses(string &s)
{
	stack<char> st;

	int i = 0;
	while (i < s.length()) {
		if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
			st.push(s[i]);
		}
		else
		{
			if (!st.empty())
			{
				char tmp = st.top();
				if (s[i] == ']' || s[i] == '}' || s[i] == ')') {
					if (MatchBrackets(s[i], tmp)) {
						st.pop();
					}
					else
						return false;
				}
			}
			else
				return false;
		}
		i++;
	}
	if (st.empty())
		return true;
	else
		return false;
}

void InsertAtBottom(stack<int>& st, int x)
{
	if (st.empty())
	{
		st.push(x); 
		return;
	}
	int top = st.top();
	st.pop();
	InsertAtBottom(st, x);
	st.push(top);
}




void ReverseStack(stack<int>& st)
{
	if (st.empty())
		return;

	int x = st.top();
	st.pop();
	ReverseStack(st);
	InsertAtBottom(st, x);
}


bool MatchBrackets(char &a, char &b) {
	if (a == ')' && b == '(')
		return true;
	else if (a == '}' && b == '{')
		return true;
	else if (a == ']' && b == '[')
		return true;
	else 
		return false;
}