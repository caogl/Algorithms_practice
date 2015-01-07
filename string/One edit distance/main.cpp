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
	s="abc"; // error prone case !!!
	t="ad";
	cout<<isOneEditDistance(s, t)<<endl; // 0
	return 0;
}

    bool isOneEditDistance(string s, string t) 
    {
        int slen=s.size();
        int tlen=t.size();
        if(slen<tlen)
            return isOneEditDistance(t, s);
        
        if(slen-tlen>1) return false;
        
        //(1) same size
        if(slen==tlen)
        {
            int misNum=0;
            for(int i=0; i<slen && misNum<=2; i++)
                misNum+=(s[i]!=t[i]);
            return misNum==1;
        }
       
        int i;
        for(i=0; i<tlen; i++)
            if(s[i]!=t[i])
                break;
        if(i==slen) // (2) if insertion once
            return true;
        else
        {
            int j;
            for(j=i; j<slen; j++)
                if(s[j+1]!=t[j])
                    break;
            return j==slen; // (3) check if append once
        }
        
    }
