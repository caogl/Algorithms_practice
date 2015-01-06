#include<vector>
#include<iostream>
using namespace std;

vector<vector<int> > generateMatrix(int n);

int main()
{
	vector<vector<int> > matrix=generateMatrix(4);
	for(int i=0; i<matrix.size(); i++)
	{
		for(int j=0; j<matrix[i].size(); j++)
			cout<<matrix[i][j]<<"	";
		cout<<endl;
	}
	return 0;
}

vector<vector<int> > generateMatrix(int n)
{
	int num=0;
	vector<vector<int> > matrix(n, vector<int>(n, 0)); // if not yet filled position, number is 0
	if(n==0)
		return matrix;
	int i=0;
	int j=0;
	matrix[i][j]=1; // important initialization, without it, would fall into dead loop!
	                //  |--| since the [0][0] is not initialized and has a value 0 in first outer while, when
	                //  |  | return, cannot go right, deadloop!  
	                //  |  |
	                //  |--|
	num++;
	while(num<n*n)
	{
		while(j+1<n && matrix[i][j+1]==0) // prone to error, be careful, first check then use ++/--
			matrix[i][++j]=++num;
		while(i+1<n && matrix[i+1][j]==0)
			matrix[++i][j]=++num;
		while(j-1>=0 && matrix[i][j-1]==0)
			matrix[i][--j]=++num;
		while(i-1>=0 && matrix[i-1][j]==0)
			matrix[--i][j]=++num;
	}
	return matrix;
}
