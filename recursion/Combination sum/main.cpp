#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<vector<int> > combinationSum(vector<int> &candidates, int target);
void combinationSum(vector<vector<int> >& result, vector<int> & candidates, int target, vector<int>& tmp, int currentSum, int startPos);

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
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        vector<int> tmp;
        int currentSum=0;
        int startPos=0;
        combinationSum(result, candidates, target, tmp, currentSum, startPos);
        return result;
}
    
void combinationSum(vector<vector<int> >& result, vector<int> & candidates, int target, vector<int>& tmp, int currentSum, int startPos)
{
        if(currentSum>=target)
        {
            if(currentSum==target)
                result.push_back(tmp);
            return;
        }
        
        for(int i=startPos; i<candidates.size(); i++)
        {
            tmp.push_back(candidates[i]);
            combinationSum(result, candidates, target, tmp, currentSum+candidates[i], i);
            tmp.pop_back();
        }
}
