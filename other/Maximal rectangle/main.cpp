#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int maximalRectangle(vector<vector<char> > &matrix);
int largestRectangleArea(vector<int> &height);

int main()
{
	/*
 *
	char matrix[][8]={{'1','1','1','1','1','1','0','1'},{'1','0','1','0','1','1','1','1'}, {'1','1','0','1','1','1','1','0'}, {'1','1','1','0','1','1','1','0'}};

	vector<char> temp(8);
	vector<vector<char> > vec(4, temp);
	
	for(int i=0; i<4; i++)
		for(int j=0; j<8; j++)
			vec[i][j]=matrix[i][j];

	for(int i=0; i<4; i++)
	{
		for(int j=0; j<8; j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	*/

	char matrix[][5]={{'0','1','1','0','1'},{'1','1','0','1','0'},{'0','1','1','1','0'},{'1','1','1','1','0'},{'1','1','1','1','1'},{'0','0','0','0','0'}};

	vector<char> temp(5);
	vector<vector<char> > vec(6, temp);

	for(int i=0; i<6; i++)
		for(int j=0; j<5; j++)
			vec[i][j]=matrix[i][j];

	for(int i=0; i<6; i++)
	{
		for(int j=0; j<5; j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	cout<<"Max rectangle size is: "<<maximalRectangle(vec)<<endl;
}

int maximalRectangle(vector<vector<char> > &matrix)
{
	if(matrix.size()==0 || matrix[0].size()==0)
		return 0;
	vector<int> temp(matrix[0].size());
	vector<vector<int> > rowNum(matrix.size(), temp);// the continuous ones in row from left to right
	vector<int> temp1(rowNum.size());
	vector<vector<int> > colNum(matrix[0].size(), temp1);

	for(int i=0; i<matrix.size(); i++)
	{
		if(matrix[i][0]=='1')
			rowNum[i][0]=1;
		else
			rowNum[i][0]=0;
		for(int j=1; j<matrix[i].size(); j++)
		{
			if(matrix[i][j]=='1')
				rowNum[i][j]=rowNum[i][j-1]+1;
			else
				rowNum[i][j]=0;
		}
	}

	for(int i=0; i<colNum.size(); i++)
		for(int j=0; j<colNum[0].size(); j++)
			colNum[i][j]=rowNum[j][i];

	
	//demo:
	for(int i=0; i<matrix.size(); i++)
	{
		for(int j=0; j<matrix[0].size(); j++)
			cout<<rowNum[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	int maxSize=0;
	for(int i=0; i<colNum.size(); i++)
	{
		maxSize=max(maxSize, largestRectangleArea(colNum[i]));
		cout<<maxSize<<" ";
	}
	cout<<endl;
	return maxSize;
}


int largestRectangleArea(vector<int> &height)
{
	int maxSize=0;
	for(int i=0; i<height.size(); i++)
	{
		if(i<height.size()-1 && height[i]<=height[i+1]){}
		else
		{
			int minHeight=height[i];
			for(int j=i; j>=0; j--)
			{
				minHeight=min(minHeight, height[j]);
				maxSize=max(maxSize, minHeight*(i-j+1));
			}
		}
	}
	return maxSize;
}
