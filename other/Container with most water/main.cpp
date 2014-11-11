#include<iostream>
#include<vector>
using namespace std;

/* graphical explanation: http://blog.csdn.net/wzy_1988/article/details/17248209 */
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
