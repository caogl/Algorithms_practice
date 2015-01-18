// reference: http://www.geeksforgeeks.org/pattern-searching-using-trie-suffixes/
/* Problem Statement: Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) 
 * that prints all occurrences of pat[] in txt[]. You may assume that n > m.
 * (1) strstr solution for leetcode problem, time complexity: O(m*n), space: O(1)
 * (2) KMP algorithm: time complexity: O(n)
 * (3) build suffix trie, time complexity of building trie: O(n^2), space: O(n^2), each search time complexity: O(m)
 */

#include<iostream>
#include<list>
#include<vector>
#define MAX_CHAR 256
using namespace std;
 
// A Suffix Trie (A Trie of all suffixes) Node
class SuffixTrieNode
{
private:
	SuffixTrieNode *children[MAX_CHAR]; // Trie node, root node with no starting char, others have a starting char(suffix)
	vector<int> indexes; // the starting indexes of the word that ends with this char
public:
    	SuffixTrieNode() // Constructor
    	{
		for(int i=0; i<MAX_CHAR; i++)
			children[i]=nullptr;
		indexes=vector<int> ();
	}
	void insertSuffix(string s, int index)
	{
		if(s.size()>0)
		{
			char cIndex=s[0];
			if(!children[cIndex])
				children[cIndex]=new SuffixTrieNode();
			children[cIndex]->indexes.push_back(index);
			children[cIndex]->insertSuffix(s.substr(1), index);
		}
	}
	vector<int> search(string s)
	{
		if(s.size()==0)	return indexes;

		if(children[s[0]])	return children[s[0]]->search(s.substr(1));
		else	return vector<int>();
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
    		vector<int> result = root.search(pat); 
    		if (result.size()==0)
			cout << "Pattern not found" << endl;
		else
		{
			for(int i=0; i<result.size(); i++)
				cout<<"Pattern found at position "<<result[i]<<endl;
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
	cout << "Search for ''" << endl;
	S1.search("");

	return 0;
}


