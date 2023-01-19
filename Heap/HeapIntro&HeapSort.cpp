#include<iostream>
using namespace std;

// 1-base indexing is followed
// Priority Queues can be implemented using Queue class  


class Heap {
public:
	int arr[100];
	int size;
	Heap()
	{
		arr[0] = -1;
		size = 0;	// size of array in which heap elements are being stored
	}

	void InsertInHeap(int data)
	{
		size = size + 1;	
		int index = size;	//this will be the index of array where new element will be stored
		arr[index] = data;

		while (index > 1) {
			int parIdx = index / 2;

			// incase of MAX-Heap parent must be greater than its children
			if (arr[parIdx] < arr[index]) {
				swap(arr[parIdx], arr[index]);		
				index = parIdx;	// assigning index to parIdx to check for remaining nodes
			}
			else
				return;
		}
	}

	void DeleteFromHeap()
	{
		if (size == 0) {
			cout << "Nothing to Delete ";
			return;
		}
		// 1st step - swap first and last node of heap
		swap(arr[size], arr[1]);
		size--;	//decrementing size so that last node cant be accessed 
		
		// take root node to its correct position
		int i = 1;	// index of root node
		while (i < size) {	//size = index of last node in array
			int leftIdx = 2 * i;
			int rightIdx = 2 * i + 1;

			if (i < size && arr[i] < arr[leftIdx]) {
				swap(arr[i], arr[leftIdx]);
				i = leftIdx;
			}
			else if (i < size && arr[i] < arr[rightIdx]) {
				swap(arr[i], arr[leftIdx]);
				i = rightIdx;
			}
			else
				return;
		}


	}

	void PrintHeap()
	{
		for (int i = 1; i <= size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};


void Heapify(int arr[], int size, int index)
{
	int largest = index;
	int leftIdx = 2 * index;
	int rightIdx = 2 * index + 1;

	if (leftIdx <= size && arr[leftIdx] > arr[largest]) {
		largest = leftIdx;	// swapping largest index with left
	}
	if (rightIdx <= size && arr[rightIdx] > arr[largest]) {
		largest = rightIdx;  // swapping largest index with right
	}

	if (largest != index)
	{
		swap(arr[largest], arr[index]);	// if largest is not same as in beginning swap them
		Heapify(arr, size, largest);
	}
}


void HeapSort(int arr[], int n)
{
	// 1- Build Heap 2- Heapify each element
	int size = n;
	while (size > 1)
	{
		// step-1 : Swap first and last element
		swap(arr[size], arr[1]);
		// step-2 : Decrementing size
		size--;
		// step-3 : 
		Heapify(arr, size, 1);
	}
}



int main()
{
	Heap h1;
	h1.InsertInHeap(32);
	h1.InsertInHeap(12);
	h1.InsertInHeap(22);

	h1.PrintHeap();
	int arr[6] = { -1, 20,54,53,52,50 };
	int n = 5;

	for (int i = n / 2; i > 0; i--)
	{
		Heapify(arr, n, i);
	}

	cout << "Heap Sort : " << endl;
	HeapSort(arr, n);
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}