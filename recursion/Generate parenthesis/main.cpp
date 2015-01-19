#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> generateParenthesis(int n);
void generateParenthesis(int n, int left, int right, const string& tmp, vector<string>& result);

int main()
{
	vector<string> vec=generateParenthesis(3);
	for(int i=0; i<vec.size(); i++)
		cout<<vec[i]<<endl;
	cout<<endl;
	return 0;
}

vector<string> generateParenthesis(int n) 
{
        vector<string> result;
        string tmp;
        generateParenthesis(n, 0, 0, tmp, result);
        return result;
}

void generateParenthesis(int n, int left, int right, const string& tmp, vector<string>& result)
{
        //base case
        if(left==n && right==n)
        {
            result.push_back(tmp);
            return;
        }
        if(right>left || left>n)
        {
            return;
        }
        
        string tmp1(tmp), tmp2(tmp);
        tmp1+='(';
        generateParenthesis(n, left+1, right, tmp1, result);
        tmp2+=')';
        generateParenthesis(n, left, right+1, tmp2, result);
}
