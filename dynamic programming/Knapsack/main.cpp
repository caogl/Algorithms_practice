#include<iostream>
#include<utility>
#include<vector>
using namespace std;

int knapsack(const vector<pair<int, int> >& value, int limit);

int main()
{
	vector<pair<int, int> > value;
	value.push_back(make_pair(1, 1));
	value.push_back(make_pair(2, 6));
	value.push_back(make_pair(5, 18));
	value.push_back(make_pair(6, 22));
	value.push_back(make_pair(7, 28));
	cout<<"The most value the thief can take with bag 11 is: "<<knapsack(value, 11)<<endl;
	cout<<"The most value the thief can take with bag 12 is: "<<knapsack(value, 12)<<endl;
	return 0;
}

int knapsack(const vector<pair<int, int> >& value, int limit)
{
	vector<int> max;
	max.assign(limit+1, 0);
	for(int i=1; i<=limit; i++)
	{
		for(int j=0; j<value.size(); j++)
		{
			if(value[j].first<=i && (max[i-value[j].first]+value[j].second)>max[i])
				max[i]=max[i-value[j].first]+value[j].second;
		}
	}
	return max[limit];
}
