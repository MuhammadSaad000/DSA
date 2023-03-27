#include<iostream>
#include<set>
using namespace std;

// Problem Solved : LeetCode 3 -Longest Substring Without Repeating Characters
// DS Involved : Strings, Approach used : 2 pointers problem 
// Problem link : https://leetcode.com/problems/longest-substring-without-repeating-characters

int substringWithoutRepeating(string s)
{
	int start = -1, max_len = 0;
	int i = 0, j = 0;

	set<char> my_set;
	while (j < s.length()) {
		// if character not exists in set
		if (my_set.find(s[j]) == my_set.end()){
			my_set.insert(s[j]);
			j += 1;
			max_len = max(max_len, j - i);
		}
		// if character exists in set
		else {
			my_set.erase(s[i]);
			i += 1;
		}
	}
	return max_len;
}



int main()
{
	cout << substringWithoutRepeating("bbbbb") << endl;

	cout << substringWithoutRepeating("pwwkew") << endl;
	return 0;
}