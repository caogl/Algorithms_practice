#include<iostream>
#include<climits>
using namespace std;

int maxSubArray(int A[], int n);

int main()
{
	int a[]={-2, 1, -3, 4, -1, 2, 1, -5, 4};
	for(int i=0; i<9; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<"The largest sum is: "<<maxSubArray(a, 9)<<endl;
	return 0;
}

int maxSubArray(int A[], int n)
{
        if(n==1)
            return A[0];
        int *B=A; // B[i] stores the bigest continuous sum to i
        for(int i=1; i<n; i++)
        {
            if(B[i-1]>0) // transformation from B[i-1] to B[i]
                B[i]=A[i]+B[i-1];
            else
                B[i]=A[i];
        }
        int max=B[0];
        for(int i=1; i<n; i++)
            if(B[i]>max)
                max=B[i];
        return max;
}
