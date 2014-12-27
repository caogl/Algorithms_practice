#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s);

int main()
{
	string s1="([)]";
	string s2="(([{()}]))";
	string s3="]";
	cout<<isValid(s1)<<endl;
	cout<<isValid(s2)<<endl;
	cout<<isValid(s3)<<endl;

	return 0;
}

bool isValid(string s)
{
	stack<char> stack1;
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]=='[' || s[i]=='{' || s[i]=='(')
			stack1.push(s[i]);
		else
		{
			if(stack1.empty())	return false;
			if(s[i]==']' && stack1.top()!='[')	return false;
			if(s[i]=='}' && stack1.top()!='{')	return false;
			if(s[i]==')' && stack1.top()!='(')	return false;
			stack1.pop();
		}		
	}
	return stack1.empty();
}
