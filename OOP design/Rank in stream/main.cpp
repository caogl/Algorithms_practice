/* (1) Cracking the coding interview 5th edition 11.8
 * 	Imagine you are reading in a stream of integers. Periodically, you wish to be able to look up the rank of a 
 *      number x (the number of values less than or equal tox).
	Implement the data structures and algorithms to support these operations.That is, implement the method 
	track(int x), which is called when each number is generated, and the method getRankOfNumber(int x), 
	which returns the number of values less than or equal to x (not including x itself).
	EXAMPLE:
	Stream (in order of appearance): 5, 1, 4, 4, 5, 9, 7, 13, 3
	getRankOfNumber(1) = 0
	getRankOfNumber(3) = 1
	getRankOfNumber(4) = 3

* (2) Google interview question: http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=84631&highlight=google
*     find k-th (start from 0) node in binary search tree
*/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	int leftSize; // the size of the left subtree of this node
	TreeNode(int x): val(x), leftSize(0), left(NULL), right(NULL) {}
};

class RankTree
{
private:
	TreeNode* root;
public:
	RankTree(): root(NULL){}

	void insert(int x)
	{
		insert(x, root);
	}

	void insert(int x, TreeNode* &current)
	{
		if(!current)
		{
			current=new TreeNode(x);
			return;		
		}
		
		if(x>current->val) // the > rather than >= make sure to get correct rank for duplicate elements !!!
			insert(x, current->right);
		else
		{
			current->leftSize++;
			insert(x, current->left);
		}
	}

	int getRank(int x)
	{
		return getRank(x, root);
	}
	
	int getRank(int x, TreeNode* current)
	{
		if(!current)	return 0;
		
		if(x==current->val)	return current->leftSize;
		else if(x>current->val)	return current->leftSize+1+getRank(x, current->right);
		else			return getRank(x, current->left);
	}
};

int main()
{
	RankTree tree;
	vector<int> vec={5,1,4,4,5,9,7,13,3};
	for(int i=0; i<vec.size(); i++)
		tree.insert(vec[i]);
	cout<<"The rank of 0 is: "<<tree.getRank(0)<<endl;
	cout<<"The rank of 3 is: "<<tree.getRank(3)<<endl;
	cout<<"The rank of 4 is: "<<tree.getRank(4)<<endl;
	cout<<"The rank of 7 is: "<<tree.getRank(7)<<endl;
	tree.insert(6);
	cout<<"The rank of 7 is: "<<tree.getRank(7)<<endl;
	
	return 0;
}
