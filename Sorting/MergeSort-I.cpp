#include<iostream>
using namespace std;


/// Problems discussed : MergeSort FileCompleted ON: December 27,2022.
// Problem Link : https://leetcode.com/problems/sort-an-array/

void MergeSort(int*, int, int);
void Merge(int*, int, int);

//merge sort in arrays - O(nlog(n))

void MergeSort(int* arr, int start, int end)	//using two pointers approach
{
	//start and end are indexes starting and ending indexes of array 
	//base case 
	if (start >= end) {
		return;		//exit : whole array is traversed
	}
	int mid = start + ((end - start) / 2);
	//sorting first half of array
	MergeSort(arr, 0, mid);

	//sorting second half of array
	MergeSort(arr, mid + 1, end);

	//merge sorted arrays	
	Merge(arr, start, end);

}

// merging two sorted arrays 
void Merge(int* arr, int start, int end)
{
	int mid = (start + (end - start) / 2);
	int len1 = mid - start + 1;	//length of first part of main array 
	int len2 = end - mid;			// len2 = start + end - len1

	//allocating memory for new two arrays
	int* first = new int[len1];
	int* second = new int[len2];


	int mainIdx = start;	//stores main array index to track which elements are inserted in new arrays 
	// at first start = 0
	//copy values in first array
	for (int i = 0; i < len1; i++)
	{
		first[i] = arr[mainIdx];
		mainIdx++;
	}
	//after copying first half mainIdx will be at mid of main(input) array

	//copy values in second array
	for (int i = 0; i < len2; i++)
	{
		second[i] = arr[mainIdx];	
		mainIdx++;
	}

	//merging two sorted arrays 
	int idx1 = 0;	//first array index 
	int idx2 = 0;	//second array index

	mainIdx = start;		

	while (idx1 < len1 && idx2 < len2)
	{
		if (first[idx1] < second[idx2]) {	//if first is greater
			arr[mainIdx++] = first[idx1++];	//postfix increment to move to new index in next iteration of loop.
		}
		else {
			arr[mainIdx++] = second[idx2++];
		}
	}


	//checking if length of arrays are unequal
	while (idx1 < len1) {
		arr[mainIdx++] = first[idx1++];
	}

	while (idx2 < len2) {
		arr[mainIdx++] = second[idx2++];
	}

	delete[] first;
	delete[] second;
}


int main()
{
	int n = 9;
	int arr[9] = { 5,2,1,6,8,3,1,2,7 };


	MergeSort(arr, 0, n-1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}