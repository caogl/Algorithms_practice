#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > permute(vector<int> &num);
void permute(vector<int>& num, vector<bool>& used, vector<int>& tmp, vector<vector<int> >& result, int startPos);
vector<vector<int> > permuteUnique(vector<int> &num);
void permuteUnique(vector<int>& num, vector<bool>& used, vector<int>& tmp, vector<vector<int> >& result, int startPos);

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);

	// generate permutations
	vector<vector<int> > result=permute(num);
	for(int i=0; i<result.size(); i++)
	{
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	num[2]=1;
	// there are duplicate sequences
	result=permute(num);
	for(int i=0; i<result.size(); i++)
	{
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	// no duplicate sequence
	result=permuteUnique(num);
	for(int i=0; i<result.size(); i++)
	{
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	return 0;
}

vector<vector<int> > permute(vector<int> &num) 
{
        vector<bool> used(num.size(), false);
        int startPos=0;
        vector<vector<int> > result;
        vector<int> tmp;
        permute(num, used, tmp, result, startPos);
        return result;
}
    
void permute(vector<int>& num, vector<bool>& used, vector<int>& tmp, vector<vector<int> >& result, int startPos)
{
        if(startPos==num.size())
        {
            result.push_back(tmp);
            return;
        }
        
        for(int i=0; i<num.size(); i++)
        {
            if(!used[i])
            {
                tmp.push_back(num[i]);
                used[i]=true;
                permute(num, used, tmp, result, startPos+1);
                used[i]=false;
                tmp.pop_back();
            }
        }
}

vector<vector<int> > permuteUnique(vector<int> &num)
{
        sort(num.begin(), num.end());
        vector<bool> used(num.size(), false); // give ordering !!!
        int startPos=0;
        vector<vector<int> > result;
        vector<int> tmp;
        permuteUnique(num, used, tmp, result, startPos);
        return result;
}
    
void permuteUnique(vector<int>& num, vector<bool>& used, vector<int>& tmp, vector<vector<int> >& result, int startPos)
{
        if(startPos==num.size())
        {
            result.push_back(tmp);
            return;
        }
        
        for(int i=0; i<num.size(); i++)
        {
            if(i>0 && num[i]==num[i-1] && !used[i-1]) // when duplicate meets, give it an ordering
                continue;
            if(!used[i])
            {
                tmp.push_back(num[i]);
                used[i]=true;
                permuteUnique(num, used, tmp, result, startPos+1);
                used[i]=false;
                tmp.pop_back();
            }
        }
}
