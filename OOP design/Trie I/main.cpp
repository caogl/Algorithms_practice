// reference: http://www.geeksforgeeks.org/pattern-searching-using-trie-suffixes/
/* Problem Statement: Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) 
 * that prints all occurrences of pat[] in txt[]. You may assume that n > m.
 * (1) strstr solution for leetcode problem, time complexity: O(m*n), space: O(1)
 * (2) KMP algorithm: time complexity: O(n)
 * (3) build suffix trie, time complexity of building trie: O(n^2), space: O(n^2), for search: O(m)
 */

#include<iostream>
#include<list>
#define MAX_CHAR 256
using namespace std;
 
// A Suffix Trie (A Trie of all suffixes) Node
class SuffixTrieNode
{
private:
	SuffixTrieNode *children[MAX_CHAR];
	list<int> *indexes;
public:
    	SuffixTrieNode() // Constructor
    	{
        	indexes = new list<int>; 
        	for (int i = 0; i < MAX_CHAR; i++)
			children[i] = NULL;
	}
	void insertSuffix(string s, int index)
	{
		indexes->push_front(index);
		if (s.length() > 0)
    		{
        		char cIndex = s.at(0);
        		if (children[cIndex] == NULL)
         			children[cIndex] = new SuffixTrieNode();
			children[cIndex]->insertSuffix(s.substr(1), index+1);
		}	
	}
	list<int>* search(string s)
	{
    		// If all characters of pattern have been processed,
		if (s.length() == 0)
        		return indexes;
		if (children[s.at(0)] != NULL)
			return (children[s.at(0)])->search(s.substr(1));
		else return NULL;
	}
};
 
// A Trie of all suffixes
class SuffixTrie
{
private:
	SuffixTrieNode root;
public:
	SuffixTrie(string txt)
	{
		for (int i = 0; i < txt.length(); i++)
        		root.insertSuffix(txt.substr(i), i);
	}
	void search(string pat)
	{
    		list<int> *result = root.search(pat); 
    		if (result == NULL)
			cout << "Pattern not found" << endl;
		else
		{
			list<int>::iterator i;
			int patLen = pat.length();
			for (i = result->begin(); i != result->end(); ++i)
			cout << "Pattern found at position " << *i - patLen<< endl;
		}
	}
};
 
// driver program to test above functions
int main()
{
	// Let us build a suffix trie for text "geeksforgeeks.org"
	string txt = "banana";
	cout<<"Searching in the string "<<txt<<endl;
	SuffixTrie S(txt);
	cout << "Search for 'ba'" << endl;
	S.search("ba");
	cout << "Search for 'na'" << endl;
	S.search("na"); 
	cout << "Search for 'ana'" << endl;
	S.search("ana");
	cout << "Search for 'a'" << endl;
	S.search("a");
	cout<<endl<<endl;

	txt = "geeksforgeeks.org";
	cout<<"Searching in the string "<<txt<<endl;
	SuffixTrie S1(txt);
	cout << "Search for 'ee'" << endl;
	S1.search("ee");
	cout << "Search for 'geek'" << endl;
	S1.search("geek");
	cout << "Search for 'quiz'" << endl;
	S1.search("quiz");
	cout << "Search for 'forgeeks'" << endl;
	S1.search("forgeeks");
	return 0;
}


