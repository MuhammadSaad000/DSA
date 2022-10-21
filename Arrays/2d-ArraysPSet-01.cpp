#include<iostream>
using namespace std;


//File Completed On : October 21,2022.
//Problems Discussed  
//Linear Search, Row , Column Sum in 2d array , Wave print form(up and down print)
//Print Elements of 2d-array in spiral form 



bool IsPresent(int arr[][4], int target, int r, int c);
void RowSum(int arr[][4], int r, int c);
void ColSum(int arr[][4], int r, int c);
int LargestRowSum(int arr[][4], int r, int c);
void WavePrintForm(int arr[][3], int r, int c);
void PrintSpiral(int arr[][3], int r, int c);

int main()
{

	int arr[2][4] = { 5,9,3,4,2,1,7,8 };
	cout << IsPresent(arr, 9, 2, 4) << endl;

	RowSum(arr, 2,4);
	ColSum(arr, 2, 4);
	cout << "Largest Row sum is : " <<  LargestRowSum(arr, 2, 4) << endl;

	int arrX[3][3] = { 1,2,3,4,5,6,7,8,9 };
	WavePrintForm(arrX,3,3);
	cout << endl;
	PrintSpiral(arrX, 3, 3);

	return 0;
}

bool IsPresent(int arr[][4], int target, int r, int c)
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == target) {
				cout << "element found at index " << i << " " << j << endl;
				return 1;
			}
		}
	}
	return 0;
}

void RowSum(int arr[][4], int r, int c) 
{
	for (int i = 0; i < r; i++) {
		int sum = 0;
		for (int j = 0; j < c; j++) {
			sum += arr[i][j];
		}
		cout << "Sum of " << i << "th row : " << sum << endl;
	}
}

void ColSum(int arr[][4], int r, int c) 
{	
	for (int i = 0; i < c; i++){
		int sum = 0;
		for (int j = 0; j < r; j++) {
			sum += arr[j][i];
		}
		cout << "Sum of " << i << "th column : " << sum << endl;
	}
}

int LargestRowSum(int arr[][4], int r, int c) {
	int largestSum = 0;
	for (int i = 0; i < r; i++) {
		int sum = 0;
		for (int j = 0; j < c; j++) {
			sum += arr[i][j];
			if (sum > largestSum)
				largestSum = sum ;
		}
	}
	return largestSum;
}

void WavePrintForm(int arr[][3], int r, int c)
{
	int j = 0;
	//print column wise
	for (int i = 0; i < c; i++)
	{
		if (i % 2 == 0) {
			for (int j = 0; j < r; j++) {
				cout << arr[j][i] << '\t';
			}
		}
		else {
			for (int j = r - 1; j >= 0; j-- ) {
				cout << arr[j][i] << '\t';
			}
		}
		
	}
}

void PrintSpiral(int arr[][3], int r, int c) 
{
	int total = r * c; //total 
	int count = 0;

	//indexes 
	int endRow = r - 1;
	int endCol = c - 1;
	int sRow = 0;
	int sCol = 0;

	while (count < total) {
		//starting row
		for (int i = sCol; i <= endCol; i++) {
			cout << arr[sRow][i] << '\t';
			count++;
		}
		sRow++;

		//ending col
		for (int i = sRow; i <= endRow; i++) {
			cout << arr[i][endCol] << '\t';
			count++;
		}
		endCol--;

		//ending row
		for (int i = endCol; i >= sCol; i--) {
			cout << arr[endRow][i] << '\t';
			count++;
		}
		endRow--;

		//starting col
		for (int i = endRow; i >= sRow; i--) {
			cout << arr[i][sCol] << '\t';
			count++;
		}
		sCol++;
	}
	
	cout << endl;

}
