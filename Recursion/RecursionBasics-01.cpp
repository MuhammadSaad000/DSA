#include<iostream>
using namespace std;

//File Completed on : October 22,2022.
//Topics Discussed : Recursion Basics 
//Problems solved : Factorial, PowerOfTwo , Print Counting using recursion
//Recursion: When a function calls itself in recursion is performed.
int Factorial(int);
int PowerOfTwo(int);
void PrintNums(int);


int main()
{
	cout << Factorial(5) << endl;
	cout << PowerOfTwo(4) << endl;
	PrintNums(6);
	return 0;
}

//factorial using recursion
int Factorial(int n)
{
	//base case:where to stop recursion
	if (n == 0)
		return 1;
	//recursive relation: Relation between usecase
	//smaller usecase/problem : fact(n-1)
	
	else
		return n * Factorial(n - 1);
}

//Power of two
int PowerOfTwo(int n)
{
	if (n == 0)
		return 1;
	else
		return 2 * PowerOfTwo(n - 1);
}


void PrintNums(int n)
{
	if (n == 0)
		return;
	else
		PrintNums(n - 1);
		cout << n << '\t';
}
