// reference: http://www.cnblogs.com/reachteam/p/4222486.html

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct cmp
{
	bool operator()(const string& a, const string& b)
	{
		return (a+b)>(b+a);
	}
};

string largestNumber(vector<int>& num);

int main()
{
	vector<int> num={3,30,34,5,9};
	cout<<largestNumber(num)<<endl;
	vector<int> num1={0, 0};
	cout<<largestNumber(num)<<endl; // correct result is "0" rather than "00"
	
	return 0;
}

string largestNumber(vector<int>& num)
{
	string result;
	cmp cmp1;
	vector<string> num1(num.size());
	for(int i=0; i<num.size(); i++)
		num1[i]=to_string(num[i]);
	sort(num1.begin(), num1.end(), cmp1);
	for(int i=0; i<num1.size(); i++)
		result+=num1[i];
	if(result[0]=='0')	return "0"; // deal with [0, 0], remove leading zeros
	return result;
}
