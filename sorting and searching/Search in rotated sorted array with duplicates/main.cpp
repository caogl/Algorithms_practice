#include<iostream>
using namespace std;

bool search(int A[], int n, int target);
bool search(int A[], int left, int right, int target);

int main()
{
	int a[]={1,1,1,3,1};
	int b[]={3,1,3,3,3};
	cout<<search(a, 5, 3)<<endl;
	cout<<search(b, 5, 1)<<endl;
    	return 0;
}

bool search(int A[], int n, int target) 
{
            int left=0;
            int right=n-1;
            return search(A, left, right, target);
}
   
bool search(int A[], int left, int right, int target)
{
        if(right<left)
            return false;
        
        int mid=(left+right)/2;
        if(A[mid]==target)
            return true;
        else 
        {
            if(A[mid]==A[right])
                return (A[right]==target || search(A, left, right-1, target));
            else if(A[mid]>A[right]) // left sorted
            {
                if(target>=A[left] && target<A[mid])
                    return search(A, left, mid-1, target);
                else
                    return search(A, mid+1, right, target);
            }
            else // right sorted 
            {
                if(target>A[mid] && target<=A[right])
                    return search(A, mid+1, right, target);
                else
                    return search(A, left, mid-1, target);
            }
        }
}
