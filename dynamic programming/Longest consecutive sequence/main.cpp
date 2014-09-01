#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int longestConsecutive(vector<int> &num);

int main()
{
	int a[]={5,3,5,1,8,0,1,19,2,4,8,6,6,11,16,19,23};
	vector<int> vec(17);
	for(int i=0; i<17; i++)
		vec[i]=a[i];
	cout<<"Lonest consecutive sequence is: "<<longestConsecutive(vec)<<endl;
}

int longestConsecutive(vector<int> &num)
{
        std::sort(num.begin(), num.end());
        vector<int> longest(num.size(), 1);
        for(int i=1; i<num.size(); i++)
        {
            if(num[i-1]==num[i]-1)
                longest[i]=longest[i-1]+1;
            else if(num[i-1]==num[i]) //Important step
                longest[i]=longest[i-1];
        }        
        return *max_element(longest.begin(), longest.end());
}
