#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxProfit1(vector<int> &prices);
int maxProfit2(vector<int> &prices);
int maxProfit3(vector<int> &prices);

int main()
{
	vector<int> vec={1,2,4,2,5,7,2,4,9};
	cout<<maxProfit1(vec)<<endl<<maxProfit2(vec)<<endl;
	cout<<maxProfit3(vec)<<endl;
	return 0;
}

int maxProfit1(vector<int> &prices)
{
	if(prices.size()==0)
		return 0;
	int profit=0;
	int min=prices[0];
	for(int i=0; i<prices.size(); i++)
	{
		if(prices[i]>min && prices[i]-min>profit)
			profit=prices[i]-min;
		else if(prices[i]<min)
			min=prices[i];
	}
	return profit;
}

int maxProfit2(vector<int> &prices)
{
	if(prices.size()==0)
		return 0;
	int profit=0;
	for(int i=0; i<prices.size()-1; i++)
		if(prices[i+1]-prices[i]>0)
			profit+=prices[i+1]-prices[i];
	return profit;
}

int maxProfit3(vector<int> &prices)
{
	if(prices.size()==0)
		return 0;
	int dp1[prices.size()]; // the profit of the first trade
	int min=prices[0];
	int profit=0;
	for(int i=0; i<prices.size(); i++)
	{
		if(prices[i]-min>profit)
			profit=prices[i]-min;
		else if(prices[i]<min)
			min=prices[i];
		dp1[i]=profit;
	}
	
	int result=profit;
	if(prices.size()<4)
		return result;
	
	int dp2[prices.size()]; // the profit of the second trade
	int maxV=prices[prices.size()-1]; 
	profit=0;
	for(int i=prices.size()-1; i>=0; i--)
	{
		if(maxV-prices[i]>profit)
			profit=maxV-prices[i];
		else if(prices[i]>maxV)
			maxV=prices[i];
		dp2[i]=profit;
	}
	
	for(int i=1; i<prices.size()-1; i++)
		result=max(result, dp1[i]+dp2[i+1]);
	return result;
}
