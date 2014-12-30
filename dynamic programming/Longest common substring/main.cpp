// reference: http://www.geeksforgeeks.org/longest-common-substring/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int LongestCommonSubstring(string &s1, string &s2);

int main()
{
	string s1="OldSite:GeeksforGeeks.org";
	string s2="NewSite:GeeksQuiz.com";
	cout<<LongestCommonSubstring(s1, s2)<<endl;
	return 0;
}

int LongestCommonSubstring(string &s1, string &s2)
{
	int result=0;
	int dp[s1.size()+1][s2.size()+1];
	for(int i=0; i<=s1.size(); i++)
		dp[i][0]=0;
	for(int i=0; i<=s2.size(); i++)
		dp[0][i]=0;
	for(int i=1; i<=s1.size(); i++)
	{
		for(int j=1; j<=s2.size(); j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
				result=max(result, dp[i][j]);
			}
			else
				dp[i][j]=0;
		}
	}
	return result;
}
