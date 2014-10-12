#include<unordered_set>
#include<string>
#include<queue>
#include<iostream>
using namespace std;

int ladderLength(string start, string end, unordered_set<string> &dict);
unordered_set<string> stringToHash(string* s, int num);

int main()
{
	string dicString[]={"hug", "hot", "hog", "big", "dog", "lot", "bit", "nit", "but", "log", "lag", "lot", "boo", "hat"};
	unordered_set<string> dict=stringToHash(dicString, 14);
	string start="hit";
	string end="cog";
	//correct answer is 4
	cout<<"The shortest transformation length is: "<<ladderLength(start, end, dict)<<endl;
	return 0;
}

unordered_set<string> stringToHash(string* s, int num)
{
	unordered_set<string> hash_set;
	for(int i=0; i<num; i++)
		hash_set.insert(s[i]);
	return hash_set;
}

int ladderLength(string start, string end, unordered_set<string> &dict)
{
	int level=1;
	if(start==end)
		return level;
	int curLevelNum=0; // the number of string in current level
	int prevLevelNum=1; // the number of string in previous level
	unordered_set<string> visited; // already visited strings, no go back
	queue<string> q;
	q.push(start);
	visited.insert(start);
	string curString;
	while(!q.empty())
	{
		curString=q.front();
		q.pop();
		for(int i=0; i<curString.size(); i++)
		{
			string s=curString;
			for(int j=0; j<26; j++)
			{
				s[i]='a'+j;
				if(s==end) //found
					return level+1;
				if(dict.find(s)!=dict.end() && visited.find(s)==visited.end())
				{
					q.push(s);
					curLevelNum++;
					visited.insert(s);
				}
			}
		}
		prevLevelNum--;
		if(prevLevelNum==0)
		{
			level++;
			prevLevelNum=curLevelNum;
			curLevelNum=0;
		}
	}
	return 0;
}
