// Google/Amazon interview question
 
/* giving n=4, the generated matrix would be:
 * 1  2  3  4
 * 5  6  7  8
 * 9  10 11 12
 * 13 14 15 16
 *
 * the index of the matrix is:
 * (0,0) (0,1) (0,2) (0,3)
 * (1,0) (1,1) (1,2) (1,3) ---------------for every diagonal elements, the row and col index sum are the same
 * (2,0) (2,1) (2,2) (2,3)
 * (3,0) (3,1) (3,2) (3,3)
 *
 * zigzag print: 1 5 2 3 6 9 13 10 7 4 8 11 14 15 12 16
 */

#include<vector>
#include<iostream>
using namespace std;

vector<vector<int> > generateMatrix(int n);
vector<int> zigzag(vector<vector<int> >& vec);

int main()
{
	vector<vector<int> > matrix=generateMatrix(4);
	for(int i=0; i<matrix.size(); i++)
	{
		for(int j=0; j<matrix[i].size(); j++)
			cout<<matrix[i][j]<<"	";
		cout<<endl;
	}
	cout<<endl;
	
	vector<int> result=zigzag(matrix);
	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<" ";
	cout<<endl;
	return 0;
}

vector<int> zigzag(vector<vector<int> >& matrix)
{
	vector<int> result;
	int n=matrix.size();
	if(n==0)
		return result;

	// (1) deal with upper triangle matrix
	for(int i=0; i<n; i++) // notice the "<" rather than "<="
	{
		if(!(i & 1)) // even number
			for(int j=0; j<=i; j++)
				result.push_back(matrix[j][i-j]);
		else
			for(int j=0; j<=i; j++)
				result.push_back(matrix[i-j][j]);
	}

	// (2) deal with lower triangle matrix
	for(int i=n; i<2*n+1; i++)
	{
		int k=i-n+1; // index !!!
		if(!(i & 1)) // even number
			for(int j=k; j<n; j++) // notice the "<" rather than "<="
				result.push_back(matrix[j][i-j]);
		else
			for(int j=k; j<n; j++)
				result.push_back(matrix[i-j][j]);
	}
	return result;
}

vector<vector<int> > generateMatrix(int n)
{
	int num=0;
	vector<vector<int> > matrix(n, vector<int>(n, 0));
	if(n==0)
		return matrix;

	int index=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			matrix[i][j]=++index;
	return matrix;
}
