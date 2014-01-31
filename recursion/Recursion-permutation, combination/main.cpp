#include<iostream>
#include<string>
#include<vector>
using namespace std;

void genePerm(const vector<char>& in, vector<char>& out, vector<bool>& used);
void geneComb(const vector<char>& in, vector<char>& out, int startPos);

int main()
{
	string inChar="abcd";
	vector<char> in;
	for(unsigned int i=0; i<inChar.length(); i++)
		in.push_back(inChar[i]);
	vector<bool> used;
	used.assign(in.size(), false);
	vector<char> out;
	genePerm(in, out, used);
	out.clear();
	geneComb(in, out, 0);
	system("PAUSE");
	return 0;
}

void geneComb(const vector<char>& in, vector<char>& out, int startPos)
{
	//basecase: startPos==in.size()
	for(unsigned int i=startPos; i<in.size(); i++)
	{
		out.push_back(in[i]);
		for(unsigned int j=0; j<out.size(); j++)
			cout<<out[j];
		cout<<endl;
		if(i<in.size())
			geneComb(in, out, i+1);
		out.pop_back();
	}
}
void genePerm(const vector<char>& in, vector<char>& out, vector<bool>& used)
{
	//basecase
	if(out.size()==in.size())
	{
		for(unsigned int i=0; i<in.size(); i++)
			cout<<out[i];
		cout<<endl;
		return;
	}
	//recursion
	for(unsigned int i=0; i<in.size(); i++)
	{
		if(used[i]){}
		else
		{
			out.push_back(in[i]);
			used[i]=true;
			genePerm(in, out, used);
			used[i]=false;
			out.pop_back();
		}
	}
}
