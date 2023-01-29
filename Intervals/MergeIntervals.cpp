#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


// Problem Solved : Leetcode 56- Merge Intervals
// Problem Link : https://leetcode.com/problems/merge-intervals/
// Approach : Sort and merge the intervals 
// Not solved with Leetcode signature 


class Interval {
public: 
	int start, end;
	Interval()
	{
		start = 0;
		end = 0;
	}
	Interval(int start, int end)
	{
		this->start = start;
		this->end = end;
	}
};

// function which will be used as criteria to sort array
bool Comparator(Interval a, Interval b)
{
	return a.start < b.start;
}


Interval* MergeIntervals(Interval intervals[], int n)
{
	sort(intervals, intervals + n, Comparator);
	int index = 0;
	
	for (int i = 1; i < n; i++)
	{
		// if end of first interval is greater than start of second interval then merge them 
		if (intervals[index].end >= intervals[i].start)
			intervals[index].end = max(intervals[index].end, intervals[i].end);
		else
		{
		// else move the index to the second interval and i++ will be pointting to the 3rd interval
			index++;
			intervals[index] = intervals[i];
		}
	}
	return intervals;
}


int main()
{
	Interval arr[4];
	arr[0] = Interval(1, 3);
	arr[1] = Interval(2, 6);
	arr[2] = Interval(8, 10);
	arr[3] = Interval(15, 18);

	MergeIntervals(arr, 4);
	
	// hardcoding the array sizes
	for (int i = 0; i < 3; i++)
	{
		cout << arr[i].start << "  " << arr[i].end << endl;
	}

	return 0;
}