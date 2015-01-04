#include<iostream>
using namespace std;

/* reference: http://www.acmerblog.com/leetcode-median-of-two-sorted-arrays-5330.html*/
/* There is a trival O(m+n) time solution, here the solution is O(log(m+n)) */

double findMedianSortedArrays(int A[], int m, int B[], int n);

// find the kth smallest element among A, size m, and B, size n
double findKth(int A[], int m, int B[], int n, int k);

int main()
{
	int A[]={1,3,4,8,9,10,15,19,20,21,22,23,25,28,29,30};
	int B[]={2,5,6,7,11,12,13,14,16,17,18,24,26,27};
	cout<<"The median is: "<<findMedianSortedArrays(A, 16, B, 14)<<endl;
	return 0;	
}

double findMedianSortedArrays(int A[], int m, int B[], int n)
{
	int total=m+n;
	if(total & 1) // odd number
		return findKth(A, m, B, n, total/2+1);
	else
		return (findKth(A, m, B, n, total/2)+findKth(A, m, B, n, total/2+1))/2;
}

double findKth(int A[], int m, int B[], int n, int k)
{
	// we need to assume that m is greater than n and check
	if(m<n)
		return findKth(B, n, A, m, k);

	if(n==0) // base case (1)
		return A[k-1];
	if(k==1)
		return min(A[0], B[0]); // base case (2)
	
	/* divide k into two parts, and throw one part, 
	   then find the "[k-part(thrown)] th" smallest among the remaining two arrays */
	int p_n=min(k/2, n); // since n is smaller than m
	int p_m=k-p_n;
	
	/* throw the first p_m element in A, because they are among the k smallest 
	   and then find the k-p_m th smallest element */
	if(A[p_m-1]<B[p_n-1]) 
		return findKth(A+p_m, m-p_m, B, n, k-p_m);
	/* throw the first p_n element in B, because they are among the k smallest and 
	   then find the k-p_n th smallest element */
	else if(A[p_m-1]>B[p_n-1]) 
		return findKth(A, m, B+p_n, n-p_n, k-p_n);
	else
		return A[p_m-1]; // base case (3), here the kth smallest is found because A and B are sorted
}
