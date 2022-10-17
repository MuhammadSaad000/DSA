#include<iostream>
using namespace std;

// Problems discussed File Completed on : October 17,2022.
//1 - Reverse Array after given index
//2 - Merged Two Sorted Arrays 
//3 - Move Zeros to the right of the array

void ReverseArray(int arr[], int size,int index);
void MergeSortedArrays(int arr1[], int size1,int arr2[] ,int size2,int arr[]);
void MoveZeros(int arr[], int n);

int main()
{
	int arr[8] = { 4,5,1,3,2,7,6,9 };
	cout << "Reverse array is : " << endl;
	ReverseArray(arr, 8, 2);
	cout << "Merged Sorted array is : " << endl;
	int arr1[3] = { 1,4,5 };
	int arr2[5] = { 2,4,6,8,10 };
	int arr3[8] = { 0 };
	MergeSortedArrays(arr1, 3, arr2, 5,arr3);
	int arr4[8] = { 3,2,0,1,0,12,0,0 };
	MoveZeros(arr4, 8);

	return 0;
}

void ReverseArray(int arr[], int size,int index)
{
	int start = index + 1;
	int end = size - 1;
	int loopSize = (end - start) / 2;

	for (int i = 0; i < loopSize; i++) {
		swap(arr[start], arr[end]);
		start = start + 1;
		end = end - 1;
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}

void MergeSortedArrays(int arr1[], int size1, int arr2[], int size2,int arr3[])
{ 
	int i = 0, j = 0, k = 0;
	while (i < size1 && j < size2) {
		if (arr1[i] < arr2[j]) {
			arr3[k++] = arr1[i++];
		}
		else {
			arr3[k++] = arr2[j++];
		}

	}

	while (i < size1) {
		arr3[k++] = arr1[i++];
	}

	while (j < size2) {
		arr3[k++] = arr2[j++];
	}

	int size3 = size1 + size2;
	for (int i = 0; i < size3; i++) {
		cout << arr3[i] << '\t';
	}
	cout << endl << endl;
}

void MoveZeros(int arr[], int n)
{
	
	int nonZero = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) {
			swap(arr[i], arr[nonZero]);
			nonZero++;
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\t';
	}
	cout << endl;
}
