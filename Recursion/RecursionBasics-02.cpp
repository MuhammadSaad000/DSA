#include<iostream>
using namespace std;

// Problems : Recursion PrintNumbers, nth Fibonacci Number
// Climb Stairs : https://leetcode.com/problems/climbing-stairs/
// Say Digits : Convert number into its individual digits
// File Completed On : October 23,2022


void PrintNums(int);
int FibonacciNum(int);
//to reach nth stair you can only climb one or two steps at a time find how many distinct ways exists?
int ClimbStairs(int); 
void SayDigits(int);	//turn number into its digits

//Fibonacci Number using For loop
int Fib(int n)
{
	int n1 = 0, n2 = 1,ans = 0;
	for (int i = 2; i < n; i++) {
		ans = n1 + n2;
		n1 = n2;
		n2 = ans;
	}
	return ans;
}



int main()
{
	PrintNums(4);
	cout << "Fibonacci Num : " ;
	cout << FibonacciNum(5) << endl;
	cout <<  "Distinct ways to climb stairs : " << ClimbStairs(5) << endl;
	SayDigits(321);
	return 0;
}

void PrintNums(int n)
{
	if (n == 0)
		return;
	else {
		cout << (n) << endl;	//processing input or performing I/O 
		PrintNums(n - 1);	//tail recursion
	}
}

//Printing nth Fibonacci number
int FibonacciNum(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return FibonacciNum(n - 1) + FibonacciNum(n - 2);
}

//Climb Stairs LeetCode 73
int ClimbStairs(int n)
{
	if (n < 0)
		return 0;
	//dont use else-if here otherwise you will get error
	if (n == 0)
		return 1;
	else
		return ClimbStairs(n - 1) + ClimbStairs(n - 2);
}

//
void SayDigits(int n)
{
	if (n == 0)
		return;
	else
	{	
		int x = n % 10;
		cout << x << " ";
		n = n / 10;
		SayDigits(n);
	}
}
