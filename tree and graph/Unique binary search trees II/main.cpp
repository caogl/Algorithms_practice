// reference: http://yucoding.blogspot.com/2013/05/leetcode-question115-unique-binary.html 

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode *> generateTrees(int n);
void print(TreeNode* root);
void generateTrees(int start, int end, vector<TreeNode*>& result);

int main()
{
	vector<TreeNode*> result=generateTrees(3);
	for(int i=0; i<result.size(); i++)
	{
		print(result[i]);
		cout<<endl;
	}
	return 0;
}

vector<TreeNode *> generateTrees(int n)
{
	vector<TreeNode*> result;
	generateTrees(1, n, result); // here start=1 becasue the ->val are from 1 to n !!!
	return result;
}

void generateTrees(int start, int end, vector<TreeNode*>& result)
{
	if(start>end) // for the zeros node tree
	{
		result.push_back(nullptr);
		return;
	}

	for(int i=start; i<=end; i++) // <= here !!!
	{
		vector<TreeNode*> leftSubTree;
		vector<TreeNode*> rightSubTree;
		generateTrees(start, i-1, leftSubTree);
		generateTrees(i+1, end, rightSubTree);
		for(int j=0; j<leftSubTree.size(); j++)
		{
			for(int k=0; k<rightSubTree.size(); k++)
			{
				TreeNode* root=new TreeNode(i);
				root->left=leftSubTree[j];
				root->right=rightSubTree[k];
				result.push_back(root);
			}
		}
	}
}

void print(TreeNode* root)
{
	if(root==nullptr)
		return;

	print(root->left);
	cout<<root->val<<" ";
	print(root->right);
}

