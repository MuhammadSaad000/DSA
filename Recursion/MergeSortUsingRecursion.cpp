#include<iostream>
using namespace std;

void Merge(int*arr,int s,int e);
void MergeSort(int* arr, int s, int e);


int main()
{
	int arr[7] = { 2,4,1,9,2,13,11 };
	MergeSort(arr, 0, 6);

	for (int i = 0; i < 7; i++) {
		cout << arr[i] << '\t';
	}


	return 0;
}


void Merge(int* arr, int s, int e)
{
	int mid = s + (e - s) / 2;

	int len1 = mid - s + 1;
	int len2 = e - mid;

	int* first = new int[len1];
	int* second = new int[len2];

	//mainArray = new array which contains merged sorted arrays 
	int mainArrayIndex = s;	//s==0 
	//copying values 
	for (int i = 0; i < len1; i++) {
		first[i] = arr[mainArrayIndex++];
	}

	for (int i = 0; i < len2; i++) {
		second[i] = arr[mainArrayIndex++];
	}

	//merging arrays 
	int idx1 = 0;
	int idx2 = 0;
	mainArrayIndex = s;
	while (idx1 < len1 && idx2 < len2) {
		if (first[idx1] < second[idx2]) {
			arr[mainArrayIndex] = first[idx1];
			idx1++;	//updation of two pointers 
			mainArrayIndex++;
		}
		else {
				arr[mainArrayIndex] = second[idx2];
				idx2++;	//updation of two pointers 
				mainArrayIndex++;
		}
		
	}

	while (idx1 < len1) {
		arr[mainArrayIndex] = first[idx1];
		mainArrayIndex++;
		idx1++;
	}

	while (idx2 < len2) {
		arr[mainArrayIndex] = second[idx2];
		mainArrayIndex++;
		idx2++;
	}

	//free memory
	delete[] first;
	delete[] second;

}

void MergeSort(int* arr, int s, int e)
{
	if (s >= e)
		return;

	int mid = s + (e - s) / 2;


	//sort left array
	MergeSort(arr, s, mid);


	//sort right array
	MergeSort(arr, mid + 1, e);

	//merging the sorted arrays 
	Merge(arr, s, e);
}
