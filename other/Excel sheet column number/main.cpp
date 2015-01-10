#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int titleToNumber(string s);

int main()
{
	cout<<titleToNumber("Z")<<endl; // 26
	cout<<titleToNumber("AA")<<endl; // 27
	cout<<titleToNumber("AB")<<endl; // 28
	cout<<titleToNumber("AAA")<<endl; // 703
	return 0;
}

int titleToNumber(string s)
{
	int result=0;
        reverse(s.begin(), s.end());
        for(int i=0; i<s.size(); i++)
            result+=(s[i]-'A'+1)*pow(26, i);
        return result;
}
