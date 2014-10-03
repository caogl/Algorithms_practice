#include<iostream>
using namespace std;

int searchInsert(int A[], int n, int target);
int searchInsert(int A[], int start, int end, int target);


int main()
{
	int A[]={1,3,5,7};
/*
 * if the insert position is not on two sides, either on left or right, start+1 or end-1, which matches the position the new element SHOULD insert!!
 * if the insert position is on two sides, can analyse to see that the postion must be start for the last ending recursion...... 
 */
	cout<<searchInsert(A, 4, 0)<<endl;
	cout<<searchInsert(A, 4, 2)<<endl;
	cout<<searchInsert(A, 4, 4)<<endl;
	cout<<searchInsert(A, 4, 6)<<endl;
	cout<<searchInsert(A, 4, 8)<<endl;
	return 0;
}

int searchInsert(int A[], int n, int target)
{
	return searchInsert(A, 0, n-1, target);
}

int searchInsert(int A[], int start, int end, int target) 
{
	//cout<<start<<" "<<end<<endl; //-->to see why return start when no match
	if(start>end)
		return start;
	int mid=(start+end)/2;
	if(A[mid]==target)
		return mid;
	else if(A[mid]>target)
		return searchInsert(A, start, mid-1, target);
	else
		return searchInsert(A, mid+1, end, target);		
}
