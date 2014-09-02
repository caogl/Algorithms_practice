#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > permute(vector<int> &num);
void permute(vector<int>& num, vector<int>& tmp, vector<vector<int> >& result, vector<bool>& used);

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	vector<vector<int> > result=permute(num);

	for(int i=0; i<result.size(); i++)
	{
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

vector<vector<int> > permute(vector<int> &num) 
{
        vector<int> tmp;
        vector<vector<int> > result;
        vector<bool> used(num.size(), false);
        permute(num, tmp, result, used);
        return result;
}

void permute(vector<int>& num, vector<int>& tmp, vector<vector<int> >& result, vector<bool>& used)
{
        if(tmp.size()==num.size())
        {
            result.push_back(tmp);
            return;
        }
        
        for(int i=0; i<num.size(); i++)
        {
            if(used[i]){}
            else
            {
                vector<int> tmp1(tmp);
                tmp1.push_back(num[i]);
                vector<bool> used1(used);
                used1[i]=true;
                permute(num, tmp1, result, used1);
            }
        }
}
