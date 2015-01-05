#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target);

int main()
{
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(2);
	vec.push_back(8);
	vec.push_back(11);
	vec.push_back(9);
	vec.push_back(6);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(7);
	vector<int> result=twoSum(vec, 6);
	for(int i=0; i<vec.size(); i++)
		cout<<vec[i]<<" ";
	cout<<endl;
	cout<<result[0]<<" "<<result[1]<<endl;
	return 0;
}

/* solution(1): time--O(n), space--O(n) */
vector<int> twoSum(vector<int> &numbers, int target)
{
	unordered_map<int, int> hashMap;
	for(int i=0; i<numbers.size()-1; i++)
		hashMap[numbers[i]]=i;
	
	for(int i=0; i<numbers.size(); i++)
	{
		int tmp=target-numbers[i];
		// second check condition make sure that duplicate elements would return same indexes
		if(hashMap.find(tmp)!=hashMap.end() && hashMap[tmp]!=i)
		{
			vector<int> result={min(i, hashMap[tmp])+1, max(i, hashMap[tmp])+1};
			return result;
		}
	}
}

/* solution(2): time--O(nlog(n)), space--O(n) *
vector<int> twoSum(vector<int> &numbers, int target) 
{
        multimap<int, int> map1; // deal with duplicate!!!
        for(int i=0; i<numbers.size(); i++)
            map1.insert(make_pair(numbers[i], i));
            
        auto itr1=map1.begin(); 
        auto itr2=--map1.end();
        int sum=itr1->first+itr2->first;
        while(sum!=target)
        {
            if(sum>target)  itr2--;
            else if(sum<target) itr1++;
            sum=itr1->first+itr2->first;
        }
        // giving index an ordering !!!
        vector<int> result={min(itr1->second+1, itr2->second+1), max(itr1->second+1, itr2->second+1)};
        return result;
}
*/
