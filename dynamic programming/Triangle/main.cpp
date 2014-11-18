#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minimumTotal(vector<vector<int> > &triangle);

int main()
{
	vector<int> vec1={1};
	vector<int> vec2={2,5};
	vector<int> vec3={9, 1, 3};
	vector<int> vec4={1, 7, 7, 0};
	vector<vector<int> > vec={vec1, vec2, vec3, vec4};
	cout<<"The minimum is: "<<minimumTotal(vec)<<endl;
	return 0;
}

int minimumTotal(vector<vector<int> > &triangle) 
{
        int n=triangle.size();
        vector<int> result(n, 0);
        vector<int> previous(n, 0);
        result[0]=triangle[0][0];
        previous[0]=triangle[0][0];
        for(int i=1; i<result.size(); i++)
        {
            result[0]=previous[0]+triangle[i][0];
            for(int j=1; j<i; j++)
            {
                result[j]=min(previous[j-1], previous[j])+triangle[i][j];
            }
            result[i]=previous[i-1]+triangle[i][i];
            previous=result;
        }
        return *min_element(result.begin(), result.end());
}
