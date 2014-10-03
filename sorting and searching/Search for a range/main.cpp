#include<vector>
#include<iostream>
using namespace std;

vector<int> searchRange(int A[], int n, int target);
int search(int A[], int start, int end, int target);

int main()
{
	int A[]={1,2,3,4,5,6,6,6,7,8,9,10};
	vector<int> result=searchRange(A, 11, 6);
	cout<<result[0]<<" "<<result[1]<<endl;
	return 0;
}

vector<int> searchRange(int A[], int n, int target)
{
	vector<int> result={-1, -1};
	int pos=search(A, 0, n, target);
	if(pos==-1)
		return result;
	int upper=search(A, pos+1, n, target);
	if(upper!=-1)
	{
		while(upper<n && A[upper]==target)
			upper++;
		result[1]=upper-1;
		
	}
	else
		result[1]=pos;
	int lower=search(A, 0, pos-1, target);
	if(lower!=-1)
	{
		while(lower>=0 && A[lower]==target)
			lower--;
		result[0]=lower+1;
	}
	else
		result[0]=pos;
	return result;
	
}

int search(int A[], int start, int end, int target)
{
	if(start>end)
		return -1;
	int mid=(start+end)/2;
	if(A[mid]==target)
		return mid;
	else if(A[mid]<target)
		return search(A, mid+1, end, target);
	else
		return search(A, start, mid-1, target);
}

