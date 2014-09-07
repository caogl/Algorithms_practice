#include<string>
#include<iostream>
using namespace std;

int minCut(string s);

int main()
{
	string s="aabchiih";
	cout<<"The mincut is: "<<minCut(s)<<endl;
	return 0;
}

int minCut(string s)
{
	if(s.size()==1)
		return 0;
	int dp[s.size()]; 
	bool isPalindrome[s.size()][s.size()];

	for(int i=0; i<s.size(); i++)
	{
		for(int j=0; j<=i; j++)
		{
			if(s[i]==s[j] && (i-j<2 || isPalindrome[j+1][i-1]))
			{
				isPalindrome[i][j]=true;
				isPalindrome[j][i]=true;
			}
			else
			{
				isPalindrome[j][i]=false;
				isPalindrome[i][j]=false;
			}
		}
	}

	for(int i=0; i<s.size(); i++)
	{
		dp[i]=i;
	}

	for(int i=1; i<s.size(); i++)
	{
		for(int j=0; j<=i; j++)
		{
			if(isPalindrome[j][i])
			{
				if(j==0)
					dp[i]=0;
				else
					dp[i]=min(dp[i], dp[j-1]+1);
			}
		}
	}

	return dp[s.size()-1];
}
