#include<string>
#include<cstring>
#include<iostream>
using namespace std;

//reference : http://yucoding.blogspot.com/2013/05/leetcode-question-118-valid-number.html

string deleteSpace(const char* s);
bool isValid(string &s);
bool isNumber(const char* s);

int main()
{
	char a[]=" 0.1";
	char b[]="abc";
	char c[]="2e10";
	char d[]=".";
	char e[]="1.";
	char f[]="1.e2";
	char g[]="-1.e+5";
	cout<<isNumber(a)<<isNumber(b)<<isNumber(c)<<isNumber(d)<<isNumber(e)<<isNumber(f)<<isNumber(g)<<endl;
	return 0;
}

// delete starting and trailing zeros
string deleteSpace(const char* s)
{
	if(strlen(s)==0)
		return "";
	int i=0;
	while(s[i]==' ')
		i++;
	int j=strlen(s)-1;
	while(s[j]==' ')
		j--;
	string result="";
	for(int k=i; k<=j; k++)
		result=result+s[k];
	return result;
}

bool isValid(string &s)
{
	int i=0;// position
	// check if '.', 'e' or '0-9' exists before the current position
	bool e=false;
	bool dot=false;
	bool digit=false;
	
	//for the fist char, the number can start with +, -, .
	if(!isdigit(s[0]))
	{
		if(s[0]=='+' || s[0]=='-' || s[0]=='.')
		{
			if(s.size()==1)
				return false;
			if(s[0]=='.')
				dot=true;
		}
		else
			return false;
	}
	else
		digit=true;
	
	for(int i=1; i<s.size()-1; i++)
	{
		switch (s[i])
		{
			case 'e':
			case 'E': // e cannot occur follow +, -
				if(e==false && s[i-1]!='+' && s[i-1]!='-' && digit==true && i!=s.size()-1)
					e=true;
				else
					return false;
				break;
			case '+': // +, - can only occur after e
			case '-':
				if(s[i-1]!='e' && s[i-1]!='E')
					return false;
				break;
			case '.':
				if(dot==false && e==false)
					dot=true;
				else
					return false;
				break;
			default:
				if(isdigit(s[i]))
					digit=true;
				else
					return false;
				break;
		}
	}
	
	if(isdigit(s[s.size()-1]))
		return true;
	if(s[s.size()-1]=='.' && !dot && !e && isdigit(s[s.size()-2]))
		return true;
	return false;
}

bool isNumber(const char* s)
{
	string s1=deleteSpace(s);
	if(s1.size()==0)
		return false;
	return isValid(s1);
}

