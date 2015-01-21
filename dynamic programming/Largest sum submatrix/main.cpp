// Google Interview Question
// Cracking the coding interview 18.12, reference: http://www.hawstein.com/posts/20.12.html

#include<vector>
#include<iostream>
using namespace std;

/* Solution(1): brute force --> totally O(n^4) submatrices, each requires O(n^2) computation --> O(n^6)*/

/* Solution(2): dynamic programming in preprocessing, reduce the time of computing the submatrices to O(1) -->O(n^4) */
vector<vector<int> > preCompute(vector<vector<int> >& matrix);
int maxSubMatrix(vector<vector<int> >& matrix);

/* solution(3): (a) dynamic programming in preprocessing  -->O(n^2)
 * 		(b) for each column sum between i and j  -->O(n^2)
 * 			for each row we can compute a value which is sum(a[i, k] ... a[j, k])  -->O(n)
 * 			then use dynamic programming approach that solves "maimum continuous subarray" to get maximum
 *
 * 		(a)+(b)=O(n^2)+O(n^3)=O(n^3)
 */
int main()
{
	vector<int> vec1={1,2,-1,-4,-20};
	vector<int> vec2={-8,-3,4,2,1};
	vector<int> vec3={3,8,10,1,3};
	vector<int> vec4={-4,-1,1,7,-6};
	vector<vector<int> > matrix1={vec1,vec2,vec3,vec4};
	cout<<maxSubMatrix(matrix1)<<endl;

	vector<int> vec5={9,-8,1,3,-2};
	vector<int> vec6={-3,7,6,-2,4};
	vector<int> vec7={6,-4,-4,8,-7};
	vector<vector<int> > matrix2={vec5,vec6,vec7};
	cout<<maxSubMatrix(matrix2)<<endl;

	vector<int> vec8={9,-8,1,-3,-2};
	vector<int> vec9={-3,7,6,-2,4};
	vector<int> vec10={6,-4,-4,-10,17};
	vector<vector<int> > matrix3={vec8,vec9,vec10};
	cout<<maxSubMatrix(matrix3)<<endl;


	return 0;
}

vector<vector<int> > preCompute(vector<vector<int> >& matrix)
{
	vector<vector<int> > result=matrix;
	int m=matrix.size();
	int n=matrix[0].size();
	for(int i=0; i<m; i++)
		for(int j=1; j<n; j++)
			result[i][j]+=result[i][j-1];
	for(int i=1; i<m; i++)
		for(int j=0; j<n; j++)
			result[i][j]+=result[i-1][j];
	return result;
}

int maxSubMatrix(vector<vector<int> >& matrix)
{
	vector<vector<int> > sumMat=preCompute(matrix);
	int m=matrix.size();
	int n=matrix[0].size();
	int maxV=matrix[0][0];
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			maxV=max(maxV, sumMat[i][j]);
	for(int i1=0; i1<m; i1++) // be careful with indexes !!!
	{
		for(int i2=i1+1; i2<m; i2++)
		{
			for(int j1=0; j1<n; j1++)
			{
				for(int j2=j1+1; j2<n; j2++)
				{
					maxV=max(maxV, sumMat[i2][j2]+sumMat[i1][j1]-sumMat[i1][j2]-sumMat[i2][j1]);
				}
			}
		}
	}
	return maxV;
}


