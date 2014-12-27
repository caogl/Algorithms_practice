// idea: O(N) time ----> use hash table to store elements, then find next + or -

#include<vector>
#include<iostream>
#include<unordered_set>
using namespace std;

int longestConsecutive(vector<int> &num);

int main()
{
	vector<int> vec={100, 4, 200, 1, 3, 2};
	cout<<"Lonest consecutive sequence is: "<<longestConsecutive(vec)<<endl;
}

int longestConsecutive(vector<int> &num)
{
	if(num.size()==0)
		return 0;
	unordered_set<int> hash_set;
	for(int i=0; i<num.size(); i++)
		hash_set.insert(num[i]);
	
	int maxV=1;
	for(int i=0; i<num.size(); i++)
	{
		if(hash_set.find(num[i])!=hash_set.end())
		{
			int curV=1;
			hash_set.erase(num[i]);
			int tmp=num[i];
			while(hash_set.find(++tmp)!=hash_set.end())
			{
				curV++;
				hash_set.erase(tmp);
			}
			tmp=num[i];
			while(hash_set.find(--tmp)!=hash_set.end())
			{
				curV++;
				hash_set.erase(tmp);
			}
			maxV=max(curV, maxV);
		}
	}
	return maxV;
}
