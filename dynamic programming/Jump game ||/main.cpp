#include<iostream>
#include<climits>
using namespace std;

int jump(int A[], int n);

int main()
{
	int A[995000];
	for(int i=0; i<994997; i++)
		A[i]=994998-i;
	A[994998]=1;
	A[994999]=1;
	cout<<"The minimum step to reach the end is: "<<jump(A, 995000)<<endl;
	int B[1]={0};
	cout<<"The minimum step to reach the end is: "<<jump(B, 1)<<endl;	
	return 0;
}

int jump(int A[], int n)
{
	if(n<2) // must check the trival case here!, or, cannot pass [0] case!
		return 0;

        int minStep[n];
	int farestReached=0; /* only need to update smallest distance from the farest can be reached in previous positions*/
        minStep[0]=0;
        for(int i=1; i<n-1; i++)
        {
            minStep[i]=INT_MAX;
        }
        for(int i=0; i<n; i++)
        {
	    if(A[i]+i>farestReached)
	    {
            	for(int j=farestReached+1; j<=A[i]+i; j++)
            	{
                	if(j>=n-1)
                    		return minStep[i]+1;
                	minStep[j]=min(minStep[i]+1, minStep[j]);
		}
		farestReached=A[i]+i;
            }
        }	
}

/* This initial try will cause time out 
int jump(int A[], int n)
{
        int minStep[n];
        minStep[0]=0;
        for(int i=1; i<n-1; i++)
        {
            minStep[i]=INT_MAX;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<A[i]; j++)
            {
                if(i+j==n-1)
                    return minStep[i]+1;
                minStep[i+j]=min(minStep[i]+1, minStep[i+j]);
            }
        }
}
*/
