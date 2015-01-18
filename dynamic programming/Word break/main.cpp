#include<vector>
#include<string>
#include<unordered_set>
#include<iostream>
using namespace std;

// (1) recursive solution is trival, however, can be pretty slow for test case (2)
bool wordBreakR(string s, unordered_set<string> &dict);
void help(string s, unordered_set<string>& dict, bool& find);

// (2) dp, for each position record whether from start position to here can be partitioned so that 
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


	dict.clear();
	// test case (2)
	vector<string> tmp={"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	for(int i=0; i<tmp.size(); i++)
		dict.insert(tmp[i]);
	cout<<wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", dict);
	cout<<"Now begins the recursive solution"<<endl;
	cout<<wordBreakR("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", dict);

	return 0;
}

bool wordBreakR(string s, unordered_set<string> &dict)
{
        bool find=false;
        help(s, dict, find);
        return find;
}

void help(string s, unordered_set<string>& dict, bool& find)
{
        if(find)    return;
        if(s.size()==0)
        {
            find=true;
            return;
        }
        for(int i=1; i<=s.size(); i++)
        {
            if(dict.find(s.substr(0, i))!=dict.end())
                help(s.substr(i, s.size()-i), dict, find);
        }
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
