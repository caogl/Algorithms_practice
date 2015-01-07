// graphical explanation: http://blog.csdn.net/wzy_1988/article/details/17248209 *
/*
假定初始的盛水面积为ans=0，lh为左边的高度，rh为右边的高度，如果lh < rh, 则向右运动，寻找第一个比当前lh大的左节点。
同理，如果lh > rh，则向左运动，寻找第一个比当前rh大的右节点。
截止条件为坐标L >= R。
*/

#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int> &height);

int main()
{
	vector<int> vec={5, 1, 6, 3, 4, 100, 2, 4, 6, 2};
	cout<<"The most water that the container can hold is: "<<maxArea(vec)<<endl;
	return 0;
}

int maxArea(vector<int> &height)
{
        int left=height[0];
        int right=height[height.size()-1];
        int result=min(left, right)*(height.size()-1); // notice the width here is size()-1 rather than size, because we are not counting!
        int leftIndex=0;
        int rightIndex=height.size()-1;
        while(leftIndex<rightIndex)
        {
            if(left<right)
            {
                leftIndex++;
                if(height[leftIndex]>left)
                {
                    left=height[leftIndex];
                    result=max(result, min(left, right)*(rightIndex-leftIndex));
                }
            }
            else
            {
                rightIndex--;
                if(height[rightIndex]>right)
                {
                    right=height[rightIndex];
                    result=max(result, min(left, right)*(rightIndex-leftIndex));
                }
            }
        }
        return result;
}
