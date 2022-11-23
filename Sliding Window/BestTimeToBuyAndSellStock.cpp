#include<iostream>
using namespace std;

//File Completed On : November 23,2022.
//Sliding Window Algorithm
//Problem Solved , LeetCode-121 : https://leetcode.com/problems/best-time-to-buy-and-sell-stock

int BestTime(int* arr, int n);


int main()
{
	int arr[6] = { 7,1,5,3,6,4 };
	int ans = BestTime(arr, 6);
	cout << ans << endl;
	return 0;
}


int BestTime(int* arr, int n)
{
	int profit = 0;

	int buy = 0,sell = 1;	//using two pointer approach
	while (sell <= n) {	
		int tempProfit = arr[sell] - arr[buy];	//find current profit
		if (arr[buy] > arr[sell]) {
			buy = sell;
		}
		else if (tempProfit>profit){
			profit = tempProfit;
		}
		sell++;
	}
	
	return profit;
}