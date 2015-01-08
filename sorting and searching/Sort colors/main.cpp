#include<iostream>
#include<algorithm>
using namespace std;

// Note: we can use counting sort for easy solution, this is a two pass algorithm
// If only one pass is allowed, here is the code
void sortColors(int A[], int n);

int main()
{
	int A[]={2,0,1,0,1,2,1,1,1,1,2,2,0,0,2,1};
	sortColors(A, 16);
	for(int i=0; i<16; i++)
		cout<<A[i]<<" ";
	return 0;
}

void sortColors(int A[], int n)
{
	int redStart=0;
	int blueEnd=n-1;
	int i=0;
	while(i<=blueEnd)
	{
		if(A[i]==0)
		{
			A[redStart++]=0;
			i++;
		}
		else if(A[i]==2)
		{
			swap(A[i], A[blueEnd]);
			blueEnd--;
		}
		else
			i++;
		
	}
	while(redStart<=blueEnd)
	{
		A[redStart++]=1;
	}
}

/* counting sort algorithm for this question: time--O(N), space--O(n+k)
void sortColors(int A[], int n)
{
        int B[3];
        memset(B, 0, sizeof(B));
        for(int i=0; i<n; i++)
            B[A[i]]++;
        for(int i=1; i<3; i++)
            B[i]+=B[i-1];
        int C[n];
        for(int i=n-1; i>=0; i--)
        {
            int index=B[A[i]];
            B[A[i]]--;
            C[index-1]=A[i];
        }
        for(int i=0; i<n; i++)
            A[i]=C[i];
}
