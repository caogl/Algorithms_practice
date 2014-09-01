#include<vector>
#include<iostream>
#include<queue>
#include<utility>
using namespace std;

void solve(vector<vector<char> > &board);

int main()
{
	char region[][5]={{'X','X','X','X','X'},{'X','O','O','X','X'},{'X','X','O','X','X'},{'O','O','X','O','X'},{'O','X','X','X','O'}};
	vector<char> tmp(5);
	vector<vector<char> > board(5, tmp);
	for(int i=0; i<board.size(); i++)
		for(int j=0; j<board[i].size(); j++)
			board[i][j]=region[i][j];

	for(int i=0; i<board.size(); i++)
	{
		for(int j=0; j<board[i].size(); j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	solve(board);
	
	for(int i=0; i<board.size(); i++)
	{
		for(int j=0; j<board[i].size(); j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
}

void solve(vector<vector<char> > &board)
{
	if(board.size()<=2 || board[0].size()<=0)
		return;
	int m=board.size();
	int n=board[0].size();

	vector<bool> tmp(n, true);
	vector<vector<bool> > bitMap(m, tmp);

	queue<pair<int, int> > q;

	for(int i1=0; i1<m; i1++)
	{
		if(bitMap[i1][0] && board[i1][0]=='O')
		{
			q.push(make_pair(i1, 0));
			bitMap[i1][0]=false;
			while(!q.empty())
			{
				pair<int, int> elem=q.front();
				q.pop();
				int i=elem.first;
				int j=elem.second;
				if(i>1 && bitMap[i-1][j] && board[i-1][j]=='O')
				{
					q.push(make_pair(i-1, j));
					bitMap[i-1][j]=false;
				}
				if(i<m-1 && bitMap[i+1][j] && board[i+1][j]=='O')
				{
					q.push(make_pair(i+1, j));
					bitMap[i+1][j]=false;
				}
				if(j>1 && bitMap[i][j-1] && board[i][j-1]=='O')
				{
					q.push(make_pair(i, j-1));
					bitMap[i][j-1]=false;
				}
				if(j<n-1 && bitMap[i][j+1] && board[i][j+1]=='O')
				{
					q.push(make_pair(i, j+1));
					bitMap[i][j+1]=false;
				}
			}
		}
	}

	for(int i1=0; i1<m; i1++)
	{
		if(bitMap[i1][n-1] && board[i1][n-1]=='O')
		{
			q.push(make_pair(i1, n-1));
			bitMap[i1][n-1]=false;
			while(!q.empty())
			{
				pair<int, int> elem=q.front();
				q.pop();
				int i=elem.first;
				int j=elem.second;
				if(i>1 && bitMap[i-1][j] && board[i-1][j]=='O')
				{
					q.push(make_pair(i-1, j));
					bitMap[i-1][j]=false;
				}
				if(i<m-1 && bitMap[i+1][j] && board[i+1][j]=='O')
				{
					q.push(make_pair(i+1, j));
					bitMap[i+1][j]=false;
				}
				if(j>1 && bitMap[i][j-1] && board[i][j-1]=='O')
				{
					q.push(make_pair(i, j-1));
					bitMap[i][j-1]=false;
				}
				if(j<n-1 && bitMap[i][j+1] && board[i][j+1]=='O')
				{
					q.push(make_pair(i, j+1));
					bitMap[i][j+1]=false;
				}
			}
		}
	}

	for(int j1=0; j1<n; j1++)
	{
		if(bitMap[0][j1] && board[0][j1]=='O')
		{
			q.push(make_pair(0, j1));
			bitMap[0][j1]=false;
			while(!q.empty())
			{
				pair<int, int> elem=q.front();
				q.pop();
				int i=elem.first;
				int j=elem.second;
				if(i>1 && bitMap[i-1][j] && board[i-1][j]=='O')
				{
					q.push(make_pair(i-1, j));
					bitMap[i-1][j]=false;
				}
				if(i<m-1 && bitMap[i+1][j] && board[i+1][j]=='O')
				{
					q.push(make_pair(i+1, j));
					bitMap[i+1][j]=false;
				}
				if(j>1 && bitMap[i][j-1] && board[i][j-1]=='O')
				{
					q.push(make_pair(i, j-1));
					bitMap[i][j-1]=false;
				}
				if(j<n-1 && bitMap[i][j+1] && board[i][j+1]=='O')
				{
					q.push(make_pair(i, j+1));
					bitMap[i][j+1]=false;
				}
			}
		}
	}

	for(int j1=0; j1<n; j1++)
	{
		if(bitMap[m-1][j1] && board[m-1][j1]=='O')
		{
			q.push(make_pair(m-1, j1));
			bitMap[m-1][j1]=false;
			while(!q.empty())
			{
				pair<int, int> elem=q.front();
				q.pop();
				int i=elem.first;
				int j=elem.second;
				if(i>1 && bitMap[i-1][j] && board[i-1][j]=='O')
				{
					q.push(make_pair(i-1, j));
					bitMap[i-1][j]=false;
				}
				if(i<m-1 && bitMap[i+1][j] && board[i+1][j]=='O')
				{
					q.push(make_pair(i+1, j));
					bitMap[i+1][j]=false;
				}
				if(j>1 && bitMap[i][j-1] && board[i][j-1]=='O')
				{
					q.push(make_pair(i, j-1));
					bitMap[i][j-1]=false;
				}
				if(j<n-1 && bitMap[i][j+1] && board[i][j+1]=='O')
				{
					q.push(make_pair(i, j+1));
					bitMap[i][j+1]=false;
				}
			}
		}
	}
	
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(board[i][j]=='O')
			{
				if(bitMap[i][j]==true)
					board[i][j]='X';
			}
		}
	}
}
