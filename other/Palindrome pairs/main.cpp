// facebook interview question
// reference: http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=106193&extra=&highlight=facebook&page=3
// Given a dictory of words, find all pair<word1, word2> such that word1+word2 is a palindrome

/* 把每个word劈成两半，如果一半自身是palindrome并且另一半的reverse过来的词在字典里存在，就找到了一个这样pair，
   找出所有这样的可能性 ---> check both halves
   time: O(L^2*n), n is the number of words, L is the length of the longest word */

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

bool isPal(string word);
vector<pair<string, string> > palindomPair(vector<string> &words);

int main() 
{
	vector<string> words={"abc","ba","aaa","a","cb","cba","ccab","cigar","tragic","abcdf","cdf"};
	vector<pair<string, string> > result = palindomPair(words);

	for(int i = 0; i < result.size(); i ++)
        	cout << result[i].first << " + " << result[i].second << endl;
	return 0;
}

bool isPal(string word) 
{
	int len = word.size();
	for(int i = 0; i < len/2; i ++)
        	if(word[i] != word[len-1-i]) 	return false;
	return true;
}

/* !!!: this function will produce duplicate for absolute reverse word pairs, 
 * for eg: abc, cba pair will appear twice, should ask the interviewer whether to deal with this,
 * if needed, when find a absolute pair () when l=0 or l=len, keep a unordered_set to avoid duplicates */
vector<pair<string, string> > palindomPair(vector<string> &words) 
{
	vector<pair<string, string> > result;
	unordered_set<string> dict;
	for(int i = 0; i < words.size(); i ++)
        	dict.insert(words[i]);
	
	for(int i = 0; i < words.size(); i ++)
	{
        	int len = words[i].size();
		for(int l = 0; l <= len; l ++)
		{
			string sub1 = words[i].substr(0, l); 
			string sub2 = words[i].substr(l, len-l);
			if(isPal(sub2))
			{
				string tmp = sub1;
            			reverse(tmp.begin(), tmp.end());
                		if(dict.find(tmp) != dict.end() && words[i] != tmp) 
					result.push_back(pair<string, string>(words[i], tmp)); 
            		}   
            		if(isPal(sub1))
			{
	                	string tmp = sub2;
                		reverse(tmp.begin(), tmp.end());
                		if(dict.find(tmp) != dict.end() && words[i] != tmp)
                    			result.push_back(pair<string,string>(tmp, words[i]));
                	}   
            	}   
        }
	return result;
}


