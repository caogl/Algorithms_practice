// reference: http://www.cnblogs.com/tenosdoit/p/3649607.html

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target);

int main()
{
	vector<int> num={1,0,-1,0,-2,2};
	vector<vector<int> > result=fourSum(num, 0);
	for(int i=0; i<result.size(); i++)
	{
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

// idea: After sorting,  fix the first and second index, then do two sum for the remaining index
//       --- runtime: O(N^3), space: O(1)
vector<vector<int> > fourSum(vector<int> &num, int target)
{
	int n=num.size(); 
	sort(num.begin(), num.end());
	vector<vector<int> > result;
	int sum=0;
	for(int i=0; i<n-3; i++)
	{
		if(i>0 && num[i-1]==num[i])	continue; // avoid duplicate for first index
		for(int j=i+1; j<n-2; j++)
		{
			if(j>i+1 && num[j-1]==num[j])	continue; // avoid duplicate for second index
			int k=j+1;
			int l=n-1;
			int target1=target-num[i]-num[j];
			while(k!=l)
			{
				int sum=num[k]+num[l];
				if(sum==target1)
				{
					result.push_back(vector<int> {num[i], num[j], num[k], num[l]});
					k++;
					while(k!= l && num[k-1]==num[k]) // avoid duplicate in third index
						k++;
				}
				else if(sum>target1)
					l--;
				else
					k++;
			}
		}
	}
	return result;
}

// optional: --- runtime: O(N^2), space: O(N^3), actually runs slower than the above one, see the reference link 
