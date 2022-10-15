#include<iostream>
using namespace std;


//Topics discussed 
//Bubble Sort 	-- O(n^2)

void BubbleSort(int arr[], int n);


int main()
{

	int arr[5] = { 7,12,18,4,16 }, n = 5;
	cout << "Bubble sort : " << endl;
	BubbleSort(arr, 5);
	return 0;
}

void BubbleSort(int arr[],int n) {
	//for optimization : check if element gets swapped get out of the loop
	bool swapped = false;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}

}