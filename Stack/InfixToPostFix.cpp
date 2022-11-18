#include<iostream>
#include<stack>
using namespace std;


//File completed on : November 18,2022.
//Problems discussed 
//Infix to PostFix

string InfixToPostFix(string& s);
bool isOperand(char& ch); 
bool isOperator(char& ch);
int CheckPrecedence(char& op);


int main()
{
	string s = "(x-y)/z-k*d";
	cout << InfixToPostFix(s);
	return 0;
}

string InfixToPostFix(string& s)
{
	string ans = "";
	stack<char> st;
	
	for (int i = 0; i < s.length(); i++) 
	{
		if (isOperand(s[i])) {
			ans = ans + s[i];
		}
		else if (isOperator(s[i])) {
			while (!st.empty() && (CheckPrecedence(s[i]) <= CheckPrecedence(st.top()))) {
				char temp = st.top();
				st.pop();
				ans = ans + temp;
			}
			st.push(s[i]);
		}
	}

	while (!st.empty()) {
		char temp = st.top();
		st.pop();
		ans = ans + temp;
	}

	return ans;
}


bool isOperand(char& ch)
{
	if (ch >= 'a' && ch <= 'z')
		return true;
	else
		return false;
}

bool isOperator(char& ch)
{
	if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
		return true;
	else
		return false;
}

int CheckPrecedence(char& op)
{
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
	else 
		return 0;
}