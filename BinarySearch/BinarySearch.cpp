#include<iostream>
using namespace std;


//File created on October 5,2022
// Problems discussed 
//	1- Binary search algorithm
//	2- Left and Right most occurence of element in array 
//  3- Total no of occurences of single element in array
//  4- Finding Peak(maximum) in an array using Binary search


int BinarySearch(int arr[], int size, int key);
int FirstOcc(int arr[], int size, int key);
int LastOcc(int arr[], int size, int key);
int FindPeak(int arr[], int size);

int main()
{
	int arr[9] = { 1,3,4,4,4,5,11,13,17 };
	int ans  = BinarySearch(arr, 10, 11);
	
	int res = FirstOcc(arr, 9, 4);
	int res1 = LastOcc(arr, 9, 4);

	cout << "Left most occurence : " << res  << " Right most occurence : "  << '\t' << res1 << endl;

	cout << "Total no of occurences is : " << (res1 - res)+1 << endl;

	int data[5] = { 1,2,4,2,1 };
	cout << FindPeak(data,5) << endl;



	return 0;
}


int BinarySearch(int arr[], int size, int key) {

	int start = 0;
	int end = size - 1;

	int mid = start + (end-start) / 2;


	while (start <= end) {
		if (arr[mid] == key) {
			return mid;
		}
		else if (key>arr[mid]) {
			start = mid + 1;
		}
		else if (key < arr[mid]) {
			end = mid - 1;
		}
		mid = start + (end-start) / 2;
	}

	return -1;
}

int FirstOcc(int arr[], int size, int key) {
	int start = 0;
	int end = size - 1;
	int mid = start + (end - start) / 2;

	int ans = -1;

	while (start <= end) {
		if (key == arr[mid]) {
			ans = mid;
			end = mid - 1;
		}
		else if (key > arr[mid]) {			//search in right part
			start = mid + 1;
		}
		else if (key < arr[mid]) {			//search the left part
			end = mid - 1;
		}

		mid = start + (end - start) / 2;
	}
	return ans;

}

int LastOcc(int arr[], int size, int key) {
	int start = 0;
	int end = size - 1;
	int mid = start + (end - start) / 2;

	int ans = -1;

	while (start <= end) {
		if (key == arr[mid]) {
			ans = mid;
			start = mid + 1;
		}
		else if (key > arr[mid]) {			//search in right part
			start = mid + 1;
		}
		else if (key < arr[mid]) {			//search the left part
			end = mid - 1;
		}

		mid = start + (end - start) / 2;
	}
	return ans;

}

int FindPeak(int arr[], int size) {

	int start = 0;
	int end = size - 1;
	int mid = start + (end - start) / 2;

	while (start <= end)
	{
		if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
			return mid;
		}
		else if (arr[mid] < arr[mid + 1]) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
		mid = start + (end - start) / 2;
	}
	return -1;

}