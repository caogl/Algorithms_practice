// reference: http://www.geeksforgeeks.org/trie-insert-and-search/
/* trie is an efficient information retrieval data structure. Using trie, search complexities can be brought to optimal limit 
 * (key length). If we store keys in binary search tree, a well balanced BST will need time proportional to O(M*logN), 
 * where M is maximum string length and N is number of keys in tree. Using trie, we can search the key in O(M) time
 * Insert and search costs O(key_length), however the memory requirements of trie is O(ALPHABET_SIZE * key_length * N),
 * where N is number of keys in trie. */

#include<iostream>
#include<vector>
#define MAX_CHAR 256
using namespace std;
 
// A Suffix Trie (A Trie of all suffixes) Node
class SuffixTrieNode
{
private:
	SuffixTrieNode *children[MAX_CHAR];
	vector<int> indexes;
public:
    	SuffixTrieNode() // Constructor
    	{
        	for (int i = 0; i < MAX_CHAR; i++)
			children[i] = nullptr;
	}
	void insertSuffix(string s, int index)
	{
		if(s.size()==0)	return;
		
		char cIndex=s[0];
		if(children[cIndex]==nullptr)
			children[cIndex]=new SuffixTrieNode();
		children[cIndex]->insertSuffix(s.substr(1), index);
		children[cIndex]->indexes.push_back(index);
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
	SuffixTrie(vector<string>& vec)
	{
		for(int i=0; i<vec.size(); i++)
			insert(vec[i], i);
	}
	void insert(string& txt, int i)
	{
		root.insertSuffix(txt, i);
	}
	void search(string pat)
	{
    		vector<int> result = root.search(pat); 
    		if(result.size()==0)
			cout << "Word not found" << endl;
		else
		{
			for(int i=0; i<result.size(); i++)
				cout << "Word found at position " << result[i] << endl;
		}
	}
};
 
// driver program to test above functions
int main()
{
	vector<string> vec={"there","is","an","answer","to","their","question","in","their","quiz","the","third","question"};
	SuffixTrie trie(vec);
	cout<<"search for word \"there\":"<<endl;
	trie.search("there");
	cout<<"search for word \"the\":"<<endl;
	trie.search("the");
	cout<<"search for word \"their\":"<<endl;
	trie.search("their");
	cout<<"search for word \"theer\":"<<endl;
	trie.search("theer");
	cout<<"search for word \"th\":"<<endl;
	trie.search("th");

	/*
	search for word "there":
	Word found at position 0
	search for word "the":
	Word found at position 10
	Word found at position 8
	Word found at position 5
	Word found at position 0
	search for word "their":
	Word found at position 8
	Word found at position 5
	search for word "theer":
	Word not found
	search for word "th":
	Word found at position 11
	Word found at position 10
	Word found at position 8
	Word found at position 5
	Word found at position 0
	*/

	return 0;
}


