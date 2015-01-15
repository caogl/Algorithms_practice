/* Perform bucket sort, each element finds its correct position if possible
 * then from position from i=0 to n-1, if A[i]!=i+1, return i+1, if the loop ends, return n+1
   exp1: 3, 4, -1, 1
   ----> 1, -1, 3, 4, return 2
   exp2: -1, 13, 14, 5
   ----> -1, 13, 14, 5, return 1
*/

#include<iostream>
#include<algorithm>
using namespace std;

int firstMissingPositive(int A[], int n);

int main()
{
	int A[]={-1, 13, 14, 5};
	cout<<firstMissingPositive(A, 4)<<endl;
	int B[]={3, 4, -1, 1};
	cout<<firstMissingPositive(B, 4)<<endl;
	int C[]={1, 4, -1, 1};  // handle duplicate elements
	cout<<firstMissingPositive(C, 4)<<endl;

	return 0;
}

int firstMissingPositive(int A[], int n) 
{
        for(int i=0; i<n; i++)
        {
        	if(A[i]!=i+1 && A[i]>=1 && A[i]<=n && A[i]!=A[A[i]-1]) 
        	// (1) the final check condition avoids dead loop!
            	{
                	swap(A[i], A[A[i]-1]);
                	i--; // (2) without this, test (A) would become: -1 1 3 4, position 1 needs to go on swap!!!
            	}
        }
        for(int i=0; i<n; i++)
            if(A[i]!=i+1)
                return i+1;
        return n+1;
}
