// from leetcode cleancode handbook
// reference: http://www.geeksforgeeks.org/array-rotation/
// input:  1 2 3 4 5 6 7     2
// result: 6 7 1 2 3 4 5

#include<iostream>
#include<algorithm>
using namespace std;

void rotateK(int A[], int n, int k);
void rotateRightbyOne(int A[], int n);

int main()
{
	int A[]={1,2,3,4,5,6,7};
	rotateK(A, 7, 2);
	for(int i=0; i<7; i++)
		cout<<A[i]<<" ";
	cout<<endl;
	return 0;
}

// time--O(k*n), space--O(1)
void rotateK(int A[], int n, int k)
{
	for(int i=0; i<k; i++)
		rotateRightbyOne(A, n);
}

void rotateRightbyOne(int A[], int n)
{
	int tmp=A[n-1];
	//for(int i=0; i<n-1; i++)	A[i+1]=A[i]; error, all covered value!	
	for(int i=n-1; i>=1; i--)	A[i]=A[i-1]; // should assign in the opposite direction!!!
	A[0]=tmp;
}
