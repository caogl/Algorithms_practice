/*
 * idea : keep two levels, and keep a "backtracking precessor" map, then finally recover the route through this map from end to start
 *        cannot use a queue, use a two level data structure, because there are multiple possible shortest paths, we need to maintain
 *        the whole layer, because any word in this layer may be a precessor to "end"
 */

#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict);
void generatePath(unordered_map<string, vector<string> > &prevWord, vector<string>& path, string& word, vector<vector<string> >& result);

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
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) 
{
        vector<vector<string> > result;
        int len=start.size();
        unordered_map<string, vector<string> > prevWord; // key is a word, value is all its precessors
        vector<string> tmp;
        prevWord[start]=tmp;
        vector<unordered_set<string> > level(2);
        int current=0;
        int previous=1;
        level[current].insert(start);
        
        while(true)
        {
	    /* here change two two level data structure indexes to avoid the copy overhead !!!*/
            swap(current, previous);
	    /* clean all the current levels, this is why queue is hard to be used 
	       if not delete by level but delete after find one by one, the following test case:
	       Input: 		"hot", "dog", ["hot","cog","dog","tot","hog","hop","pot","dot"]
	       Output: 		[["hot","hog","dog"]]
	       Expected: 	[["hot","dot","dog"],["hot","hog","dog"]]*/
            level[current].clear();
            for(auto itr=level[previous].begin(); itr!=level[previous].end(); itr++)
                dict.erase(*itr);
            
            for(auto itr=level[previous].begin(); itr!=level[previous].end(); itr++)
            {
                for(int i=0; i<len; i++)
                {
                    string word=*itr;
                    for(int j='a'; j<='z'; j++)
                    {
                        if((*itr)[i]==j)
                            continue;
                        word[i]=j;
                        if(dict.find(word)!=dict.end())
                        {
                            if(prevWord.find(word)==prevWord.end())
                                prevWord[word]=tmp;
                            prevWord[word].push_back(*itr);
                            level[current].insert(word);
                        }
                    }
                }
            }
            
            if(level[current].size()==0) // no path to reach end
                return result;
            if(level[current].find(end)!=level[current].end())
                break;
        }
        
        vector<string> path;
        generatePath(prevWord, path, end, result);
        return result;
}
    
void generatePath(unordered_map<string, vector<string> > &prevWord, vector<string>& path, string& word, vector<vector<string> >& result)
{
        if(prevWord[word].empty()) // finally find the start word, which has no previous word changed to it ---> base case
        {
            path.push_back(word);
            vector<string> pathTmp(path); // important step, if not, would mess the order, because there are pop_back after the recursive call!!!
            reverse(pathTmp.begin(), pathTmp.end());
            result.push_back(pathTmp);
            path.pop_back(); // import step, to maintain the recursive growth of path
            return;
        }
        
        path.push_back(word);
        for(auto itr=prevWord[word].begin(); itr!=prevWord[word].end(); itr++)
            generatePath(prevWord, path, *itr, result);
        path.pop_back();
}
