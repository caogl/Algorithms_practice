#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	dict.insert("cog");
	string start("hit");
	string end("cog");
	vector<vector<string> > result=findLadders(start, end, dict);
	for(int i=0; i<result.size(); i++)
	{
		for(int j=0; j<result[i]; j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
