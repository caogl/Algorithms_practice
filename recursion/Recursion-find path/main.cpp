#include<iostream>
#include<utility>
using namespace std;

void findPath(int graph[][4], pair<int, int> *path, int rowNum, int colNum, int row, int col, int& count);

int main()
{
	int graph[][4]={{1,1,1,0}, {0,1,1,1}, {1,1,1,1}};
	pair<int, int> path[7]; 
	int count=0;
	findPath(graph, path, 3, 4, 0, 0, count);
	cout<<"The number of possible path is: "<<count<<endl;
	system("PAUSE");
	return 0;
}

void findPath(int graph[][4], pair<int, int> *path, int rowNum, int colNum, int row, int col, int& count)
{
	if(graph[row][col]==0 || row==rowNum || col==colNum) // Notice the attainable inf of row and col should be rowNum-1 and colNum-1!!
		return;
	path[row+col]=make_pair(row, col);
	if((row+col)==(rowNum+colNum-2))
	{
		count++;
		for(int i=0 ;i<=(rowNum+colNum-2); i++)
			cout<<"("<<path[i].first<<","<<path[i].second<<") ";
		cout<<endl;
	}
	else
	{
		findPath(graph, path, rowNum, colNum, row+1, col, count);
		findPath(graph, path, rowNum, colNum, row, col+1, count);
	}
}

