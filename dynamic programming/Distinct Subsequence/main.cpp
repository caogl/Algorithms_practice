// reference: http://www.cnblogs.com/TenosDoIt/p/3440022.html

#include<vector>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;

int numDistinct(string S, string T);

/* the recursive solution, more natural for this case, but runtime error for big test cases---call stacks!
int numDistinct(string S, string T);
void numDistinct(string S, int Spos, string T, int Tpos, int& num);
*/

int main()
{
	string S="chuuchunleiunllei";
	string T="chunlei";
	cout<<numDistinct(S, T)<<endl;	
	return 0;
}

int numDistinct(string S, string T)
{
	int lenS=S.size();
	int lenT=T.size();
	/* notice corner cases!!! */
	if(lenT==0)
		return 1;
	if(lenS==0)
		return 0;
	int dp[lenS+1][lenT+1]; // size to be [+1][+1]
	memset(dp, 0, sizeof(dp));
	
	/* starting values !!! */
	for(int i=0; i<=lenS; i++)
		dp[i][0]=1;

	for(int i=1; i<=lenS; i++)
	{
		for(int j=1; j<=lenT; j++)
		{
			if(S[i-1]==T[j-1])
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
			else	
				dp[i][j]=dp[i-1][j];
		}
	}
	
	return dp[lenS][lenT];
}

/*
int numDistinct(string S, string T)
{
	int num=0;
	numDistinct(S, S.size()-1, T, T.size()-1, num);
	return num;
}

void numDistinct(string S, int Spos, string T, int Tpos, int& num)
{
	if(Tpos<0)
	{
		num++;
		return;
	}
	if(Spos<0)
		return;
	while(S[Spos]!=T[Tpos])
		Spos--;
	if(Spos<0)
		return;
	numDistinct(S, Spos-1, T, Tpos-1, num);
	numDistinct(S, Spos-1, T, Tpos, num);
}
*/
