#include<iostream>
#include<string>
using namespace std;

string longestPalindrome(string s);
string valid(string& s, int left, int right);

int main()
{
	string s1="asdsafabuhmhubaghjfdsagopipoaas";
	cout<<"The longest palindrome in "<<s1<<" is "<<longestPalindrome(s1)<<endl;
return 0;
}

string longestPalindrome(string s)
{
	if(s.size()==0 || s.size()==1)
		return s;
	string result=s.substr(0, 1);
	for(int i=0; i<s.size()-1; i++)
	{
		string s1=valid(s, i, i);
		if(s1.size()>result.size())
			result=s1;
		string s2=valid(s, i, i+1);
		if(s2.size()>result.size())
			result=s2;
	}
	return result;
}

string valid(string& s, int left, int right)
{
	while(left>=0 && right<s.size())
	{
		if(s[left]==s[right])
		{
			left--;
			right++;
		}
		else
			break;
	}
	return s.substr(left+1, right-left-1);
}
