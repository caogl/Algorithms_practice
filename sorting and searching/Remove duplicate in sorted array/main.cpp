#include<iostream>
using namespace std;

int removeDuplicates(int A[], int n);

int main()
{
	int a[]={1, 1, 2, 2, 2, 3, 4, 4, 5, 7, 7, 7, 9, 9};
	int n=removeDuplicates(a, 14);
	for(int i=0; i<n; i++)
		cout<<a[i]<<"	";
	cout<<endl;
	return 0;
}

int removeDuplicates(int A[], int n)
{
	if(n==0 || n==1)
	return n;
	int pos=0;
	for(int i=1; i<n; i++)
	{
		if(A[i]!=A[pos])
			A[++pos]=A[i];
	}
	return pos+1;
}
