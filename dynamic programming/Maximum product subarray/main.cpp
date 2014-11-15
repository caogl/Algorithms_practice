#include<iostream>
using namespace std;

int maxProduct(int A[], int n);

int main()
{
	int A[3]={3, -1, 4};
	cout<<"Maximum subarray product is: "<<maxProduct(A, 3)<<endl;
	return 0;
}

int maxProduct(int A[], int n)
{
	int curMax=A[0];
	int curMin=A[0];
	int result=A[0];
	for(int i=1; i<n; i++)
	{
		int tmp1=curMax*A[i];
		int tmp2=curMin*A[i];
		curMax=max(max(tmp1, tmp2), A[i]);
		curMin=min(min(tmp1, tmp2), A[i]);
		result=max(result, curMax);
	}
	return result;
}


/* error solution, too many corner cases to consider 
int maxProduct(int A[], int n) 
{
	int prev0=false; // if the value for previsous index 
	int result=A[0];
	int posMax=max(0, A[0]); // the positive maximum to current point(include current point)
	int negMin=min(0, A[0]); // the negative minimum to current point(include current point)
	for(int i=1; i<n; i++)
	{
		if(A[i]==0)
		{
			prev0=true;
			posMax=0;
			negMin=0;
		}
		else
		{
			if(prev0)
			{
				posMax=max(0, A[i]);
				negMin=min(0, A[i]);
			}
			else if(A[i]>0)
			{
				posMax*=A[i];
				negMin*=A[i];
			}
			else
			{
				posMax=negMin*A[i];
				negMin=posMax*A[i];
			}
			prev0=false; // important, set it here
		}
		result=max(result, posMax);
	}
	return result;
}
*/
