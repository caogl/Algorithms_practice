#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int> > flowingWater(vector<vector<int> >& matrix);
void search(vector<vector<int> >& matrix, vector<vector<bool> >& sea, int i, int j);

int main()
{
	vector<int> vec1={1,2,2,3,5};
	vector<int> vec2={3,2,3,4,4};
	vector<int> vec3={2,4,5,3,1};
	vector<int> vec4={6,7,1,4,5};
	vector<int> vec5={5,1,1,2,4};
	vector<vector<int> > matrix={vec1, vec2, vec3, vec4, vec5};
	vector<pair<int, int> > result=flowingWater(matrix);
	for(int i=0; i<result.size(); i++)
		cout<<result[i].first<<" "<<result[i].second<<endl;
	return 0;
}

void search(vector<vector<int> >& matrix, vector<vector<bool> >& sea, int i, int j)
{
	int n=matrix.size();
	if(i>0 && matrix[i-1][j]>=matrix[i][j] && !sea[i-1][j])
	{
		sea[i-1][j]=true;
		search(matrix, sea, i-1, j);
	}
        if(i<n-1 && matrix[i+1][j]>=matrix[i][j] && !sea[i+1][j])
        {
                sea[i+1][j]=true;
                search(matrix, sea, i+1, j);
        }
        if(j>0 && matrix[i][j-1]>=matrix[i][j] && !sea[i][j-1])
        {
                sea[i][j-1]=true;
                search(matrix, sea, i, j-1);
        }
        if(j<n-1 && matrix[i][j+1]>=matrix[i][j] && !sea[i][j+1])
        {
                sea[i][j+1]=true;
                search(matrix, sea, i, j+1);
        }
}

vector<pair<int, int> > flowingWater(vector<vector<int> >& matrix)
{
	vector<pair<int, int> > result;
	int n=matrix.size();
	vector<vector<bool> > sea1(n, vector<bool>(n, false));
	vector<vector<bool> > sea2(n, vector<bool>(n, false));
	for(int i=0; i<n; i++)
	{
		sea1[0][i]=true;
		sea1[i][0]=true;
		sea2[n-1][i]=true;
		sea2[i][n-1]=true;
	}
	for(int i=0; i<n; i++)
	{
		search(matrix, sea1, 0, i);
		search(matrix, sea1, i, 0);
		search(matrix, sea2, n-1, i);
		search(matrix, sea2, i, n-1);
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(sea1[i][j] && sea2[i][j])
				result.push_back(make_pair(i, j));
	return result;
}
