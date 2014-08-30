#include<iostream>
#include<utility>
#include<vector>
using namespace std;

int findPath(int graph[][4], int row, int col); //recursive solution
void findPath(int graph[][4], int rowNum, int colNum, int row, int col, int& count);
int findPathDP(int graph[][4], int row, int col); // DP solution

int main()
{
	int graph[][4]={{1,1,1,0}, {1,1,0,1}, {1,1,1,1}};
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<4; j++)
			cout<<graph[i][j]<<" ";
		cout<<endl;
	}
	cout<<"The number of possible path is: "<<findPath(graph, 3, 4)<<endl;
	cout<<"The number of possible path is: "<<findPathDP(graph, 3, 4)<<endl;

	return 0;
}

int findPath(int graph[][4], int row, int col)
{
	int rowNum=0, colNum=0, count=0;
	findPath(graph, rowNum, colNum, row, col, count);
	return count;
}

void findPath(int graph[][4], int rowNum, int colNum, int row, int col, int& count)
{
	if(rowNum==row || colNum==col)
		return;
	if(rowNum==row-1 && colNum==col-1)
	{
		count++;
		return;
	}
	if(graph[rowNum+1][colNum])
		findPath(graph, rowNum+1, colNum, row, col, count);
	if(graph[rowNum][colNum+1])
		findPath(graph, rowNum, colNum+1, row, col, count);
}

int findPathDP(int graph[][4], int row, int col)
{
	vector<int> temp(col, 0);
	vector<vector<int> > vec(row, temp);


	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(graph[i][j]==0)
				vec[i][j]=0;
			else
			{	
				if(i-1<0 && j-1<0)
					vec[i][j]=1;	
				else if(i-1<0)
					vec[i][j]=vec[i][j-1];
				else if(j-1<0)
					vec[i][j]=vec[i-1][j];
				else
					vec[i][j]=vec[i-1][j]+vec[i][j-1];
			}
		}
	}
	
	cout<<endl;
	for(int i=0; i<vec.size(); i++)
	{
		for(int j=0; j<vec[0].size(); j++)
		{
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
	return vec[row-1][col-1];
}

