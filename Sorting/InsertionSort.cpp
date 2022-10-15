#include<iostream>
using namespace std;


//Topics discussed 
//Insertion Sort
void InsertionSort(int arr[], int n);

int main()
{

	int arr[5] = { 7,12,18,4,16 }, size = 5;
	InsertionSort(arr, 5);

	return 0;
}

void InsertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++) {
		int temp = arr[i];
		int hole = i;
		while (hole > 0 && arr[hole - 1] > temp) {
			arr[hole] = arr[hole - 1];
			hole--;
		}
		arr[hole] = temp;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}

}