// reference: http://www.hawstein.com/posts/1.6.html
/*
我们假设要将图像逆时针旋转90度，顺时针是一个道理。如果原图如下所示：
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16
那么逆时针旋转90度后的图应该是：
4 8 12 16 
3 7 11 15 
2 6 10 14 
1 5 9 13
我们要如何原地进行操作以达到上面的效果呢？可以分两步走。 第一步交换主对角线两侧的对称元素，
第二步交换第i行和第n-1-i行，即得到结果。 看图示：
原图：           第一步操作后：   第二步操作后：
1 2 3 4         1 5 9 13        4 8 12 16
5 6 7 8         2 6 10 14       3 7 11 15
9 10 11 12      3 7 11 15       2 6 10 14
13 14 15 16     4 8 12 16       1 5 9 13
对于顺时针旋转：先交换主对角线元素，再交换列向量
原图：           第一步操作后：   第二步操作后：
1 2 3 4         1 5 9 13        13 9  5 1
5 6 7 8         2 6 10 14       14 10 6 2
9 10 11 12      3 7 11 15       15 11 7 3
13 14 15 16     4 8 12 16       16 12 8 4
*/

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
