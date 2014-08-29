#include<iostream>
using namespace std;

int singleNumber(int A[], int n);
int main()
{
	int a[]={12, 23, 432, 43, 41, 541, 23, 12, 542, 541, 43, 41, 432};
	cout<<"the single number is: "<<singleNumber(a, 13)<<endl;
	return 0;
}

int singleNumber(int A[], int n)
{
	int result=A[0];
	for(int i=1; i<n; i++)
		result=A[i] ^ result;
	return result;
}
