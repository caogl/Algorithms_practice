// very similar with 3Sum, just keep track of the minimum difference instead

#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int> &num, int target);

int main()
{
	vector<int> num={-1, 2, 1, -4};
	cout<<threeSumClosest(num, 1)<<endl;
	return 0;
}

int threeSumClosest(vector<int> &num, int target)
{
        sort(num.begin(), num.end());
        vector<int>::iterator itr1, itr2, itr3;
        int minDist=INT_MAX;
        int result;
        for(itr1=num.begin(); itr1<num.end()-2; itr1++)
        {
            itr2=itr1+1;
            itr3=num.end()-1;
            while(itr2!=itr3)
            {
                int tmp=*itr1+*itr2+*itr3;
                if(abs(tmp-target)<minDist)
                {
                    minDist=abs(tmp-target);
                    result=tmp;
                }
                if(tmp>target)
                    itr3--;
                else
                    itr2++;
            }
            while(itr1<num.end()-3 && *itr1==*(itr1+1)) itr1++;
        }
        return result;
}
