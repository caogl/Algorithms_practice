#include<iostream>
//#include<cctype>
//#include<locale>
#include<string>
using namespace std;

bool isPalindrome(string s);

int main()
{
	string s1="A man, a plan, a canal: Panama";
	string s2="race a car";
	string s3=" ";
	string s4="A man, a pl:an, a canal: ...Panama";
	if(isPalindrome(s1))
		cout<<"s1 is palindrome"<<endl;
	else
		cout<<"s1 is not palindrome"<<endl;
	if(isPalindrome(s2))
		cout<<"s2 is palindrome"<<endl;
	else
		cout<<"s2 is not palindrome"<<endl;
	if(isPalindrome(s3))
		cout<<"s3 is palindrome"<<endl;
	else
		cout<<"s3 is not palindrome"<<endl;
	if(isPalindrome(s4))
		cout<<"s4 is palindrome"<<endl;
	else
		cout<<"s4 is not palindrome"<<endl;
	return 0;
}

bool isPalindrome(string s) 
{
	if (s.size()==0)   {return true;}     
    int st = 0;
    int ed = s.size()-1;
    while(st<ed)
    {
        while(isalnum(s[st])==false)
        {
            st++;
            if(st==ed)
                return true;
        }
        while(isalnum(s[ed])==false)
        {
            ed--;
            if(st==ed)
                return true;
        }
        if (tolower(s[ed])!=tolower(s[st]))
		{
            return false;
		}
        else
		{
            st++;
            ed--;
        }
    }
	return true;
}
