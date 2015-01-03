#include<vector>
#include<iostream>
using namespace std;

int findMin(vector<int> &num);
void findMin(vector<int> &num, int left, int right, int& result);

int main()
{
	vector<int> num={3,4,5,6,7,8,1,2,3};
	cout<<"The minimum is: "<<findMin(num)<<endl;
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
	
	int mid=(left+right)/2;
	if(num[mid]<num[right]) // the right part must be sorted
	{
		result=min(result, num[mid]);
		findMin(num, left+1, mid-1, result);
	} 
	else // the left part must be sorted
	{
		result=min(result, num[left]);
		findMin(num, mid+1, right-1, result);
	}
}
