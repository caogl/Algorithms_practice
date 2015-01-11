/*
(0) negative
(1) If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
(2) Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, 
    then the reverse of 1000000003 overflows. How should you handle such cases?
    For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

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
	int c=1534236469;
	cout<<reverse(c)<<endl; // 0
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
	std::reverse(s.begin(), s.end());
	int result=atoi(s.c_str());
	if(sign==-1)
		result=result*sign;
	return result;
}
