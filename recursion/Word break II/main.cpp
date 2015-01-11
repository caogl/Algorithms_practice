#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

vector<string> wordBreak(string s, unordered_set<string> &dict);
void wordBreak(string& s, unordered_set<string> &dict, int start, string& tmp, vector<bool>& promise, vector<string>& result);

int main()
{
	string s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	unordered_set<string> dict;
	string str[]={"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	for(int i=0; i<10; i++)	dict.insert(str[i]);
	vector<string> result=wordBreak(s, dict);
	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<endl;
	cout<<endl;

	s="aaaaaaa";
	dict.clear();
	string str1[]={"aaa","aaaa"};
	for(int i=0; i<2; i++)	dict.insert(str1[i]);
	result=wordBreak(s, dict);
	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<endl;
	cout<<endl;

	return 0;
}

vector<string> wordBreak(string s, unordered_set<string> &dict)
{
        string tmp;
        vector<string> result;
	vector<bool> promise(s.size()+1, true);
        wordBreak(s, dict, 0, tmp, promise, result);
        return result;
}
    
void wordBreak(string& s, unordered_set<string> &dict, int start, string& tmp, vector<bool>& promise, vector<string>& result)
{
        if(start==s.size())
        {
            result.push_back(tmp.substr(0, tmp.size()-1));
            return;
        }
        
        for(int i=start; i<s.size(); i++)
        {
            string str=s.substr(start, i-start+1);
            if(dict.find(str)!=dict.end() && promise[i+1])
            {
		int n=tmp.size();
                tmp=tmp+str+" ";
		int before=result.size();
                wordBreak(s, dict, i+1, tmp, promise, result);
		promise[i+1]=(before!=result.size());
                tmp=tmp.substr(0, n);
            }
        }
}
