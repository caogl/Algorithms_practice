// Google interview question
// reference: http://www.mitbbs.com/article_t/JobHunting/32856675.html
/*
给定一个数字数组 ,其中每个元素是从末端数小于原数组中该元素的个数。求原数组。
原数组中元素是 从1到n。Example:
原数组      ：4, 1, 3, 2
Count array ：3, 0, 1, 0

即用两条件sort：（1）value大小
		（2）value若相等，右边index的数比左边大
--》 用counting sort即可，做成pair， 再根据index recover
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
