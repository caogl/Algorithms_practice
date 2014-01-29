#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findCoinSum(int target, const vector<int>& coin);

int main()
{
	vector<int> coin(3);
	coin[0]=1;
	coin[1]=3;
	coin[2]=5;
	cout<<"The smallest coin number for the sum of 11 is: "<<findCoinSum(11, coin)<<endl;
	cout<<"The smallest coin number for the sum of 10 is: "<<findCoinSum(10, coin)<<endl;
	system("PAUSE");
	return 0;
}

int findCoinSum(int target, const vector<int>& coin)
{
	vector<int> min;
	min.assign(target+1, INT_MAX);
	min[0]=0;
	for(int i=0; i<=target; i++)
	{
		for(int j=0; j<coin.size(); j++)
		{
			if(coin[j]<=i && min[i-coin[j]]+1<min[i])
			{
				//cout<<"haha ";
				min[i]=min[i-coin[j]]+1;
			}
		}
	}
	return min[target];
}