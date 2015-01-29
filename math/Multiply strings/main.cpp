// reference: http://fisherlei.blogspot.com/2012/12/leetcode-multiply-strings.html

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string multiply(string num1, string num2);

int main()
{
	cout<<multiply("12", "12")<<endl;
	cout<<multiply("99", "99")<<endl;
	return 0;
}

string multiply(string num1, string num2) 
{
	if(num1=="0" || num2=="0") return "0";
	string res(num1.size()+num2.size(), '0');
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	for(int i =0; i < num1.size(); i++)
	{
        	int dig1 = num1[i] -'0';
        	int carry = 0;
        	for(int j = 0; j< num2.size(); j++)
        	{
          		int dig2 = num2[j] - '0';
          		int exist = res[i+j] -'0';
          		res[i+j] = (dig1*dig2+carry+ exist) % 10 +'0';
          		carry = (dig1*dig2+carry+exist)/10;
        	}
        	if(carry >0)
        		res[i+num2.size()] = carry + '0';
	}
      	reverse(res.begin(), res.end());
      	if(res[0]=='0')	return res.substr(1);
      	else	return res;
} 
