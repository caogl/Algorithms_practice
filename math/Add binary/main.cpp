// refer to the "add list" problem in Cracking book
#include<iostream>
#include<string>
#include<algorithm> // for std::reverse && std::min
#include<sstream>
using namespace std;

string addBinary(string a, string b)
{
	if(a=="")
		return b;
	if(b=="")
		return a;
	string result="";
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int carry=0;
	int digit;
	int i=0;
	int min_size=min(a.size(), b.size());
	while(i<min_size)
	{
		carry=(a[i]-'0')+(b[i]-'0')+carry;
		digit=carry%2;
		ostringstream ss;
		ss<<digit;
		result=ss.str()+result;
		carry=carry/2;
		i++;
	}
	while(i<a.size())
	{
		carry=a[i]-'0'+carry;
		digit=carry%2;
		ostringstream ss;
		ss<<digit;
		result=ss.str()+result;
		carry=carry/2;	
		i++;	
	}
	while(i<b.size())
	{
		carry=b[i]-'0'+carry;
		digit=carry%2;
		ostringstream ss;
		ss<<digit;
		result=ss.str()+result;
		carry=carry/2;	
		i++;	
	}
	if(carry>0)
	{
		ostringstream ss;
		ss<<carry;
		result=ss.str()+result;		
	}
	return result;
}

int main()
{
	string a="11";
	string b="1";
	cout<<addBinary(a, b)<<endl;

	string c="10001011";
	  string d="101110";
	cout<<addBinary(c, d)<<endl;

	return 0;
}
