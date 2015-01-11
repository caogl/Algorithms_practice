// Google interview question for Ma Xiao
/*
example:
	input matrix             	2d matrix storing max value of current node
2	3	4	5			4	3	2	1
4	5	10	11    -----------	9	8	3	2
20	6	9	12    -----------	1	7	4	1
6	7	8	40			7	6	5	1
*/

#include<iostream>
#include<vector>
using namespace std;

int help(vector<vector<int> > &matrix, vector<vector<int> > &info, int i, int j)
{
// This recursive solution is in courtesy of Lai Ting. Once return, the max value of the current node is determined
        if (!info[i][j])
	{
                info[i][j] = 1;
                if (i && matrix[i-1][j] == matrix[i][j]+1)
                	info[i][j] = max(info[i][j], help(matrix, info, i-1, j) + 1);
                if (i != matrix.size()-1 && matrix[i+1][j] == matrix[i][j]+1) 
                	info[i][j] = max(info[i][j], help(matrix, info, i+1, j) + 1);
                if (j && matrix[i][j-1] == matrix[i][j]+1)
                	info[i][j] = max(info[i][j], help(matrix, info, i, j-1) + 1);
                if (j != matrix[0].size()-1 && matrix[i][j+1] == matrix[i][j]+1)
                	info[i][j] = max(info[i][j], help(matrix, info, i, j+1) + 1);
        }
        return info[i][j];
}

int longestPath(vector<vector<int> > &matrix)
{
        if (matrix.empty() && matrix[0].empty()) return 0;

        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int> > info(row, vector<int>(col, 0)); // store the info of the longest length of current node
        int res = 1;

        for (int i=0; i<row; i++)
                for (int j=0; j<col; j++) // O(mn), every node is processed once
                        res = max(res, help(matrix, info, i, j));
        return res;
}

int main(){

        vector<vector<int> > matrix;
        matrix.push_back(vector<int>({2,3,4,5}));
        matrix.push_back(vector<int>({4,5,10,11}));
        matrix.push_back(vector<int>({20,6,9,12}));   // modify the test case
	matrix.push_back(vector<int>({6,7,8,40}));
        cout << longestPath(matrix) << endl;

        return 0;
}
