// The solution can pass all test cases, but long and ugly, the precise one(those commented) can generate right result, but cannot pass big test cases due to the copy of vectors

#include<vector>
#include<string>
#include<iostream>
using namespace std;

bool exist(vector<vector<char> > &board, string word);
bool exist(vector<vector<char> > &board, vector<vector<bool> >& visited, string& word, string& tmp, int row, int col);

int main()
{
/*
	vector<char> vec1={'A','B','C','E'};
	vector<char> vec2={'S','F','C','S'};
	vector<char> vec3={'A','D','E','E'};
	vector<vector<char> > vec;
	vec.push_back(vec1);
	vec.push_back(vec2);
	vec.push_back(vec3);

	cout<<exist(vec, "ABCCED")<<endl;
	cout<<exist(vec, "SEE")<<endl;
	cout<<exist(vec, "ABCB")<<endl;
*/
	vector<char> vec1={'a','a','a','a'};
	vector<char> vec2={'a','a','a','b'};
	vector<vector<char> > vec;
	vec.push_back(vec1);
	vec.push_back(vec1);
	vec.push_back(vec1);
	vec.push_back(vec1);
	vec.push_back(vec2);
	cout<<exist(vec, "aaaaaaaaaaaaaaaaaaaa")<<endl;

	return 0;
}

bool exist(vector<vector<char> > &board, string word)
{
	if(board.size()==0 || word.size()==0 || word.size()>(board.size()*board[0].size()))
		return false;
	string tmp;
	vector<bool> vec(board[0].size(), false);
	vector<vector<bool> > visited(board.size(), vec);
	
	for(int i=0; i<board.size(); i++)
	{
		for(int j=0; j<board[0].size(); j++)
		{
			if(board[i][j]==word[0])
			{
				tmp+=word[0];
				visited[i][j]=true;
				if(exist(board, visited, word, tmp, i, j))
					return true;
				visited[i][j]=false;
				tmp="";
			}
		}
	}
	
	return false;
}

bool exist(vector<vector<char> > &board, vector<vector<bool> >&visited, string& word, string& tmp, int row, int col)
{
	if(tmp[tmp.size()-1]!=word[tmp.size()-1])
		return false;
	if(tmp==word)
		return true;

	if(row>0 && !visited[row-1][col])
	{
		visited[row-1][col]=true;
		tmp+=board[row-1][col];
		if(exist(board, visited, word, tmp, row-1, col))
			return true;
		tmp=tmp.substr(0, tmp.size()-1);
		visited[row-1][col]=false;
	}
	if(row<board.size()-1 && !visited[row+1][col])
	{
		visited[row+1][col]=true;
		tmp+=board[row+1][col];
		if(exist(board, visited, word, tmp, row+1, col))
			return true;
		tmp=tmp.substr(0, tmp.size()-1);
		visited[row+1][col]=false;
	}
	if(col>0 && !visited[row][col-1])
	{
		visited[row][col-1]=true;
		tmp+=board[row][col-1];
		if(exist(board, visited, word, tmp, row, col-1))
			return true;
		tmp=tmp.substr(0, tmp.size()-1);
		visited[row][col-1]=false;
	}
	if(col<board[0].size()-1 && !visited[row][col+1])
	{
		visited[row][col+1]=true;
		tmp+=board[row][col+1];
		if(exist(board, visited, word, tmp, row, col+1))
			return true;
		tmp=tmp.substr(0, tmp.size()-1);
		visited[row][col+1]=false;
	}
	
	return false;		
}

/*
 * 
bool exist(vector<vector<char> > &board, string word)
{
	if(board.size()==0 || word.size()==0)
		return false;
	string tmp;
	vector<bool> vec(board[0].size(), false);
	vector<vector<bool> > visited(board.size(), vec);
	
	for(int i=0; i<board.size(); i++)
	{
		for(int j=0; j<board[0].size(); j++)
		{
			if(board[i][j]==word[0] && exist(board, visited, word, tmp, i, j))
				return true;
		}
	}
	
	return false;
}

bool exist(vector<vector<char> > &board, vector<vector<bool> >&visited, string& word, string& tmp, int row, int col)
{
	if(tmp.size()>0 && tmp[tmp.size()-1]!=word[tmp.size()-1])
		return false;
	if(tmp==word)
		return true;
	if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || visited[row][col]==true)
		return false;

	vector<vector<bool> >visited1(visited);
	visited1[row][col]=true;
	string tmp1(tmp);
	tmp1+=board[row][col];
	return (exist(board, visited1, word, tmp1, row+1, col) || exist(board, visited1, word, tmp1, row-1, col)
		|| exist(board, visited1, word, tmp1, row, col-1) || exist(board, visited1, word, tmp1, row, col+1));
}

*/
