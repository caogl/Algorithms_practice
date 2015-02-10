#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int> > &matrix);

int main()
{
	vector<int> vec0={1,2,3};
	vector<int> vec1={4,5,6};
	vector<int> vec2={7,8,9};
	vector<vector<int> > matrix={vec0, vec1, vec2};
	for(int i=0; i<matrix.size(); i++)
	{
		for(int j=0; j<matrix[0].size(); j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	cout<<"After rotate: "<<endl;
	rotate(matrix);
        for(int i=0; i<matrix.size(); i++)
        {
                for(int j=0; j<matrix[0].size(); j++)
                        cout<<matrix[i][j]<<" ";
                cout<<endl;
        }
	return 0;
}

void rotate(vector<vector<int> > &matrix)
{
        int n=matrix.size();
        if(n==0)    return;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<i; j++)
                swap(matrix[i][j], matrix[j][i]);
        for(int j=0; j<n/2; j++)
            for(int i=0; i<n; i++)
                swap(matrix[i][j], matrix[i][n-j-1]);
}
