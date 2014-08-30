#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int largestRectangleArea(vector<int> &height);

int main()
{
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(2);
	vec.push_back(3);
	cout<<"The size of max rectangle is: "<<largestRectangleArea(vec)<<endl;
	return 0;
}

int largestRectangleArea(vector<int> &height)
{
	int maxSize=0;
	for(int i=0; i<height.size(); i++)
	{
		if(i<height.size()-1 && height[i]<=height[i+1]){}
		else
		{
			int minHeight=height[i];
			for(int j=i; j>=0; j--)
			{
				minHeight=min(minHeight, height[j]);
				maxSize=max(maxSize, minHeight*(i-j+1));
			}
		}
	}
	return maxSize;
}
