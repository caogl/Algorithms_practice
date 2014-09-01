#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > generate(int numRows);

int main()
{
	vector<vector<int> > result=generate(4);
	for(int i=0; i<result.size(); i++)
	{
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
}

vector<vector<int> > generate(int numRows)
{
        vector<vector<int> > result;
        if(numRows==0)
            return result;
        vector<int> tmp;
        tmp.push_back(1);
        result.push_back(tmp);
        if(numRows==1)
            return result;
        tmp.push_back(1);
        result.push_back(tmp);
        if(numRows==2)
            return result;
        for(int i=3; i<=numRows; i++)
        {
            vector<int> tmp1(i,1);
            for(int j=1; j<i-1; j++)
                tmp1[j]=result[i-2][j-1]+result[i-2][j]; // the index matters!
            result.push_back(tmp1);
        }
        return result;
}
