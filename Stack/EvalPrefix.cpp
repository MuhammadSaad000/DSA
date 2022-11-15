#include<iostream>
#include<stack>
using namespace std;


//File Completed on November 15,2022.
//Problem Solved : https://www.geeksforgeeks.org/evaluation-prefix-expressions/
//Evaluate Prefix Expression

int EvalPrefix(string &s);
bool isNumeral(char& ch);
bool isOperator(char& ch);
int PerformOperation(int&, int&, char&);


int main()
{
	string s = "-+7*45+20";
	int res = EvalPrefix(s);
	cout << res << endl;
	return 0;
}


int EvalPrefix(string& s)
{
	stack<int> st;
	int i = s.length(),ans = 0;
	while (i >= 0) {
		if (isNumeral(s[i])) {
			int temp = s[i] - '0';
			st.push(temp);
		}
		else if (isOperator(s[i])) {
			int op1 = st.top();
			st.pop();
			int op2 = st.top();
			st.pop();
			ans = PerformOperation(op1, op2, s[i]);
			st.push(ans);
		}
		i--;
	}
	int x = st.top();
	return x;
}

bool isNumeral(char &ch)
{
	if (ch >= '0' && ch <= '9')
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

int PerformOperation(int& a, int& b, char& op)
{
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else if (op == '*')
		return a * b;
	else if (op == '/')
		return a / b;
	else
		return -1;
}