// 只要mid比其左邻居小，那说明左半段必然存在peak，只访问左半段即可；否则，右半段必然存在peak。
// 需要注意的是，两端也可以是peak。

#include<iostream>
#include<vector>
using namespace std;

int findPeakElement(const vector<int> &num);
int findPeakElement(const vector<int> &num, int left, int right);

int main()
{
	vector<int> num={1,2,3,1};
	cout<<findPeakElement(num)<<endl;
	return 0;
}

int findPeakElement(const vector<int> &num)
{
        if(num.size()==1)
            return 0;
        
        return findPeakElement(num, 0, num.size()-1);
}

int findPeakElement(const vector<int> &num, int left, int right)
{
        int mid=(left+right)/2;
        if(mid==0 && num[mid]>num[mid+1]) // check peak element at boundaries
            return mid;
        else if(mid==num.size()-1 && num[mid]>num[mid-1]) // check peak element at boundaries
            return mid;
        else if(mid>0 && mid<num.size()-1 && num[mid]>num[mid-1] && num[mid]>num[mid+1])
            return mid;
                         // cannot change this "<" to ">" and explore the other side, out of range!
        else if(mid>0 && num[mid]<num[mid-1]) // must check that mid>0, or if mid==0, seg fault !!!
            return findPeakElement(num, left, mid-1);
        else // the check of the boundary optional here because it is guaranteed that there is a peak
            return findPeakElement(num, mid+1, right);
}
