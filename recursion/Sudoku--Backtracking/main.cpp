#include<iostream>
#include<vector>
using namespace std;

void solveSudoku(vector<vector<char> > &board);
bool solveSudoku(vector<vector<char> > &board, vector<vector<char> >& result);
bool isValid(vector<vector<char> >& board, int i, int j);

int main()
{
	char a[][9]={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},
{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},
{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
	
	vector<char> tmp(9);
	vector<vector<char> > board(9, tmp);
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
			board[i][j]=a[i][j];
			
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}


	cout<<"The sudoku solution is: "<<endl;
	solveSudoku(board);
	
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

bool isValid(vector<vector<char> >& board, int i1, int j1)
{
	for(int i=0; i<9; i++)
	{
		if((i1!=i || j1!=j) && (board[i1][j1]==board[i][j]))
			return false;
	}
	
	int rowNum=i1/3;
	rowNum*=3;
	int colNum=j1/3;
	colNum*=3;
	for(int i=rowNum; i<rowNum+3; i++)
	{
		for(int j=colNum; j<colNum+3; j++)
		{
			if((i1!=i || j1!=j) && (board[i1][j1]==board[i][j]))
				return false;
		}
	}

	return true;
}

bool solveSudoku(vector<vector<char> > &board, vector<vector<char> >& result)
{
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			if(board[i][j]=='.')
			{
				for(char k='1'; k<='9'; k++)
				{
					board[i][j]=k;
					if(isValid(board, i, j) && solveSudoku(board, result))
					{
						return true;
					}
					board[i][j]='.';
				}
				return false;
			}
		}
	}
	
	/* base case !!!*/
	// if all the cells are filled, would skip the two for loops and reach here
	result=board;
	return true;	
}

void solveSudoku(vector<vector<char> > &board)
{
	vector<vector<char> > result;
	solveSudoku(board, result);
	board=result;
}
