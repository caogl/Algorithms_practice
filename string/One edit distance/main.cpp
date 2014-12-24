// reference: leetcode clean code handbook
// The definition of edit is the same in the problem "Edit Distance", ONLY return distance 1, and 0 distance is not included!

#include<string>
#include<iostream>
using namespace std;

bool isOneEditDistance(string s, string t);

int main()
{
	string s="bacd";
	string t="abcd";
	cout<<isOneEditDistance(s, t)<<endl;
	s="abXd";
	cout<<isOneEditDistance(s, t)<<endl;
	s="abcXd";
	cout<<isOneEditDistance(s, t)<<endl;
	s="abcdX";
	cout<<isOneEditDistance(s, t)<<endl;		

	return 0;
}

bool isOneEditDistance(string s, string t)
{
	int lens=s.size();
	int lent=t.size();
	if(lent>lens)
		return isOneEditDistance(t, s);
	// from now that the length of s is always greater than t
	
	int lenDiff=lens-lent;
	if(lenDiff>1)
		return false;
	int i=0;
	while(s[i]==t[i] && i<lent) 
		i++;

	if(i==lent) 
		return lenDiff==1;

	if(lenDiff==0)
		i++;
	while(s[i+lenDiff]==t[i] && i<lent)
		i++;
	return i==lent;	
}
