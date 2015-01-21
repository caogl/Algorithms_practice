// Google interview question: http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=113812&highlight=google
/* idea: traverse the array from the beginning to end, if found repeat currentSum, means that one such subarray is found */

#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

vector<int> LongestSubarraySumtoZero(vector<int> vec)
{
	unordered_map<int, int> hashMap;// key: currentSum, value: first position that this sum appears
	vector<int> result;
	int currentSum=0;
	int left=0;
	int right=-1;
	int maxDiffPos=-1;
	for(int i=0; i<vec.size(); i++)
	{
		currentSum+=vec[i];
		if(hashMap.find(currentSum)!=hashMap.end())
		{
			if(i-hashMap[currentSum]>maxDiffPos)
			{
				maxDiffPos=i-hashMap[currentSum];
				left=hashMap[currentSum];
				right=i;
			}
		}
		else
			hashMap[currentSum]=i;
	}
	if(right!=-1)
	{
		for(int i=left; i<=right; i++)
			result.push_back(vec[i]);
	}
	return result;
}

int main()
{
	vector<int> vec={8,1,2,3,-5,9,29,-29,4,-5,-1,2,1,-8,-3,2,3,3,3,3,-1,-12,2,3,-1};
	vector<int> result=LongestSubarraySumtoZero(vec);
	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<" ";
	cout<<endl;
	return 0;
}
