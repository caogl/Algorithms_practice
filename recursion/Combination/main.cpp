#include<iostream>
#include<string>
#include<vector>
using namespace std;

// generate all combination of a sequence
vector<string> geneComb(const string str);
void geneComb(vector<string>& result, string str, string& out, int startPos);

// leetcode question, generate fixed length combination sequence
vector<vector<int> > combine(int n, int k);
void combine(vector<int>& num, int k, int startPos, vector<int>& tmp, vector<vector<int> >& result);


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
