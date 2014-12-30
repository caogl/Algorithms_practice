#include<vector>
#include<string>
#include<iostream>
using namespace std;

vector<vector<string> > solveNQueens(int n);
void solveNQueens(vector<vector<string> >& result, vector<int>& tmp, int current, int n);
vector<string> convert(vector<int>& tmp);

int main()
{
	vector<vector<string> > result=solveNQueens(4);
	
	for(int i=0; i<result.size(); i++)
	{
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<endl;
		cout<<endl;
	}
	return 0;
}

vector<vector<string> > solveNQueens(int n) 
{
        vector<vector<string> > result;
        vector<int> tmp;
        int current;
        solveNQueens(result, tmp, 0, n);
        return result;
}

void solveNQueens(vector<vector<string> >& result, vector<int>& tmp, int current, int n)
{
        if(current==n)
        {
            vector<string> vec=convert(tmp);
            result.push_back(vec);
            return;
        }
        
        for(int i=0; i<n; i++)
        {
            tmp.push_back(i);
            bool promise=true;
            for(int j=0; j<current; j++) // easy to cause bug: tend to use i instead of current 
            {
                if(tmp[current]==tmp[j] || current-j==abs(tmp[current]-tmp[j]))
                {
                    promise=false;
                    break;
                }
            }
            if(promise)
                solveNQueens(result, tmp, current+1, n);
            tmp.pop_back();
        }
}

vector<string> convert(vector<int>& tmp)
{
        vector<string> result;
        for(int i=0; i<tmp.size(); i++)
        {
            string str(tmp.size(), '.');
            str[tmp[i]]='Q';
            result.push_back(str);
        }
        return result;
}
