#include<vector>
#include<string>
#include<unordered_set>
#include<iostream>
using namespace std;

// logic: dp, for each position record whether from start position to here can be partitioned so that 
// each part is in the dictionary

bool wordBreak(string s, unordered_set<string> &dict);

int main()
{
	unordered_set<string> dict;
	dict.insert("leet");
	dict.insert("code");
	dict.insert("online");
	dict.insert("judge");
	cout<<wordBreak("leet", dict);
	cout<<wordBreak("leetcodeonline", dict);
	cout<<wordBreak("onlinejudge", dict);
	cout<<wordBreak("onlinej", dict);
	return 0;
}

bool wordBreak(string s, unordered_set<string> &dict)
{
        vector<bool> vec(s.size()+1, false);
        vec[0]=true;
        for(unsigned int i=1; i<=s.size(); i++)
        {
            for(int j=0; j<i; j++)
            {
                if(vec[j] && dict.find(s.substr(j, i-j))!=dict.end())
                {
                    vec[i]=true;
                    break;
                }
            }
        }
        return vec[s.size()];
}
