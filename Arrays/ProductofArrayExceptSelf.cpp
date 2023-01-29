#include<iostream>
#include<vector>
using namespace std;

// Problem Solved : Leetcode 238 : Product of Array Except Self
// Problem Link : https://leetcode.com/problems/product-of-array-except-self/
// approach : make two arrays left and right, product array will be left[i-1]*right[i+1]  


vector<int> productExceptSelf(vector<int>& nums);

vector<int> productExceptSelf(vector<int>& nums)
{ 
	int size = nums.size();
	vector<int> product(size);
	vector<int> left(size);
	vector<int> right(size);

	left[0] = nums[0];	// edge case 
	// left product will be last left index left[i-1] and current nums[i]
	for (int i = 1; i < size; i++)
	{
		left[i] = left[i - 1] * nums[i];
	}
	
	right[size - 1] = nums[size - 1];	// edge case 
	// right product will be first right index right[i+1] and current nums[i]
	for (int i = size - 2; i>=0; i--)
	{
		right[i] = right[i + 1] * nums[i];
	}

	product[0] = right[1];
	for (int i = 1; i < size - 1; i++)
	{
		product[i] = right[i + 1] * left[i - 1];
	}

	product[size - 1] = left[size - 2];

	return product;

}


int main()
{
	vector<int> nums = { 1,2,3,4 };
	nums = productExceptSelf(nums);
	for (auto i : nums)
	{
		cout << i << " ";
	}
	return 0;
}