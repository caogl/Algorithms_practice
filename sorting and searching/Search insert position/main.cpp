/*
Corner case: target cannot be found
==>          left==mid==right
             (1) if target<A[left], then search in left, mid-1, since A[left-1]=A[mid-1] must be less than A[left],
	         we need to put target in the left position
	     (2) if target>A[right] then search in mid+1, right ... we need to put target in the mid+1 position
	     (1)+(2): we put target in left if the corner case happens
*/

#include<iostream>
using namespace std;

int searchInsert(int A[], int n, int target);
int searchInsert(int A[], int start, int end, int target);


int main()
{
	int A[]={1,3,5,7};
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
