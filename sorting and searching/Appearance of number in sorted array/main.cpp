// facebook interview question
/* Given an array of ages (integers) sorted lowest to highest, output the number of occurrences for each age. 
 * For instance: 
 * [8,8,8,9,9,11,15,16,16,16] 
 * should output something like: 
 * 8: 3 
 * 9: 2 
 * 11: 1 
 * 15: 1 
 * 16: 3 
 *
 * This should be done in less than O(n).
 */

#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<int, int> count(vector<int>& num);
void count(vector<int>& num, int start, int end, map<int, int>& countMap);

int main()
{
	vector<int> num={8,8,8,9,11,15,16,16,16};
	map<int, int> countMap=count(num);
	for(auto itr=countMap.begin(); itr!=countMap.end(); itr++)
		cout<<itr->first<<" "<<itr->second<<endl;
	return 0;
}

map<int, int> count(vector<int>& num)
{
	map<int, int> countMap;
	count(num, 0, num.size()-1, countMap);
	return countMap;
}
void count(vector<int>& num, int start, int end, map<int, int>& countMap)
{
	if(end<start)	return;
	
	if(start==end)	countMap[num[start]]+=(end-start+1);
	else
	{
		count(num, start, (start+end)/2, countMap);
		count(num, (start+end)/2+1, end, countMap);
	}
}
