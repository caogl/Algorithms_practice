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
	vector<int> result;
        multimap<int, int> map1;
        for(int i=0; i<numbers.size(); i++)
        {
            map1.insert(make_pair(numbers[i], i));
        }
        multimap<int, int>::iterator itr1=map1.begin(), itr2=--map1.end();
        while(itr1!=itr2)
        {
            if(itr1->first+itr2->first==target)
            {
                if(itr1->second<=itr2->second)
                {
                    result.push_back(itr1->second+1);
                    result.push_back(itr2->second+1);
                    return result;
                }
                else
                {
                    result.push_back(itr2->second+1);
                    result.push_back(itr1->second+1);
                    return result;                   
                }
            }
            else if(itr1->first+itr2->first>target)
                itr2--;
            else
                itr1++;
        }
}
