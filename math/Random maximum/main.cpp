// facebook interview question: http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=114813&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption[3046][value][2]%3D2%26searchoption[3046][type]%3Dcheckbox%26sortid%3D311
// reference: http://www.fgdsb.com/2015/01/15/random-maximum/
/*
给一个数组比如： ｛1，2，3，5，5，3，2，5｝
请返回最大数的下标。
如果最大数出现了好几次，就随机返回一个，随机是指，每个最大数的下标被选中的概率是一样的

Naive的做法是先扫一遍，找出最大值和最大值的个数。然后从头再扫一遍即可。用Reservoir Sampling思路做，one pass就可以了。*/

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
