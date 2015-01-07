// reference: http://fisherlei.blogspot.com/2013/01/leetcode-trapping-rain-water.html
/*
[解题思路]
对于任何一个坐标，检查其左右的最大坐标，然后相减就是容积。所以，
1. 从左往右扫描一遍，对于每一个坐标，求取左边最大值。
2. 从右往左扫描一遍，对于每一个坐标，求最大右值。
3. 再扫描一遍，求取容积并加和。
#2和#3可以合并成一个循环，
*/

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

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
