// reference: https://oj.leetcode.com/discuss/20718/share-my-c-dp-solution-with-explanation
/* different from the solution to Maximum/Minimum Path Sum, 
 * (1) if use the same dp idea:
       -2    -3     3			-2    -5    -2 
       -5    -10    1	     --->	-7   -15    -1         ---> solution: 28(wrong)
       10    30    -5		 	 3    33    28 

   (2) dp[i][j] means start from point (i,j), to reach point (n-1,m-1), the knight needs at least dp[i][j] health
       dp[i][j] = min( max(dp[i+1][j]-dungeon[i][j], 1), max(dp[i][j+1]-dungeon[i][j], 1) )
       -2    -3     3			 7     5     2 
       -5    -10    1	     --->	 6     11    5         ---> solution: 7 
       10    30    -5		 	 1     1     6 
*/

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int calculateMinimumHP(vector<vector<int> > &dungeon);

int main()
{
	vector<int> tmp1={-2, -3, 3};
	vector<int> tmp2={-5, -10, 1};
	vector<int> tmp3={10, 30, -5};
	vector<vector<int> > dungeon={tmp1, tmp2, tmp3};
	cout<<calculateMinimumHP(dungeon)<<endl;
	vector<int> tmp4={0, 0};
	vector<vector<int> > dungeon1={tmp4};
	cout<<calculateMinimumHP(dungeon1)<<endl;

	return 0;
}

int calculateMinimumHP(vector<vector<int> > &dungeon)
{
	int m=dungeon.size();
	int n=dungeon[0].size();
	int dp[m][n];
	dp[m-1][n-1]=max(1-dungeon[m-1][n-1], 1);
	for(int i=m-2; i>=0; i--)
		dp[i][n-1]=max(dp[i+1][n-1]-dungeon[i][n-1], 1);
	for(int j=n-2; j>=0; j--)
		dp[m-1][j]=max(dp[m-1][j+1]-dungeon[m-1][j], 1);
	for(int i=m-2; i>=0; i--)
		for(int j=n-2; j>=0; j--)
			dp[i][j]=min( max(dp[i+1][j]-dungeon[i][j], 1), max(dp[i][j+1]-dungeon[i][j], 1) );
	return dp[0][0];
}
