#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<vector<string> > partition(string s);
bool isValid(string& s, int begin, int end);
void find(string s, int startPos, vector<string>& vec, vector<vector<string> >& result);

int main()
{
	string s="aab";
	vector<vector<string> > result=partition(s);
	for(int i=0; i<result.size(); i++)
	{
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

vector<vector<string> > partition(string s)
{
	vector<vector<string> > result;
	vector<string> vec;
	find(s, 0, vec, result);
	return result;
}

bool isValid(string& s, int begin, int end)
{
	while(begin<end)
	{
		if(s[begin]!=s[end])
			return false;
		begin++;
		end--;
	}
	return true;
}

void find(string s, int startPos, vector<string>& vec, vector<vector<string> >& result)
{
	if(startPos>=s.size())
	{
		result.push_back(vec);
		return;
	}
	
	for(int i=startPos; i<s.size(); i++)
	{
		if(isValid(s, startPos, i))
		{
			vector<string> vec1(vec);
			vec1.push_back(s.substr(startPos, i-startPos+1));
			find(s, i+1, vec1, result);
		}
	}
}
