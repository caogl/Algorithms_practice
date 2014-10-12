#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<vector<int> > combinationSum(vector<int> &candidates, int target);
void combinationSum(const vector<int>& candidates, int target, int sum, int startPos, vector<int>& tmp, vector<vector<int> >& result);

int main()
{
	vector<int> vec1={1,3,6,2,7};
	vector<vector<int> >result1=combinationSum(vec1, 7);
	for(unsigned int i=0; i<result1.size(); i++)
	{
		for(int j=0; j<result1[i].size(); j++)
			cout<<result1[i][j];
		cout<<endl;
	}
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target)
{
	vector<vector<int> > result;
	vector<int> tmp;
	sort(candidates.begin(), candidates.end());
	combinationSum(candidates, target, 0, 0, tmp, result);
	return result;
}

void combinationSum(const vector<int>& candidates, int target, int sum, int startPos, vector<int>& tmp, vector<vector<int> >& result)
{
	if(sum==target)
	{
		result.push_back(tmp);
		return;
	}
	if(sum>target)
		return;

	for(int i=startPos; i<candidates.size(); i++)
	{
		vector<int> tmp1(tmp);
		tmp1.push_back(candidates[i]);
		// to allow sam repeated numbers choosen unlimited times, start from i rather than i+1
		combinationSum(candidates, target, sum+candidates[i], i, tmp1, result);
	}
}
