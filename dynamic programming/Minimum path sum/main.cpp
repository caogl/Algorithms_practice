#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int minPathSum(vector<vector<int> > &grid);

int main()
{
	int graph[][5]={{1,8,5,7,3}, {2,6,7,3,2}, {5,2,7,1,6}, {2,4,9,1,4}};
	vector<int> temp(5);
	vector<vector<int> > vec(4, temp);
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<5; j++)
		{
			vec[i][j]=graph[i][j];
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<minPathSum(vec)<<endl;
	return 0;
}

int minPathSum(vector<vector<int> > &grid)
{
	if(grid.size()==0)
		return 0;
	vector<vector<int> > minGrid=grid;
	for(int i=1; i<minGrid.size(); i++)
		minGrid[i][0]+=minGrid[i-1][0];
	for(int j=1; j<minGrid[0].size(); j++)
		minGrid[0][j]+=minGrid[0][j-1];
	for(int i=1; i<minGrid.size(); i++)
	{
		for(int j=1; j<minGrid[0].size(); j++)
		{
			minGrid[i][j]+=min(minGrid[i-1][j], minGrid[i][j-1]);
		}
	}

	cout<<endl;
	for(int i=0; i<minGrid.size(); i++)
	{
		for(int j=0; j<minGrid[0].size(); j++)
		{
			cout<<minGrid[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return minGrid[minGrid.size()-1][minGrid[0].size()-1];
}
