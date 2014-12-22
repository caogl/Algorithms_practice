//如果我们有面值为1元、3元和5元的硬币若干枚，如何用最少的硬币凑够11元？
//(表面上这道题可以用贪心算法，但贪心算法无法保证可以求出解，比如1元换成2元的时候)
//Also Epic interview question: given a centain dose, give the optimal number of combination of pills that adds up to be equal to this amount!
//

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
	cout<<"The smallest coin number for the sum of 11 is: "<<findCoinSum(11, coin)<<endl; //3
	cout<<"The smallest coin number for the sum of 10 is: "<<findCoinSum(10, coin)<<endl; //2

	// epic corner case, greedy algorithm would produce result of 11, correct solution is 3
	coin[1]=20;
	coin[2]=50;
	cout<<"The smallest coin number for the sum of 60 is: "<<findCoinSum(60, coin)<<endl; //3

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
