#include<iostream>
#include<map>
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
