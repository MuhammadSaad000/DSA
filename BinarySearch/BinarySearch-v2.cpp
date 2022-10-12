#include<iostream>
using namespace std;

//Author : Muhammad Saad File Completed : October 12, 2022
//Binary Search problems discussed
// 1- Find Pivot index	2- Search key/element in array 3- Find SquareRoot of a number using Binary Search



int FindPivot(int arr[], int size);
int SearchKey(int arr[], int size, int key);
int SquareRoot(int num);

int main()
{
	int arr[5] = { 6,7,9,11,1 };
	int res = 0;
	res = FindPivot(arr, 5);
	cout << "Pivot is at index : " <<  res << endl;
	res = SearchKey(arr, 5, 9);
	cout << "Element found at Index : " << res <<endl;
	res = SquareRoot(189);
	cout << res << endl;

	return 0;
}


int FindPivot(int arr[], int size)
{
	int start = 0, end = size - 1;
	int mid = start + (end - start) / 2;

	while (start < end) {
		if (arr[0] <= arr[mid]) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
		mid = start + (end - start) / 2;
	}

	return start;
}

int SearchKey(int arr[], int size, int key)
{
	int start = 0, end = size - 1;
	int mid = start + (end - start) / 2;
	
	while (start < end) {
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
		
		mid = start + (end - start) / 2;
	}

	return -1;
}

int SquareRoot(int num)
{
	int* arr = new int[num] ,ans = -1;
	for (int i = 0; i < num; i++) {
		arr[i] = i;
	}
		
	int start = 0, end = num ;
	int mid = start + (end - start) / 2;

	while (start <= end) {
		int square = mid * mid;
		if (square == num)
		{
			return mid;
		}
		else if (square > num ) {
			end = mid - 1;
		}
		else if (square < num){	//possible answer
			ans = mid;
			start = mid + 1;
		}
		mid = start + (end - start) / 2;
	}
	return ans;
}
