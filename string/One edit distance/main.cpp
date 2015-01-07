// reference: leetcode clean code handbook
// The definition of edit is the same in the problem "Edit Distance", ONLY return distance 1, and 0 distance is not included!
/*
O(n) runtime, O(1) space – Simple one-pass:

For the case where m is equal to n, it becomes finding if there is exactly one modified 
character. Now let’s assume m ≤ n. (If m > n we could just swap them).
Assume X represents the one-edit character. There are three one-edit distance operations 
that could be applied to S.
(i). Modify operation – Modify a character to X in S.
S = “abcde”
T = “abXde”
(ii). Insert operation – X was inserted before a character in S.
S = “abcde”
T = “abcXde”
(iii). Append operation – X was appended at the end of S.
S = “abcde”
T = “abcdeX”

We make a first pass over S and T concurrently and stop at the first non-matching character between S and T.
(1). If S matches all characters in T, then check if there is an extra character at the end  of T. (Append)
(2). If | n – m | == 1, that means we must skip this non-matching character only in T
and make sure the remaining characters between S and T are exactly matching. (Insert)
(3). If | n – m | == 0, then we skip both non-matching characters in S and T and make 
sure the remaining characters between S and T are exactly matching. (Modify)
*/

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
