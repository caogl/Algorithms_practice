#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string convertToTitle(int n);

int main()
{
	cout<<convertToTitle(26)<<endl; // "Z"
	cout<<convertToTitle(27)<<endl; // "AA"
	cout<<convertToTitle(26*26*26)<<endl; // "YYZ"
	cout<<convertToTitle(25*26*26)<<endl; // "XYZ"
	return 0;
}

string convertToTitle(int n)
{
        string result;
        n--;
        while(n/26>0)
        {
            int tmp=n%26;
            char tmp1='A'+tmp;
            ostringstream ss;
            ss<<tmp1;
            result=ss.str()+result;
            n/=26;
            n--;
        }
        int tmp=n%26;
        char tmp1='A'+tmp;
        ostringstream ss;
        ss<<tmp1;
        result=ss.str()+result;
        return result;
}
