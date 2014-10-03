// reference: http://fisherlei.blogspot.com/2012/12/leetcode-next-permutation.html
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

void nextPermutation(vector<int> &num);
int main()
{
	vector<int> num={1, 2, 3};
	cout<<"Before reverse: ";
	for(int i=0; i<num.size(); i++)
		cout<<num[i]<<" ";
	nextPermutation(num);
	cout<<endl<<"After  reverse: ";
	for(int i=0; i<num.size(); i++)
		cout<<num[i]<<" ";

	return 0;
}

void nextPermutation(vector<int> &num)
{
	if(num.size()<2)
		return;
	int i=num.size()-2;
	while(i>=0)
	{
		if(num[i]<num[i+1])
			break;
		i--;
	}
	int j=i+1;
	int min=INT_MAX;
	int swap_index=i;
	while(j<num.size())
	{
		if(num[j]>num[i] && num[j]<=min)
		{
			swap_index=j;
			min=num[j];
		}
		j++;
	}

	if(swap_index!=i)
	{
		swap(num[i], num[swap_index]);
		reverse(num.begin()+i+1, num.end());
	}
	else
		reverse(num.begin(), num.end());	
}

