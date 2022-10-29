#include<iostream>
using namespace std;

//Problems discussed Recursion October 29,2022.	
//FirstOccurence of element in array 
//LastOccurence of element in array 
//Print Array using recursion
//Reverse Array using recursion
//Find Magic Index of Array using recursion

int FirstOcc(int arr[], int n, int i, int key);
int LastOcc(int arr[], int n, int key);
void PrintArray(int arr[], int n);
void Reverse(int arr[],int i,int j);
int MagicIndex(int arr[], int s,int e);

int main()
{
	int arr[5] = { 0,2,0,3,4};
	cout << FirstOcc(arr, 5, 0, 2) << endl; 
	cout << LastOcc(arr, 5, 2) << endl;

	Reverse(arr, 0, 4);
	cout << "Reversed array is : ";
	PrintArray(arr, 5);
	cout << endl;
	int arrX[5] = { -1,0,1,2,4 };
	cout << "Magic Index of Array : " << MagicIndex(arrX,0,4) << endl;
	return 0;
}

int FirstOcc(int arr[], int n, int i, int key)
{
	if (n==0)
		return -1;

	if (arr[i] == key)
		return i;
	else
		return FirstOcc(arr, n - 1, i + 1, key);
}

int LastOcc(int arr[], int n, int key)
{
	if (n == 0)
		return -1;

	if (arr[n] == key)
		return n;
	else
		return LastOcc(arr, n - 1, key);
}



//Print array using recursion
void PrintArray(int arr[], int n)
{
	if (n == 0)
		return;
	else {
		n = n - 1;
		PrintArray(arr , n);
		cout << arr[n] << '\t';
	}
}

void Reverse(int arr[], int i, int j)
{
	if (i > j)
		return;
	else
	{
		swap(arr[i], arr[j]);
		i++;
		j--;
		Reverse(arr, i, j);
		
	}
}

int MagicIndex(int arr[],int s,int e)
{
	int mid = s + (e - s) / 2;

	//stop when start index becomes greater than end
	if (s > e)
		return -1;
	
	
	if (arr[mid] == mid)
		return mid;
	else if (arr[mid] > mid)
		return MagicIndex(arr, s, mid - 1);
	else
		return MagicIndex(arr, mid + 1, e);

}
