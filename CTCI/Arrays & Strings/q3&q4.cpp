#include<iostream>
using namespace std;

//File completed on : October 22,2022
//CTCI Ch-01 Arrays & Strings Solved problems 3-4
//Urlify, Palindrome Permutation


void URLify(char* str, int len);
bool PalindromePerm(char* str,int len);

int main()
{
    char str[] = "Mr John Smith    ";                       //String with extended length ( true length + 2* spaces)
    URLify(str, 13);
	char arr[] = "tact ca oo";
	cout << PalindromePerm(arr, 12);

    return 0;
}


void URLify(char* str, int len)
{
    int spaceCount = 0;
    int i = 0, j = 0;
    for (i = 0; i < len; ++i) {
        if (str[i] == ' ') {
            spaceCount++;
        }
    }

    int extendedLen = len + 2 * spaceCount;
    i = extendedLen - 1;
    for (j = len - 1; j >= 0; --j) {
        if (str[j] != ' ') {
            str[i--] = str[j];
        }
        //indexing from end of string
        else {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
    }

    for (int i = 0; i < len; i++) {
        cout << str[i];
    }
    cout << endl ;

}

//this function is currently working for even permutations 
// if you know how to deal with odd permutations please make a PR I will merge it to main if plausible.


bool PalindromePerm(char* str, int len)
{
	//making array of 26 characters to hold character count
	int map[128] = { 0 }, count = 0;
	for (int i = 0; i < len; i++) {
		map[str[i]]++;
	}

	for (int i = 0; i < 128 && count <=1 ; i++) {
		count = count + map[i] % 2;
	}
	return count <= 1;

}
