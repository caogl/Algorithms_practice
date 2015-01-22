// reference: http://www.geeksforgeeks.org/longest-common-substring/
// Google Interview question: optimize the space usage 
//			      --> optimize to linear at best

#include<cstring>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int LongestCommonSubstring(string &s1, string &s2); // space: O(m*n)
int LCSGoogle(string s1, string s2); // space: O(n)

int main()
{
	string s1="Site:GeeksforGeekshahahahaa.org";
	string s2="NewSite:GeeksQuizhahahahab.com";
	cout<<LongestCommonSubstring(s1, s2)<<endl;
	cout<<LCSGoogle(s1, s2)<<endl;
	return 0;
}

int LCSGoogle(string s1, string s2)
{
	int dp[s2.size()+1]; 
	int i=0;
	int maxLen=-1;
	memset(dp, 0, sizeof(dp));
	for(i=1; i<=s1.size(); i++)
	{
		// Important to follow this order, or it will produce a "gradually replace" problem!!!
		// or we can use two vectors, O(2*m) and update interchangably
		// if not, the change of the vector would be: 
		/*	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
			0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
			0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
			0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
			0 1 0 0 0 0 1 0 0 1 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
 			--> gradually changing problem */
		for(int j=s2.size(); j>=1; j--)
		{	
			if(s1[i-1]==s2[j-1])
			{
				maxLen=max(maxLen, dp[j-1]+1);
				dp[j]=dp[j-1]+1;
			}
			else
				dp[j]=0;
		}
	}
	return maxLen;
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
