#include<iostream>
using namespace std;

//Problems Discussed: LeetCode-121: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//Best Time to Buy and Sell Stock 


int MaxProfit(int arr[], int n);

int main()
{
	int arr[6] = { 7,1,5,3,6,4 };
	cout << MaxProfit(arr, 6);
	return 0;
}

int MaxProfit(int arr[], int n)
{
	int buy = 0;
	int sell = 1;
	int maxProfit = 0;
	int profit;

	while (sell<n)
	{
		profit = arr[sell] - arr[buy];
		if (arr[buy] > arr[sell]) {
			buy = sell;
		}
		else if (profit > maxProfit) {
			maxProfit = profit;
		}
		sell++;
	}
	return maxProfit;

}
