#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int random_max(const vector<int>& nums);

int main()
{
	srand (time(NULL));
	vector<int> vec={1,3,2,5,5,3,3,2,5,4,5,3,5,1,5};
	for(int i=0; i<5; i++)
		cout<<random_max(vec)<<" ";
	return 0;
}

int random_max(const vector<int>& nums) 
{
	int ret = 0, count = 0, max = INT_MIN;
	for(int i = 0; i < nums.size(); ++i)
	{
		if(nums[i] > max)
		{
			max = nums[i];
			count = 1;
			ret = i;
		} 
		else if(nums[i] == max)
		{
			if ((rand()%(++count)) == 0)
				ret = i;
		}
	}
	return ret;
}
