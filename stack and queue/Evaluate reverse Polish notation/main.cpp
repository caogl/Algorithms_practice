#include<vector>
#include<string>
#include<stack>
#include<iostream>
using namespace std;

int evalRPN(vector<string> &tokens);
vector<string> toVec(string* s, int n);

int main()
{
	string s1[]={"2","1","+","3","*"};
	string s2[]={"4","13","5","/","+"};
	vector<string> vec1=toVec(s1, 5);
	vector<string> vec2=toVec(s2, 5);
	cout<<evalRPN(vec1)<<"	"<<evalRPN(vec2)<<endl;
	return 0;
}

int evalRPN(vector<string> &tokens)
{
	stack<int> s;
	for(int i=0; i<tokens.size(); i++)
	{
		if((tokens[i][0]=='-' && tokens[i].size()>1) || (tokens[i][0]>='0' && tokens[i][0]<='9'))
			s.push(atoi(tokens[i].c_str()));
		else
		{
			int i1=s.top();
			s.pop();
			int i2=s.top();
			s.pop();
			if(tokens[i]=="+")	s.push(i2+i1); //Notice the order of i1 and i2!!!
			if(tokens[i]=="-")	s.push(i2-i1);
			if(tokens[i]=="*")	s.push(i2*i1);
			if(tokens[i]=="/")	s.push(i2/i1);
		}
	}
	return s.top();
}

vector<string> toVec(string* s, int n)
{
	vector<string> vec;
	for(int i=0; i<n; i++)
		vec.push_back(s[i]);
	return vec;
}
