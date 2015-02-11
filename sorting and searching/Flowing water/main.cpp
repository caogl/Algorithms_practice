// reference: http://www.fgdsb.com/2015/02/09/elevation-matrix/#more
/*
输入是一个 N*N的矩阵，代表地势高度。如果下雨水流只能流去比他矮或者一样高的地势。
矩阵左边和上边是太平洋，右边和下边是大西洋。求出所有的能同时流到两个大洋的点。

For example:
Pacific: ~
Atlantic: *
~  ~   ~   ~   ~   ~  ~
~  1   2   2   3  (5) *
~  3   2   3  (4) (4) *
~  2   4  (5)  3   1  *
~ (6) (7)  1   4   5  *
~ (5)  1   1   2   4  *
*  *   *   *   *   *  *
括号里即为结果：
[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]]

Google近期高频题。
Brutal force的解法很简单，每个点搜索一次，接触到太平洋或者大西洋就记录下来。最后扫一遍输出同时能走到两个ocean的点即可。
复杂度为O(n^3)。

优化的话，可以从两个ocean的点开始，从外往里搜。首先搜所有太平洋的点，记录下能接触到的position。然后同理搜大西洋的点，
求出交集即可, 复杂度为O(n^2)。
*/

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
