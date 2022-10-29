#include<iostream>
using namespace std;

//Print , Reverse String using recursion
//Check If string is Palindrome , Find Power of number 
//Nested Recursion : Bubble Sort using recursion
void PrintString(string& str, int i);
void ReverseString(string& s,int i,int j);	//i-> Starting Index j-> Ending Index
bool CheckPalindrome(string& s, int i, int j); //i-> Starting Index j-> Ending Index
int Power(int n, int p);
void BubbleSort(int arr[], int n);

int main()
{
	string s = "lambda";
	ReverseString(s, 0, s.length() - 1);
	PrintString(s,s.length());
	
	cout << endl;
	cout << CheckPalindrome(s, 0, s.length() - 1) << endl;
	cout << Power(4, 6) << endl;

	int arr[5] = { 12,4,6,7,21 };
	BubbleSort(arr, 5);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << endl;
	}

 	return 0;
}

void ReverseString(string& s,int i,int j)
{
	//base case
	if (i > j)
		return;
	else
	{
		swap(s[i], s[j]);
		//updating pointers 
		i++;
		j--;
		//recursive call
		ReverseString(s,i,j);
	}
}

void PrintString(string& str,int i)
{
	if (str[i] != '\n')
		cout << str;
	else
	{
		i++;
		PrintString(str, i);
	}
}

bool CheckPalindrome(string& s, int i, int j)
{
	if (i > j)
		return true;

	if (s[i] != s[j])
		return false;
	else
	{
		i++;
		j--;
		return CheckPalindrome(s, i, j);
	}
}


int Power(int n, int p)
{
	if (p == 0)
		return 1;	// n ^ 0 = 1

	if (p == 1)
		return n * p;	//2 ^ 1 = 2
	else if (p % 2 == 0) {
		p = p / 2;	
		return Power(n, p) * Power(n,p);
	}
	else if (p % 2 == 1) {
		p = p / 2;
		return n * Power(n, p) * Power(n,p);
	}
}


void BubbleSort(int arr[], int n)
{
	if (n == 0 || n == 1)
		return;

	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			swap(arr[i], arr[i + 1]);
	}
	BubbleSort(arr, n - 1);
}
