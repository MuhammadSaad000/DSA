#include<iostream>
using namespace std;

//CTCI Ch-01 Arrays & Strings Solved First two problems 
//File completed on : October 14,2022

bool isUnique(string s);
bool checkPermutation(string s1, string s2);
void swap(string&, string&);
string sortString(string&);

int main()
{
	bool ans = checkPermutation("nisp", "pins");
	cout << ans << endl;
	ans = isUnique("spinner");
	cout << ans << endl;


	return 0;
}

bool isUnique(string s)
{
	int ascii = -1;
	if (s.length() > 128) {
		return false;
	}


	bool* charCountArr = new bool[128];

	for (int i = 0; i < s.length(); i++)
	{
		ascii = int(s[i]);
		if (charCountArr[ascii] == true) {
			return false;
		}
		else {
			charCountArr[ascii] = true;
		}
	}
	return true;
}

bool checkPermutation(string s1, string s2)
{
	if (s1.size() != s2.size())
		return false;
	else
	{
		//sorting the strings brute force 
		s1 = sortString(s1);
		s2 = sortString(s2);

		if (s1._Equal(s2)) {
			return true;
		}
		else {
			return false;
		}

	}
}

void swap(string& a, string& b)
{
	string temp = a;
	a = b;
	b = temp;
}

string sortString(string &s)
{
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < s.length(); j++) {
			if (s[j] > s[j + 1]) {
				swap(s[j], s[j + 1]);
			}
		}
	}
	return s;
}