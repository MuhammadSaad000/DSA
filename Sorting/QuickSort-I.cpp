#include<iostream>
using namespace std;

// Problem Solved : Quick Sort 
// Avg. Best O(nlgn)	worst O(n*n)

void QuickSort(int arr[], int start, int end);
int Partition(int arr[], int start, int end);


void QuickSort(int arr[], int start, int end)
{
	// base case 
	if (start >= end)	// there is one or no element array is sorted 
		return;

	// partition 
	int idx = Partition(arr, start, end);

	QuickSort(arr, start, idx - 1);
	QuickSort(arr, idx + 1, end);

}

int Partition(int arr[], int start, int end)
{
	int pivot = arr[start];
	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot) {
			count++;
		}
	}
	int pivotIdx = start + count;
	swap(arr[pivotIdx], arr[start]);

	int i = start, j = end;
	while (i<pivotIdx && j > pivotIdx)
	{
		while (arr[i] < pivot)
			i++;

		while (arr[j] > pivot)
			j--;

		// we will reach this condition if element greater than pivot 
		// is on left & less than pivot is on right
		// if arr[i] > pivot and arr[j] < pivot 
		// just checking i and j lies in the boundart
		if (i < pivotIdx && j > pivotIdx)
			swap(arr[i++], arr[j--]);
	}
	return pivotIdx;
}


int main()
{
	int arr[7] = { 12,18,9,19,2,5,7 };

	QuickSort(arr, 0, 6);
	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}