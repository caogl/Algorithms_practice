#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// generate all combination of a sequence, same with leetcode question "subsets"
vector<string> geneComb(const string str);
void geneComb(vector<string>& result, string str, string& out, int startPos);

// leetcode question, generate fixed length combination sequence
vector<vector<int> > combine(int n, int k);
void combine(vector<int>& num, int k, int startPos, vector<int>& tmp, vector<vector<int> >& result);

// leetcode question "subsets II"
vector<vector<int> > subsetsWithDup(vector<int> &S);
void subsets(const vector<int>& S, int startPos, vector<int>& tmp, vector<vector<int> >& result);


int main()
{
	string inChar="1234";
	vector<string> result=geneComb(inChar);
	for(unsigned int i=0; i<result.size(); i++)
		cout<<result[i]<<endl;
	cout<<endl;

	vector<vector<int> > result1=combine(4, 2);
	for(int i=0; i<result1.size(); i++)
	{
		for(int j=0; j<result1[i].size(); j++)
			cout<<result1[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	inChar="2123";
	result=geneComb(inChar);
	for(unsigned int i=0; i<result.size(); i++)
		cout<<result[i]<<endl;
	cout<<endl;

	vector<int> vec={2,1,2,3};
	vector<vector<int> > result2=subsetsWithDup(vec);
	for(unsigned int i=0; i<result2.size(); i++)
	{
		for(int j=0; j<result2[i].size(); j++)
			cout<<result2[i][j];
		cout<<endl;
	}

	return 0;
}

vector<string> geneComb(const string str)
{
	vector<string> result;
	string out;
	int startPos=0;
	geneComb(result, str, out, startPos);
	return result;
}

void geneComb(vector<string>& result, string str, string& out, int startPos)
{
	if(startPos==str.size())
		return;
	for(int i=startPos; i<str.size(); i++)
	{
		string out1(out);
		out1+=str[i];
		result.push_back(out1);
		geneComb(result, str, out1, i+1);
	}
}

vector<vector<int> > combine(int n, int k)
{
        vector<int> num(n);
        for(int i=0; i<n; i++)
            num[i]=i+1;
        vector<vector<int> > result;
        vector<int> tmp;
        combine(num, k, 0, tmp, result);
        return result;
}

void combine(vector<int>& num, int k, int startPos, vector<int>& tmp, vector<vector<int> >& result)
{
        if(tmp.size()==k)
        {
            result.push_back(tmp);
            return;
        }
        if(startPos==num.size())
            return;

        for(int i=startPos; i<num.size(); i++)
        {
            vector<int> tmp1(tmp);
            tmp1.push_back(num[i]);
            combine(num, k, i+1, tmp1, result);
        }
}

vector<vector<int> > subsetsWithDup(vector<int> &S)
{
        vector<vector<int> > result;
        if(S.size()==0)
        {
            return result;
        }
        vector<int> tmp;
        result.push_back(tmp);
        sort(S.begin(), S.end());
        subsets(S, 0, tmp, result);
        return result;
}
    
void subsets(const vector<int>& S, int startPos, vector<int>& tmp, vector<vector<int> >& result)
{
        if(startPos>=S.size())
            return;
        for(int i=startPos; i<S.size(); i++)
        {
            vector<int> tmp1(tmp);
            tmp1.push_back(S[i]);
            result.push_back(tmp1);
            subsets(S, i+1, tmp1, result);
            while(i<S.size()-1 && S[i+1]==S[i]) // These two lines makes a difference and jumps the duplicate!
                i++; //......
        }
}
