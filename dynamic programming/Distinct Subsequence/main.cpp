// reference: http://www.cnblogs.com/TenosDoIt/p/3440022.html

#include<vector>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;

/* solution (1): Resurison: time complexcity: O(2^n), space: O(n);
int numDistinct(string S, string T);
void numDistinct(string S, int Spos, string T, int Tpos, int& num); */

/* solution (2): Dynamic Programming: time complexicty: O(n^2), space: O(n^2) */
int numDistinct(string S, string T);


int main()
{
	string S="rabbbit";
	string T="rabbit";
	cout<<numDistinct(S, T)<<endl;

	S="aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe";
	T="bddabdcae";
	cout<<numDistinct(S, T)<<endl;	// recursive solution time limit exceeded
	return 0;
}

/* solution (1) */
int numDistinct(string S, string T)
{
	int lenS=S.size();
	int lenT=T.size();
	/* notice corner cases!!! */
	if(lenT==0)	return 1;
	if(lenS==0)	return 0;
	int dp[lenS+1][lenT+1]; // size to be [+1][+1]
	
	/* starting values, the orders of two for loops cannot be exchanged to ensure that dp[0][0]=1!!! */
	for(int i=0; i<=lenT; i++)
		dp[0][i]=0;
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

/* solution(2)
int numDistinct(string S, string T)
{
	int num=0;
	numDistinct(S, 0, T, 0, num);
	return num;
}

void numDistinct(string S, int Spos, string T, int Tpos, int& num)
{
        if(sPos==S.size())  return;
        if(tPos==T.size())
        {
            num++;
            return;
        }

        if(S[sPos]==T[tPos])
        {
            numDist(S, sPos+1, T, tPos+1, num);
            numDist(S, sPos+1, T, tPos, num);
        }
        else
            numDist(S, sPos+1, T, tPos, num);
        }
}
*/
