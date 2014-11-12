#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

/*
 * For the small test, we can look at the bar graph from level to level. For each level, scan from the 1st to the last, count 0s between two 1's. 
 * Add all the valid 0s for all the levels. However, if the highest and lowest bar is too much different, say 0, 100000, the loop while 100000*n, which is not efficient.
 *
 * An O(n) solution is to consider each bar at a time, we can see that, for each bar, the water itself can trap depends on the max height on its left and right,
 * e.g.  if current bar is of height 2, the max height on its left is 4, max height on its right is 3,   then water can be trapped in this bar is min(4,3)-2 = 1.
 * */

int trap(int A[], int n);

int main()
{
	int A[]={0,1,0,2,1,0,1,3,2,1,2,1};
	cout<<"The trapped rain water is: "<<trap(A, 12)<<endl;
	return 0;
}

int trap(int A[], int n)
{
	// cannot initialize like this: int* leftMax=A, which just copies address!!!!!!!
	int leftMax[n]; // for each column, the highest column on its left
	int rightMax[n]; // for each column, the highest column on its right
	for(int i=0; i<n; i++)
	{
		leftMax[i]=A[i];
		rightMax[i]=A[i];
	}

	for(int i=1; i<n; i++)
	{
		leftMax[i]=max(leftMax[i], leftMax[i-1]);
	}

	for(int i=n-2; i>=0; i--)
	{
		rightMax[i]=max(rightMax[i], rightMax[i+1]);
	}

	int result=0;
	for(int i=1; i<n-1; i++)
	{
		result+=min(rightMax[i], leftMax[i])-A[i];
	}
	return result;
}
