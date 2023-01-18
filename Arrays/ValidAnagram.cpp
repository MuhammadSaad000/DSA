#include<iostream>
using namespace std;

#define CharCount 128

// Leetcode 242 : Valid Anagram
// Problem Link : https://leetcode.com/problems/valid-anagram

bool isAnagram(string s1, string s2);


bool isAnagram(string s, string t) {
    if (s.length() != t.length())
        return false;

    // storing the no of count in arrays
    int count1[CharCount] = { 0 };
    int count2[CharCount] = { 0 };

    for (int i = 0; i < s.length(); i++) {
        count1[int(s[i])]++;
        count2[int(t[i])]++;
    }

    // comparing two arrays 
    for (int j = 0; j < CharCount; j++) {
        if (count1[j] != count2[j])
            return false;
    }
    return true;
}


int main()
{
	cout << "Anagram or not  " ;
	bool ans = isAnagram("car", "tar");
	cout << ans;

	return 0;

}