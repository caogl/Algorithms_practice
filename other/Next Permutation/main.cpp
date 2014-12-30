// reference: http://fisherlei.blogspot.com/2012/12/leetcode-next-permutation.html
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

void nextPermutation(vector<int> &num);
int main()
{
	vector<int> num={1, 2, 3};
	cout<<"Before reverse: ";
	for(int i=0; i<num.size(); i++)
		cout<<num[i]<<" ";
	nextPermutation(num);
	cout<<endl<<"After  reverse: ";
	for(int i=0; i<num.size(); i++)
		cout<<num[i]<<" ";

	return 0;
}

void nextPermutation(vector<int> &num)
{
        if(num.size()<=1)
            return;
        int index1=-1;
        for(int i=num.size()-2; i>=0; i--)
        {
            if(num[i]<num[i+1])
            {
                index1=i;
                break;
            }
        }
        if(index1==-1) // if the last sequence order
        {
            reverse(num.begin(), num.end());
            return;
        }
        
        int index2=-1;
        for(int i=num.size()-1; i>=0; i--)
        {
            if(num[i]>num[index1])
            {
                index2=i;
                swap(num[index1], num[index2]);
                reverse(num.begin()+index1+1, num.end()); // here it is index1 rather than index2 !!
                break;
            }
        }
}

