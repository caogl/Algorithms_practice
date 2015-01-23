// DP solution reference: http://yucoding.blogspot.com/2013/01/leetcode-question-27-interleaving-string.html

#include<string>
#include<vector>
#include<iostream>
using namespace std;

/* Solution (1): Recusion, time complexity: O(2^n), n=min(s1.size(), s2.size()), space: O(n), n=max(s1.size(), s2.size())
void isInterleave(string s1, string s2, string s3, bool& match); */

/* Solution (2): Dynamic Programming, time complexity: O(m*n), space: O(m*n)*/
bool isInterleave(string s1, string s2, string s3);

int main()
{
	string s1="abbbbbbcabbacaacccababaabcccabcacbcaabbbacccaaaaaababbbacbb";
	string s2="ccaacabbacaccacababbbbabbcacccacccccaabaababacbbacabbbbabc";
	string s3="cacbabbacbbbabcbaacbbaccacaacaacccabababbbababcccbabcabbaccabcccacccaabbcbcaccccaaaaabaaaaababbbbacbbabacbbacabbbbabc";
	cout<<isInterleave(s1, s2, s3)<<endl;
	return 0;
}

/* Solution (2)*/
bool isInterleave(string s1, string s2, string s3)
{
	int n1=s1.size();
	int n2=s2.size();
	int n3=s3.size();
	if(n1+n2!=n3)
		return false;

	//dp[i][j] means whether s1[0...i-1] and s2[0...j-1] can be interleaved to s3[0...i+j-1]
	vector<vector<bool> > dp(n1+1, vector<bool> (n2+1, false));	
	dp[0][0]=true; // important initialization

	/* Be very careful about the index of the strings --- i-1 !!!*/
	for(int i=1; i<=n1; i++)
		if(dp[i-1][0] && s1[i-1]==s3[i-1])
			dp[i][0]=true;
	for(int i=1; i<=n2; i++)
		if(dp[0][i-1] && s2[i-1]==s3[i-1])
			dp[0][i]=true;

	for(int i=1; i<=n1; i++)
	{
		for(int j=1; j<=n2; j++)
		{
			if((dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1]))
				dp[i][j]=true;
		}
	}
	return dp[n1][n2];
}

/* solution (1)
bool isInterleave(string s1, string s2, string s3)
{
        if(s3.size()!=s1.size()+s2.size())
            return false;
        bool match=false;
        isInterleaving(s1, s2, s3, match);
        return match;
}

void isInterleaving(string s1, string s2, string s3, bool& match)
{
        if(match)   return;
        if(s1.size()==0 && s2.size()==0)
        {
            match=true;
            return;
        }

        if(s1.size()!=0 && s3[0]==s1[0])
            isInterleaving(s1.substr(1), s2, s3.substr(1), match);
        if(s2.size()!=0 && s3[0]==s2[0])
            isInterleaving(s1, s2.substr(1), s3.substr(1), match);
}*/
