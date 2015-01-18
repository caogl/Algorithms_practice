// Google interview question
// reference: (1)http://www.careercup.com/question?id=15422849 (2)Leetcode cleancode official guide new added question

/* Pots of gold game: Two players A & B. There are pots of gold arranged in a line, each containing some gold coins
 * (the players can see how many coins are there in each gold pot - perfect information). 
 * They get alternating turns in which the player can pick a pot from one of the ends of the line. 
 * The winner is the player which has a higher number of coins at the end. 
 * The objective is to "maximize" the number of coins collected by A, assuming B also plays optimally. A starts the game.

 * The idea is to find an optimal strategy that makes A win knowing that B is playing optimally as well. 
 * How would you do that? */

// Question to ask: can we assume that the coin number is even?
// For this question, we assume that the coin number is even.

#include<vector>
#include<iostream>
using namespace std;

/* solution (0), Greedy approach, wrong --> cannot reflect perfect information of player B: B is not playing optimally
 */
int Greedy(vector<int>& coins);
int Greedy(vector<int>& coins, int start, int end);

/* solution (1): Recursive solution, Time complexity: O(4^n), since each recursive call branches into a total of
		 four separate recursive calls, and it could be n levels deep from the very first call.
		 Space: O(n)
 * idea: For player A : he can pick up coin in first place or last place, for each of these case player B 
 * can further pick from * first or last place from remaining coins. Since B has complete information, 
 * he will adopt the strategy that after he picks his coin, when A picks from remaining, A will get smallest 
 * value of coins.
 * This is because amount(A)+Amount(B)=total, B will try to make A get less and in this way he will get more.
 */
int maxCoin(vector<int>& coins);
int maxCoin(vector<int>& coins, int start, int end);

/* solution (2): Recursive + memorization, Time complexity: O(n^2), Space: O(n^2) 
*/
int maxCoinDP(vector<int>& coins);
int maxCoinDP(vector<int>& coins, vector<vector<int> >& dp, int start, int end);

int main()
{
	vector<int> coins1={10,3,12,2,1,2};
	cout<<"the Maximum number of coins A can get is: "<<maxCoin(coins1)<<endl; // 23
	cout<<"the Maximum number of coins A can get using Greedy approach is: "<<Greedy(coins1)<<endl; //24
	cout<<"the Maximum number of coins A can get using Recursion+Memorization is: "<<maxCoinDP(coins1)<<endl; // 23

	return 0;
}

/*solution (0)*/
int Greedy(vector<int>& coins)
{
	return Greedy(coins, 0, coins.size()-1);
}
int Greedy(vector<int>& coins, int start, int end)
{
	if(start>=end)	return 0;
	
	int n1, n2;
	if(start+1<=end && coins[start+1]>coins[end])
		n1=coins[start]+maxCoin(coins, start+2, end);
	else
		n1=coins[start]+maxCoin(coins, start+1, end-1);
	if(start<=end-1 && coins[start]>coins[end-1])
		n2=coins[end]+maxCoin(coins, start+1, end-1);
	else
		n2=coins[end]+maxCoin(coins, start, end-2);
	return max(n1, n2);

}

/*solution (1)*/
int maxCoin(vector<int>& coins)
{
	return maxCoin(coins, 0, coins.size()-1);
}
int maxCoin(vector<int>& coins, int start, int end)
{
	if(start>=end)	return 0;

	int n1=coins[start]+min(maxCoin(coins, start+2, end), maxCoin(coins, start+1, end-1));
	int n2=coins[end]+min(maxCoin(coins, start+1, end-1), maxCoin(coins, start, end-2));
	return max(n1, n2);
}

/*solution (2)*/
int maxCoinDP(vector<int>& coins)
{
	vector<vector<int> > dp(coins.size(), vector<int> (coins.size(), 0));
	return maxCoinDP(coins, dp, 0, coins.size()-1);
}
int maxCoinDP(vector<int>& coins, vector<vector<int> >& dp, int start, int end)
{
	if(start>=end)	return 0;
	if(dp[start][end])	return dp[start][end];
	
	int n1=coins[start]+min(maxCoinDP(coins, dp, start+1, end-1), maxCoinDP(coins, dp, start+2, end));
	int n2=coins[end]+min(maxCoinDP(coins, dp, start+1, end-1), maxCoinDP(coins, dp, start, end-2));
	dp[start][end]=max(n1, n2);
	return max(n1, n2);
}
