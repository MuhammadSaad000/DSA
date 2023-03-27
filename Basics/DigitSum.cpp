#include<iostream>
using namespace std;

int DigitSum(int);

int DigitSum(int num)
{
	int sum = 0,digit;
	while (num > 0)
	{
		digit = num % 10;
		sum = sum + digit;
		num = num / 10;
	}
	return sum;
}


int main()
{
	cout << DigitSum(11) << endl;
	return 0;
}