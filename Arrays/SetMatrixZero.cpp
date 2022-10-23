#include<iostream>
#include<vector>
using namespace std;

//problems discussed : Set Matrix Zero
//Leetcode 73 : https://leetcode.com/problems/set-matrix-zeroes/


void SetMatrixZero(int arr[][4], int r, int c);
void NullifyRow(int arr[][4], int c, int rowIdx);
void NullifyCol(int arr[][4], int r, int colIdx);



int main()
{
	int arr[3][4] = { 0,1,2,0,3,4,5,2,1,3,1,5 };
	SetMatrixZero(arr, 3, 4);

	return 0;
}

void SetMatrixZero(int arr[][4], int r, int c)
{
	vector<pair<int, int>> v;
	int rX = -1, cX = -1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 0) {
				rX = i;
				cX = j;
				//storing location of zero indices in pairs array
				pair<int, int> temp;
				temp.first = rX;
				temp.second = cX;
				v.push_back(temp);
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		NullifyRow(arr, 4, v[i].first);
		NullifyCol(arr, 3, v[i].second);
	}


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}

void NullifyRow(int arr[][4], int c, int rowIdx)
{
	for (int j = 0; j < c; j++) {
		arr[rowIdx][j] = 0;
	}
}


void NullifyCol(int arr[][4], int r, int colIdx)
{
	for (int i = 0; i < r; i++) {
		arr[i][colIdx] = 0;
	}
}