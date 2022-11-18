#include<iostream>
using namespace std;

//File Completed November 18,2022.
//Given unsorted array from 1 to 50 but one number is missing find missing number.

int main()
{
	//number 22 is missing in below unsorted array
	int arr[50] = { 17,18,25,26,21,1,2,3,4,5,6,12,13,14,15,16,23,27,28,19,20,
		24,36,37,38,39,29,30,31,42,32,33,34,35,43,44,40,41,47,48,49,50,45,46,7,8,9,10,11};

	int n = 50;
	int total = (n * (n + 1)) / 2;
	for (int i = 0; i < 50; i++) {
		total = total - arr[i];
	}

	cout << total << endl;

}
