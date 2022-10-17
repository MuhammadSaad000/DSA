#include<iostream>
#include<vector>
using namespace std;

//File Completed on : October 17, 2022.
// 4 - Rotate an array by k distance
// 5 - Check if array is rotated and sorted 
// 6 - Sum two Arrays 


void RotateArray(int arr[], int size, int k);
bool CheckRotatedAndSorted(int arr[], int n);
vector<int> SumTwoArrays(vector<int>&,int n1,vector<int>&,int n2);

int main()
{
	int arr[8] = { 1,2,3,4,5,6,7,8 };
	RotateArray(arr, 8, 3);
	int arr2[5] = { 1,2,3,4,5};
	cout << endl;

	cout << CheckRotatedAndSorted(arr2, 5);

	cout << "Sum of two arrays : " << endl;
	vector<int>v1,v2;
	v1.push_back(2);
	v1.push_back(7);
	v1.push_back(3);

	v2.push_back(4);
	v2.push_back(6);
	v2.push_back(9);

	vector<int> ans = SumTwoArrays(v1, 3,v2,3);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\t';
	}
	cout << endl;


	return 0;
}

void RotateArray(int arr[], int size, int k) {
	int* temp = new int[size];
	
	for (int i = 0; i < size; i++) {
		temp[(i + k) % size] = arr[i];
	}

	for (int i = 0; i < size; i++) {
		cout << temp[i] << '\t';
	}

	return;
}


bool CheckRotatedAndSorted(int arr[], int n)
{
	int count = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] > arr[i]  ) {
			count++;
		}
	}

	if (arr[n - 1] < arr[0]) {
		count++;
	}

	if (count <= 1)
		return true;
	else
		return false;
}

vector<int> SumTwoArrays(vector<int>& v1, int n1, vector<int>&v2, int n2)
{
	int i = n1 - 1;
	int j = n2 - 1;
	int carry = 0;

	vector<int> ans;
	while (i >= 0 && j >= 0) {
		int val1 = v1[i];
		int val2 = v2[j];
		int sum = val1 + val2 + carry;

		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		i--;
		j--;
	}


	//first case add on left side
	while (i >= 0) {
		int sum = v1[i] + carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		i--;
	}


	//2nd case add on right side
	while (j >= 0) {
		int sum = v2[j] + carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		j--;
	}

	//3rd case
	while (carry != 0) {
		int sum = carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
	}
	
	reverse(ans.begin(), ans.end());
	return ans;
}

