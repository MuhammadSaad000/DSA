#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// kth smallest and kth largest element in array using heap
// approach -01 : Sort the array return (n-k)th element in case of kth smallest 

int kthLargestElement(vector<int>& nums, int k);
int kthSmallestElement(vector<int>& nums, int k);


int kthSmallestElement(vector<int>& nums, int k)
{
	priority_queue<int> pq;
	// create max heap from first k elements for kth Smallest 
	for (int i = 0; i < k; i++) {
		pq.push(nums[i]);
	}

	// for rest of elements if heap.top()(max) is less than current element delete from top of heap
	// and push that element into the heap
	for(int i=k;i<nums.size();i++)
	{ 
		if (nums[i] < pq.top()) {
			pq.pop();
			pq.push(nums[i]);
		}
	}
	return pq.top();
}

int kthLargestElement(vector<int>& nums, int k)
{
	// creating min heap from stl c++
	priority_queue<int, vector<int>, greater<int>> pq;

	// push first k elements into heap
	for (int i = 0; i < k; i++)
	{
		pq.push(nums[i]);
	}

	// for rest of elements if heap.top()(max) is greater than current element delete from top of heap
	// and push that element into the heap
	for (int i = k; i < nums.size(); i++)
	{
		if (nums[i] > pq.top()) {
			pq.pop();
			pq.push(nums[i]);
		}
	}
	return pq.top();
}


int main()
{
	vector<int> arr = { 7,10,4,20,5 };
	int kSmall = kthSmallestElement(arr, 4);
	int kLarge = kthLargestElement(arr, 5);
	
	cout << "KTh Smallest Element : " << kSmall << endl;
	cout << "kTh Largest Element : " << kLarge << endl;


	return 0;
}