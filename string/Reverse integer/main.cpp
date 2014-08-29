#include<sstream>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int reverse(int x);

int main()
{
	int a=123;
	int b=-123;
	cout<<reverse(a)<<endl;
	cout<<reverse(b)<<endl;
	return 0;
}

int reverse(int x)
{
	ostringstream ss;
	ss<<x;
	string s=ss.str();
	int sign=1;
	if(s[0]=='-')
	{
		sign=-1;
		s=s.substr(1, s.size()-1);
	}
	reverse(s.begin(), s.end());
	int result=atoi(s.c_str());
	if(sign==-1)
		result=result*sign;
	return result;
}
