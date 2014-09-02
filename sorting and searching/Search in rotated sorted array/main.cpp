#include<iostream>
using namespace std;

int search(int A[], int n, int target);
int search(int A[], int begin, int end, int target);

int main()
{
	//int a[]={15,16,19,20,25,1,3,4,5,7,10,14};
	int a[]={1, 3};
	cout<<"The element is in the position: "<<search(a, 2, 3)<<endl;
    	return 0;
}

int search(int A[], int n, int target) 
{
        if(n==0)
            return -1;
        return search(A, 0, n-1, target);
}
    
int search(int A[], int begin, int end, int target)
{
        if(begin>end)
            return -1;
        int mid=(begin+end)/2;
        if(A[mid]==target)
            return mid;
        if(A[mid]>A[end]) // the first half is sorted
        {
            if(target>=A[begin] && target<A[mid])
	    {
                return search(A, begin, mid-1, target);
	    }
            else
	    {
                return search(A, mid+1, end, target);
	    }
        }
        else // the second half is sorted
        {
            if(target>A[mid] && target<=A[end]) // notice <= cannot be <!!!
	    {
                return search(A, mid+1, end, target);
	    }
            else
	    {
                return search(A, begin, mid-1, target);
	    }
        }
}
