#include<vector>
#include<iostream>
using namespace std;

int findMin(vector<int> &num);
void findMin(vector<int> &num, int left, int right, int& result);

int main()
{
	// if just use the copy for the problem without duplicates, cannot pass one of these cases
	vector<int> num1={10,1,10,10,10};
	vector<int> num2={3,3,1,3};
	cout<<"The minimum is: "<<findMin(num1)<<endl;
	cout<<"The minimum is: "<<findMin(num2)<<endl;
	return 0;
}

int findMin(vector<int> &num)
{
	int left=0;
	int right=num.size()-1;
	int result=num[0];
	findMin(num, left, right, result);
	return result;
}

void findMin(vector<int> &num, int left, int right, int& result)
{
	if(right<left)
		return;

	/* key point here, to make sure that after the loop, num[left]!=num[mid] and num[right]!=num[mid] 
	   if not in a loop, may be will be ended that right=mid, still cannot find minimum!*/
	int mid;
	while(true)
	{
	    mid=(left+right)/2;
	    while(mid!=right && num[mid]==num[right])
	        right--;
	    while(mid!=left && num[mid]==num[left])
	        left++;
	    if((left+right)/2==mid)
	        break;
	}
	
	if(num[mid]<=num[right]) // the right part must be sorted
	{
		result=min(result, num[mid]);
		findMin(num, left, mid-1, result);
	} 
	else // the left part must be sorted
	{
		result=min(result, num[left]);
		findMin(num, mid+1, right, result);
	}
	
}
