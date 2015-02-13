// Google interview question
// reference: http://www.mitbbs.com/article_t/JobHunting/32856675.html
/*
 */

#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;

struct compare
{
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
	{
		if(p1.first!=p2.first)
			return p1.first<p2.first;
		else
			return p1.second<p2.second;
	}
};

vector<int> recover(vector<int>& count);

int main()
{
	vector<int> count={3,0,1,0};
	vector<int> raw=recover(count);
	for(int i=0; i<count.size(); i++)
		cout<<raw[i]<<" ";
	cout<<endl;
	return 0;
}
vector<int> recover(vector<int>& count)
{
	vector<pair<int, int> > vec;
	for(int i=0; i<count.size(); i++)
		vec.push_back(make_pair(count[i], i));
	// can use counting sort in O(n) time
	compare comp;
	sort(vec.begin(), vec.end(), comp);
	vector<int> result(count.size());
	for(int i=0; i<vec.size(); i++)
		result[vec[i].second]=i+1;
	return result;	
}
