/* Follow up:
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution? */

// reference: http://yucoding.blogspot.com/2013/04/leetcode-question-97-set-matrix-zeros.html

#include<iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int> > &matrix);

int main()
{
	vector<int> vec0={1,0,2,3,4,5};
	vector<int> vec1={2,0,2,3,4,5};
	vector<int> vec2={3,1,2,3,4,5};
	vector<vector<int> > matrix={vec0, vec1, vec2};
	for(int i=0; i<matrix.size(); i++)
	{
		for(int j=0; j<matrix[0].size(); j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Set zeros: "<<endl;

	setZeroes(matrix);
	for(int i=0; i<matrix.size(); i++)
	{
		for(int j=0; j<matrix[0].size(); j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

void setZeroes(vector<vector<int> > &matrix)
{
	int m=matrix.size();
	if(m==0)	return;
	int n=matrix[0].size();
	if(n==0)	return;

	bool row0=false, col0=false;
	for(int i=0; i<n; i++)
	{
		if(!matrix[0][i])
		{
			row0=true;
			break;
		}
	}
	for(int i=0; i<m; i++)
	{
		if(!matrix[i][0])
		{
			col0=true;
			break;
		}
	}

	for(int i=1; i<m; i++)
	{
		for(int j=1; j<n; j++)
		{
			if(!matrix[i][j])
			{
				matrix[0][j]=0;
				matrix[i][0]=0;
			}
		}
	}

	for(int j=1; j<n; j++)
	{
		if(!matrix[0][j])
		for(int i=1; i<m; i++)
			matrix[i][j]=0;
	}
	for(int i=1; i<m; i++)
	{
		if(!matrix[i][0])
		for(int j=1; j<n; j++)
			matrix[i][j]=0;
	}
	
	if(row0)
	{
		for(int j=0; j<n; j++)
			matrix[0][j]=0;
	}
	if(col0)
	{
		for(int i=0; i<m; i++)
			matrix[i][0]=0;
	}
}
