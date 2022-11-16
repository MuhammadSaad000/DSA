#include<iostream>
#include<stack>
using namespace std;


//File Completed on November 16,2022.
//Problem Solved : https://www.geeksforgeeks.org/stack-set-4-evaluation-postfix-expression/
//Evaluate Postfix Expression

int EvalPostfix(string &s);
bool isNumeral(char& ch);
bool isOperator(char& ch);
int PerformOperation(int&, int&, char&);


int main()
{
	string s = "46+2/5*7+";
	int res = EvalPostfix(s);
	cout << res << endl;
	return 0;
}


int EvalPostfix(string& s)
{
	stack<int> st;
	int i = 0,ans = 0;

	for (int i = 0; i <= s.length() ; i++) {
		if (isNumeral(s[i])) {
			int temp = s[i] - '0';
			st.push(temp);
		}
		else if (isOperator(s[i])) {
			//in case of postfix evaluation we will treat top value as second operand
			int op2 = st.top();
			st.pop();
			int op1 = st.top();
			st.pop();

			ans = PerformOperation(op1, op2, s[i]);
			st.push(ans);
		}
	}
	return st.top();
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