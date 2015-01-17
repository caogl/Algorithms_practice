// reference: http://fisherlei.blogspot.com/2013/01/leetcode-scramble-string.html

#include<iostream>
#include<string>
#include<cstring>
using namespace std;

bool isScramble(string s1, string s2);

int main()
{
	string s="great";
	string s1="rgtae";
	string s2="egatr";
	cout<<isScramble(s, s1)<<endl;
	cout<<isScramble(s, s2)<<endl;
	return 0;
}

bool isScramble(string s1, string s2)
{
	if(s1.size()!=s2.size())
		return false;
	int check[26];
	memset(check, 0, 26*sizeof(check[0]));
	for(int i=0; i<s1.size(); i++)
		check[s1[i]-'a']++;
	for(int i=0; i<s2.size(); i++)
		check[s2[i]-'a']--;
	for(int i=0; i<26; i++)
		if(check[i]!=0)
			return false;
	if(s1.size()<=1) // as long as there are only 3 chars, they can be scrambled to convert
			 //if there are 4, not: abcd VS bdac
		return true;

	for(int i=1; i<s1.size(); i++)
	{
		bool b1=isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, s1.size()-i), s2.substr(i, s2.size()-i));
		bool b2=isScramble(s1.substr(0, i), s2.substr(s2.size()-i, i)) && isScramble(s1.substr(i, s1.size()-i), s2.substr(0, s2.size()-i));
		if(b1 || b2)
			return true;	
	}
	return false;
}
