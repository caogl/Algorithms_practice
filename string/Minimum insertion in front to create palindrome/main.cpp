// google interview question:

/* Given a string S, you are allowed to convert it to a palindrome by adding 0 or more characters in front of it.
   Find the length of the shortest palindrome that you can create from S by applying the above transformation. */

#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string& s, int left, int right);
int minStep(string& s, int left, int right);
int minStep(string& s);

int main()
{
	string s0="aacecaaa";
	cout<<minStep(s0)<<endl; //9
	string s1="acecaaa";
	cout<<minStep(s1)<<endl; //9
	string s2="abcb";
	cout<<minStep(s2)<<endl; //7
	string s3="racexyzart";
	cout<<minStep(s3)<<endl; //19
	return 0;
}

// O(N^2) solution
int minStep(string& s)
{
	return minStep(s, 0, s.size()-1)+s.size();
}

int minStep(string& s, int left, int right)
{
	if(isPalindrome(s, left, right)) return 0;
	return 1+minStep(s, left, right-1);
}

bool isPalindrome(string& s, int left, int right)
{
	while(left<right)
		if(s[left++]!=s[right--])
			return false;
	return true;
}

