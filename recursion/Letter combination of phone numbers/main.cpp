#include<vector>
#include<string>
#include<iostream>
using namespace std;

void combination(string& c, const vector<string>& index, vector<string>& result, string digits);
vector<string> letterCombinations(string digits);

int main()
{
	string digits="23";
	vector<string> result=letterCombinations(digits);
	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<endl;
	return 0;
}

void combination(string& c, const vector<string>& index, vector<string>& result, string digits)
{
	if(c.size()==digits.size())
	{
		result.push_back(c);
		return;
	}
	for(int i=0; i<index[digits[c.size()]-'0'-2].size(); i++)
	{
		string c1=c+index[digits[c.size()]-'0'-2][i];
		combination(c1, index, result, digits);
	}
}

vector<string> letterCombinations(string digits)
{
        vector<string> result;
        vector<string> index(8);
        index[0]="abc";
        index[1]="def";
        index[2]="ghi";
        index[3]="jkl";
        index[4]="mno";
        index[5]="pqrs";
        index[6]="tuv";
        index[7]="wxyz";
        string c="";
        combination(c, index, result, digits);
        return result;
}
