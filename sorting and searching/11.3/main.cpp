#include<iostream>
using namespace std;

int search(int *a, int x, int left, int right);

int main()
{
	int a[]={15,16,19,20,25,1,3,4,5,7,10,14};
	cout<<"The element 5 is in the position: "<<search(a, 5, 0, 11)<<endl;
	system("PAUSE");
    return 0;
}

int search(int *a, int x, int left, int right)
{
	int mid=(left+right)/2;
	if(a[mid]==x)
		return mid;
	if(a[mid]>a[right]) // which means the first half is sorted
	{
		if(x<a[mid] && x>a[right]) // if x is located on left half of the array
			return search(a, x, left, mid-1);
		else
			return search(a, x, mid+1, right);
	}
	else // which means the second half is sorted
	{
		if(x>a[mid] && x<a[right])
			return search(a, x, mid+1, right);
		else
			return search(a, x, left, mid-1);
	}
}
