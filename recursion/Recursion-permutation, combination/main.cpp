#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;

void genePerm(const vector<char>& in, vector<char>& out, vector<bool>& used);
void geneComb(const vector<char>& in, vector<char>& out, int startPos);
// generate permutation for upper and lower cases
void genePermUL(const vector<char>& in, vector<char>& out, vector<bool>& used); 
void printUL(vector<char>& in);
void printUL1(vector<char>& out, const vector<vector<char> > in);

int main()
{
	string inChar="abc";
	vector<char> in;
	for(unsigned int i=0; i<inChar.length(); i++)
		in.push_back(inChar[i]);
	vector<bool> used;
	used.assign(in.size(), false);
	vector<char> out;
	genePermUL(in, out, used);
	out.clear();
	geneComb(in, out, 0);
	system("PAUSE");
	return 0;
}

void geneComb(const vector<char>& in, vector<char>& out, int startPos)
{
	if(startPos==in.size())
		return;
	for(int i=startPos; i<in.size(); i++)
	{
		out.push_back(in[i]);
		for(unsigned j=0; j<out.size(); j++)
			cout<<out[j]<<" ";
		cout<<endl;
		geneComb(in, out, i+1);
		out.pop_back();
	}
}
void genePerm(const vector<char>& in, vector<char>& out, vector<bool>& used)
{
	if(out.size()==in.size())
	{
		for(unsigned int i=0; i<out.size(); i++)
			cout<<out[i]<<" ";
		cout<<endl;
		return;
	}
	for(unsigned int i=0; i<in.size(); i++)
	{
		if(used[i]){}
		else
		{
			used[i]=true;
			out.push_back(in[i]);
			genePerm(in, out, used);
			out.pop_back();
			used[i]=false;
		}
	}
}

void genePermUL(const vector<char>& in, vector<char>& out, vector<bool>& used)
{
	if(out.size()==in.size())
	{
		printUL(out);
		return;
	}
	for(unsigned int i=0; i<in.size(); i++)
	{
		if(used[i]){}
		else
		{
			used[i]=true;
			out.push_back(in[i]);
			genePermUL(in, out, used);
			out.pop_back();
			used[i]=false;
		}
	}
}

void printUL(vector<char>& in)
{
	vector<char> out;
	vector<char> tmp(2);
	vector<vector<char> > index(in.size(), tmp); 
	// the elements in the vector are the pair for upper and lower case of the original char
	for(unsigned int i=0; i<in.size(); i++)
	{
		index[i][0]=tolower(in[i]);
		index[i][1]=toupper(in[i]);
	}
	printUL1(out, index);
}

void printUL1(vector<char>& out, const vector<vector<char> > in)
{
	if(out.size()==in.size())
	{
		for(unsigned int i=0; i<out.size(); i++)
			cout<<out[i]<<" ";
		cout<<endl;
		return;
	}
	for(unsigned int i=0; i<in[out.size()].size(); i++)
	{
		out.push_back(in[out.size()][i]);
		printUL1(out, in);
		out.pop_back();
	}
}
