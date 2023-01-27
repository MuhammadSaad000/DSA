#include<iostream>
using namespace std;

// Problem Solved : check if number is even or odd without modulus and if-else operator 
// Problem Link : https://www.geeksforgeeks.org/3-ways-check-number-odd-even-without-using-modulus-operator-set-2-can-merge-httpswww-geeksforgeeks-orgcheck-whether-given-number-even-odd/

bool isEven(int num)
{
	// first divide then multiply by 2
	int y = (num / 2) * 2;
	return (y == num);
}

bool checkEven(int num)
{
	bool isEven = true;
	// for initial value of i=1 isEven is False then for 2 its true
	for (int i = 1; i <= num; i++)
		isEven = !isEven;
	return isEven;
}

int main()
{
	cout << checkEven(12) << endl;

	cout << isEven(11) << endl;

	return 0;
}