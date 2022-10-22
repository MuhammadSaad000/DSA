#include<iostream>
using namespace std;

//File Completed on : October 22,2022, Problems discussed
//Binary Search on 2d array, Transpose of matrix
//Search in row & column wise sorted array 
bool BinarySearch(int arr[][3], int target, int r, int c);
bool Search(int arr[][4], int target, int r, int c);
void Transpose(int arr[][4], int r, int c);

int main()
{
	int arr[3][3] = { 1,3,5,7,10,11,13,17,20 };
	cout << BinarySearch(arr, 1, 3, 3) << endl;
	int arrX[4][4] = { 1,2,6,9,3,4,8,11,9,10,12,13,11,14,15,19 };
	cout << Search(arrX, 20, 4, 4) << endl;
	Transpose(arrX, 4, 4);
	return 0;
}

bool BinarySearch(int arr[][3], int target, int r, int c)
{
	int start = 0, end = (r * c) - 1;
	int mid = start + (end - start) / 2;

	while (start <= end)
	{
		int element = arr[mid / c][mid % c];
		if (element == target) {
			return 1;
		}
		else if (element < target) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
		mid = start + (end - start) / 2;
	}
	return 0;
}


bool Search(int arr[][4], int target, int r, int c)
{
	int rowIdx = 0;
	int colIdx = c - 1;

	//loop till last row and first column
	while (rowIdx < r && colIdx >= 0) {
		int element = arr[rowIdx][colIdx];
		if (element == target)
			return 1;
		//if element is lesser than target so target may exist in current column
		else if (element < target)
			rowIdx++;
		//if element is greater than target so target doesn't exist in current column move to previous column
		else if (element > target)
			colIdx--;
	}
	return 0;
}


//Transpose of 2d matrix
void Transpose(int arr[][4], int r, int c)
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
		{
			arr[i][j] = arr[j][i];
		}
	}

	for (int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
