#include<vector>
#include<iostream>
using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix);

int main()
{
	vector<int> vec1={1,2,3,4};
	vector<int> vec2={5,6,7,8};
	vector<int> vec3={9,10,11,12};
	vector<int> vec4={13,14,15,16};
	vector<vector<int> > matrix={vec1, vec2, vec3, vec4};
	vector<int> result=spiralOrder(matrix);
	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<" ";
	return 0;
}

vector<int> spiralOrder(vector<vector<int> > &matrix)
{
	vector<int> result;
	if (matrix.empty())
		return result;
	if (matrix.size()==1)
		return matrix[0];
	int num=0; // the visited number;
	int m=matrix.size();
	int n=matrix[1].size();
	vector<vector<bool> > visited(m, vector<bool>(n, false)); // visited or not
	int i=0;
	int j=0;
	visited[i][j]=true;
	num++;
	result.push_back(matrix[i][j]);
	while(num<n*m) // the termination condition is < rather than <=, or the loop won't end
	{
		while(j+1<n && !visited[i][j+1]) // go to the very unvisited right
		{
			result.push_back(matrix[i][j+1]);
			visited[i][j+1]=true;
			j++;
			num++;
			//cout<<"right "<<num<<endl;
		}
		while(i+1<m && !visited[i+1][j]) // go to the very unvisited bottom
		{
			result.push_back(matrix[i+1][j]);
			visited[i+1][j]=true;
			i++;
			num++;
			//cout<<"down "<<num<<endl;
		}
		while(j-1>=0 && !visited[i][j-1]) // go to the very unvisited left
		{
			result.push_back(matrix[i][j-1]);
			visited[i][j-1]=true;
			j--;
			num++;
			//cout<<"left "<<num<<endl;
		}
		while(i-1>=0 && !visited[i-1][j]) // go to the very unvisited up
		{
			result.push_back(matrix[i-1][j]);
			visited[i-1][j]=true;
			i--;
			num++;
			//cout<<"up "<<num<<endl;
		}
		//cout<<"num: "<<num<<endl;
	}
	return result;
} 
