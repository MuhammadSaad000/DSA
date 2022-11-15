#include<iostream>
#include<stack>
using namespace std;

//File Completed on : November 15,2022.
//Problem solved : https://www.geeksforgeeks.org/reverse-the-sentence-using-stack/

string ReverseWords(string& s);

int main()
{
	string s = "I love to code";
	s = ReverseWords(s);
	cout << s << endl;
	return 0;
}

string ReverseWords(string& s)
{
	stack<string> st;
	string temp = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ') {
			st.push(temp);
			temp = "";	//making temp empty for new word
		}	
		else{
			temp = temp + s[i];	//adding letters to make word
		}
	}
	st.push(temp);
	
	string ans = "";
	while (!st.empty()) {
		string top = st.top();
		ans = ans + top + " ";	//adding space between words 
		st.pop();	//deleting the uppermost word in stack
	}

	cout << ans.length() << endl;

 	return ans;
}
