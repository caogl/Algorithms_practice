#include<iostream>
#include<map>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target);

int main()
{
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(9);
	vec.push_back(11);
	vector<int> result=twoSum(vec, 6);
	for(int i=0; i<vec.size(); i++)
		cout<<vec[i]<<" ";
	cout<<endl;
	cout<<result[0]<<" "<<result[1]<<endl;
	return 0;
}

/* because sorted: time--O(n), space--O(1) */
vector<int> twoSum(vector<int> &numbers, int target) 
{
        vector<int> result;
        if(numbers.size()<2)
            return result;
        int i=0;
        int j=numbers.size()-1;
        int sum=numbers[i]+numbers[j];
        while(sum!=target)
        {
            if(sum>target)	j--;
            else    i++;
            sum=numbers[i]+numbers[j];
        }
        result.push_back(i+1);
        result.push_back(j+1);
        return result;
}
