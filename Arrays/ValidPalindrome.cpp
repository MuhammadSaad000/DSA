#include<iostream>
using namespace std;

// Problems : LeetCode-125 Valid Palindrome 
// https://leetcode.com/problems/valid-palindrome/
// October 23,2022

bool ValidPalindrome(string);

int main()
{
	cout << ValidPalindrome("a man a plan a canal panama") << endl;
	return 0;
}

bool ValidPalindrome(string s) 
{
	int left = 0, right = s.length() - 1;

	while (left < right)
	{
		if (s[left] != s[right]) {
			return false;
		}
		left++;
		right++;
	}
	return true;
}
