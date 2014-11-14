#include<iostream>
using namespace std;

bool canJump(int A[], int n) 
{
        int reached=A[0];
        for(int i=1; i<n; i++)
        {
            if(i>reached)
                return false;
            else
                reached=max(reached, i+A[i]);
        }
        return reached>=(n-1);
}

int main()
{
	int A[5]={2,3,1,1,4};
	int B[5]={3,2,1,0,4};
	cout<<canJump(A, 5)<<endl;
	cout<<canJump(B, 5)<<endl;
	return 0;
}
