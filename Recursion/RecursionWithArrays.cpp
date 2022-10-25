#include<iostream>
using namespace std;

//Recursion File Completed on : October 25,2022.
//sum from 0 to n using recursion
//Check if array is sorted ,sum of array using recursion
//linear search in array , Binary Search
 

int Sum(int n);
bool IsSorted(int* arr, int len);
int FindSum(int arr[], int len);
bool SearchKey(int* arr, int len,int key);
bool BinarySearch(int* arr,int start,int end, int key);


int main()
{
	int arr[] = { 4,5,7,2,3,1 };
	cout << IsSorted(arr, 6) << endl;
	cout << Sum(100) << endl;
	cout << FindSum(arr, 6) << endl;
	cout << SearchKey(arr, 6, 7) << endl;
	int arrX[6] = {2,3,5,6,11,15};
	cout << BinarySearch(arrX, 0, 5, 6) << endl;
	return 0;
}


bool IsSorted(int* arr, int len)
{
	//if there is zero or one element in array its sorted already
	if (len == 0 || len == 1)
		return true;
	//base case 
	if (arr[0] > arr[1])
		return false;
	else
	{
		//recursive function
		return IsSorted(arr + 1, len - 1);
	}
}

int Sum(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return n + Sum(n - 1);
}

int FindSum(int arr[], int len)
{
	if (len == 0)
		return 0;
	if (len == 1)
		return arr[0];
	else
		//recursive function
		return arr[0] + FindSum(arr + 1, len - 1);
}


//Linear Search using Recursion
bool SearchKey(int* arr, int len, int key)
{
	//base case
	if (len == 0)
		return false;

	//solving one case
	if (arr[0] == key)
		return true;
	else
		return SearchKey(arr + 1, len - 1, key);
}


bool BinarySearch(int* arr, int start, int end, int key)
{
	if (IsSorted(arr, end + 1)) {

	//base case : element not found 
		if (start > end)
			return false;

		int mid = start + (end - start) / 2;
		if (arr[mid] == key)
			return true;

		//search in right part if key is greater than array of mid
		if (arr[mid] < key) {
			return BinarySearch(arr, mid + 1, end, key);
		}
		//search in left part if key is greater than array of mid
		else
		{
			return BinarySearch(arr, start, mid - 1, key);
		}
	}
	
	else{
		cout << "Array is Not Sorted " << endl;
		return false;
	}

}
