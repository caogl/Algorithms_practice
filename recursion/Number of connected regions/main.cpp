/*
0 0 1 1 1 1 0 0 
0 0 0 0 1 0 0 0 
0 0 0 0 0 0 0 0 
0 0 0 0 0 0 1 1   ---> number of connected "ones": 5
0 0 0 0 0 0 0 0 
0 0 1 0 1 1 1 0 
0 0 0 1 0 0 0 0 
1 1 0 0 0 0 0 1
*/

#include<iostream>
#include<vector>
using namespace std;

int find_black_regions(vector<vector<bool> >& region);
void make_white(vector<vector<bool> >& region, int i, int j, int rowNum, int colNum);
vector<vector<bool> > makeTestCase(bool test[][8], int size1);
int main()
{
	bool test1[][8]={{0,0,1,1,1,1,0,0},
	{0,0,0,0,1,0,0,0}, {0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1}, {0,0,0,0,0,0,0,0},
	{0,0,1,0,1,1,1,0}, {0,0,0,1,0,0,0,0},
	{1,1,0,0,0,0,0,1}};
	vector<vector<bool> > testCase=makeTestCase(test1, 8);
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
			cout<<testCase[i][j]<<" ";
		cout<<endl;
	}
	int regionNum=find_black_regions(testCase);
	cout<<"The number of connected black region is: "<<regionNum<<endl;
	return 0;
}

vector<vector<bool> > makeTestCase(bool test[][8], int size1)
{
	vector<vector<bool> > testCase(8);
	for(int i=0; i<8; i++)
		testCase[i].assign(size1, false);
	for(int i=0; i<8 ;i++)
		for(int j=0; j<size1; j++)
			testCase[i][j]=test[i][j];
	return testCase;
}

int find_black_regions(vector<vector<bool> >& region)
{
	int colNum=region.size();
	int rowNum=region[0].size();
	int regionNum=0;
	for(int i=0; i<colNum; i++)
	{
		for(int j=0; j<rowNum; j++)
		{
			if(region[i][j]==true)
			{
				regionNum++;
				make_white(region, i, j, rowNum, colNum);
			}
		}
	}
	return regionNum;
}

void make_white(vector<vector<bool> >& region, int i, int j, int rowNum, int colNum)
{
	if(region[i][j]==false)
		return;
	region[i][j]=false;
	if(i>0)
		make_white(region, i-1, j, rowNum, colNum);
	if(i<colNum-1)
		make_white(region, i+1, j, rowNum, colNum);
	if(j>0)
		make_white(region, i, j-1, rowNum, colNum);
	if(j<rowNum-1)
		make_white(region, i, j+1, rowNum, colNum);
	if(i>0 && j>0)
		make_white(region, i-1, j-1, rowNum, colNum);
	if(i>0 && j<rowNum-1)
		make_white(region, i-1, j+1, rowNum, colNum);
	if(i<colNum-1 && j>0)
		make_white(region, i+1, j-1, rowNum, colNum);
	if(i<colNum-1 && j<rowNum-1)
		make_white(region, i+1, j+1, rowNum, colNum);
}
