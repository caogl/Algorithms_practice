#include<vector>
#include<string>
#include<iostream>
using namespace std;

vector<vector<string> > solveNQueens(int n);
void solveNQueens(int n, int cur, vector<int>& tmp, vector<vector<string> >& result);
vector<string> convert(vector<int>& vec);

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
        int cur=0;
        vector<vector<string> > result;
        vector<int> tmp;
        solveNQueens(n, cur, tmp, result);
        return result;
}


void solveNQueens(int n, int cur, vector<int>& tmp, vector<vector<string> >& result)
{
        if(cur==n)
        {
            vector<string> Queen=convert(tmp);
            result.push_back(Queen);
            return;
        }
        
        for(int i=0; i<n; i++)
        {
            vector<int> tmp1(tmp);
	    tmp1.push_back(i);
            bool prune=false;
            for(int j=0; j<cur; j++)
            {
                if(tmp1[j]==tmp1[cur] || abs(cur-j)==abs(tmp1[cur]-tmp1[j]))
                {
                    prune=true;
                    break;
                }
            }
            if(prune==false)
            {
                solveNQueens(n, cur+1, tmp1, result);
            }
        }
}

/* buggy solution:: easy to make this kind of mistake
void solveNQueens(int n, int cur, vector<int>& tmp, vector<vector<string> >& result)
{
        if(cur==n)
        {
            vector<string> Queen=convert(tmp);
            result.push_back(Queen);
            return;
        }
        
        for(int i=0; i<n; i++)
        {
            tmp.push_back(i); // bug(1): tmp keeps increasing the size, wrong
            bool prune=false;
            for(int j=0; j<cur; j++)
            {
                if(tmp[j]==tmp[i] || abs(i-j)==abs(tmp[i]-tmp[j])) //bug(2)
                {
                    prune=true;
                    break;
                }
            }
            if(prune==false)
            {
                vector<int> tmp1(tmp);
                solveNQueens(n, cur+1, tmp1, result);
            }
        }
}
*/

vector<string> convert(vector<int>& vec)
{
        vector<string> result;
        for(int i=0; i<vec.size(); i++)
        {
            string str(vec.size(), '.');
            str[vec[i]]='Q';
            result.push_back(str);
        }
        return result;
}
