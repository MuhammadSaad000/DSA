#include<iostream>
using namespace std;
 
//Selection Sort	-- O(n^2)
//File completed on October 14,2022.

void SelectionSort(int arr[], int n);


int main()
{
	cout << "Hello world " << endl;
	int arr[5] = { 7,12,18,4,16 }, n = 5;
	cout << "Selection sort : " << endl;
	SelectionSort(arr, 5);
	

	return 0;
}

void SelectionSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[minIndex] > arr[j]) {
				minIndex = j;
			}
		}
		swap(arr[minIndex], arr[i]);
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}