#include<iostream>
#include<stack>
using namespace std;

//Problem Solved
//Leetcode 921 : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
//File completed on : Nov 14,2022.

int MinBrackets(string& s);
bool MatchBrackets(char& a, char& b);


int main()
{
	string s = "())((";
	int ans = MinBrackets(s);
	cout << ans;
	return 0;
}

int MinBrackets(string& s)
{
	int i = 0, count = 0;
	stack<char>st;

	while (i < s.length()){
		if (s[i] == '(') {
			st.push(s[i]);
			count++;
		}
		else if (s[i] == ')' && !st.empty()) {
			if (MatchBrackets(s[i], st.top()))
			{
				st.pop();
				count = count - 1;
			}
		}
		else if (s[i] == ')' && st.empty()) {
			count = count + 1;
		}
		i++;
	}
	return count;
}

bool MatchBrackets(char& a, char& b)
{
	if (a == ')' && b == '(')
		return true;
	else
		return false;
}