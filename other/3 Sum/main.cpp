#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int> &num);

int main()
{
	vector<int> vec;
	vec.push_back(-1);
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(-1);
	vec.push_back(-4);
	
	vector<vector<int> > result=threeSum(vec);
	
	for(int i=0; i<result.size(); i++)
	{
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
vector<vector<int> > threeSum(vector<int> &num)
{
        vector<int> tmp(3);
        vector<vector<int> > resultVec;
        sort(num.begin(), num.end());
        vector<int>::iterator itr1, itr2, itr3;
        if(num.size()>=3)
        {
            for(itr1=num.begin(); itr1<(num.end()-2); itr1++)
            {
                itr2=itr1+1;
                itr3=num.end()-1;
                while(itr2!=itr3)
                {
                    int result=*itr1+*itr2+*itr3;
                    if(result==0)
                    {
                        tmp[0]=*itr1;
                        tmp[1]=*itr2;
                        tmp[2]=*itr3;
                        resultVec.push_back(tmp);
                        itr2++;
                        while(*itr2==*(itr2-1) && itr2!=itr3)
                            itr2++;
                    }
                    else if(result>0)
                        itr3--;
                    else
                        itr2++;
                }
                while(*itr1==*(itr1+1))
		    itr1++;
            }
        }
        return resultVec;
}
