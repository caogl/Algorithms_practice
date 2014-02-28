#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;

vector<string> genePerm(const string str);
void genePerm(vector<string>& result, string str, string& out, vector<bool>& used);
vector<string> geneComb(const string str);
void geneComb(vector<string>& result, string str, string& out, int startPos);

int main()
{
	string inChar="abc";
	vector<string> result=genePerm(inChar);
	for(unsigned int i=0; i<result.size(); i++)
		cout<<result[i]<<endl;
	result=geneComb(inChar);
	for(unsigned int i=0; i<result.size(); i++)
		cout<<result[i]<<endl;
	system("PAUSE");
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
		out+=str[i];
		result.push_back(out);
		geneComb(result, str, out, i+1);
		out=out.substr(0, out.size()-1);
	}
}

vector<string> genePerm(const string str)
{
	vector<string> result;
	vector<bool> used(str.size(), false);
	string out;
	genePerm(result, str, out, used);
	return result;
}
void genePerm(vector<string>& result, string str, string& out, vector<bool>& used)
{
	if(str.size()==out.size())
	{
		result.push_back(out);
		return;
	}
	for(unsigned int i=0; i<str.size(); i++)
	{
		if(used[i]){}
		else
		{
			out+=str[i];
			used[i]=true;
			genePerm(result, str, out, used);
			used[i]=false;
			out=out.substr(0, out.size()-1);
		}
	}
}
