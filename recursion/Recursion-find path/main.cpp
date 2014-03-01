#include<iostream>
#include<utility>
using namespace std;

int findPath(int graph[][4], int row, int col);
void findPath(int graph[][4], int rowNum, int colNum, int row, int col, int& count);

int main()
{
	int graph[][4]={{1,1,1,0}, {0,1,1,1}, {1,1,1,1}};
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<4; j++)
			cout<<graph[i][j]<<" ";
		cout<<endl;
	}
	cout<<"The number of possible path is: "<<findPath(graph, 3, 4)<<endl;
	system("PAUSE");
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
