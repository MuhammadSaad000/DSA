#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Problem Solved : LeetCode-1. Two Sum
// Problem link : https://leetcode.com/problems/two-sum/


vector<int> TwoSum(vector<int>& nums, int target);


vector<int> TwoSum(vector<int>& arr, int target)
{
	vector<int> ans;
	unordered_map<int, int> visited;

	for (int i = 0; i < arr.size(); i++) {
		int diff = target - arr[i];

		if (visited.find(diff) != visited.end()) {
			ans.push_back(visited[diff]);	//index where complement exists
			ans.push_back(i);	// index of current element
			break;
		}
		else
			visited[arr[i]] = i;	// inserting element and its index 
	}
	return ans;
}


int main()
{	
	vector<int> arr = { 2,4,3,9,12,7 };
	int target = 16;
	arr = TwoSum(arr, target);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}

	return 0;
}