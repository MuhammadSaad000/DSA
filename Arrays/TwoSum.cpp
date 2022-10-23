#include<iostream>
#include<algorithm>	
using namespace std;

//Problems discussed
//TwoSum - LeetCode 1: https://leetcode.com/problems/two-sum/

pair<int,int> TwoSum(int arr[], int n, int sum);

int main()
{
	int arr[] = { 2,7,11,15 };
	pair<int,int> temp = TwoSum(arr, 4, 9);
	if (temp.first == -1 || temp.second == -1) {
		cout << "Not Found ";
	}
	else {
		cout << "[" << temp.first << "," << temp.second << "]" << endl;
		cout << "Pair Found " << endl ;
	}

	return 0;
}

pair<int,int> TwoSum(int arr[], int n, int sum)
{
	sort(arr, arr + n);
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		if (arr[left] + arr[right] == sum)
		{
			pair<int, int> temp = {left,right};
			return temp;
		}
		else if (arr[left] + arr[right] < sum)
		{
			left++;
		}
		else
		{
			right--;
			pair<int, int> temp = { -1,-1 };
		}
	}
}