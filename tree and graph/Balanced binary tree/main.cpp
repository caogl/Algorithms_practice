// reference: leetcode official clean code handbook

#include<iostream>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// top-down recursion: runtime O(N^2), space O(N), where N is the number of nodes in the tree
// similar to fibonacci recursion
/*
bool isBalanced(TreeNode *root);
int height(TreeNode* root);
*/

// bottom-up recursion, runtime O(N), space O(N), where N is the number of nodes in the tree
bool isBalanced(TreeNode *root);
int height(TreeNode* root);

int main()
{
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->left->left=new TreeNode(5);
	root->left->right=new TreeNode(6);
	root->right->left=new TreeNode(7);

	cout<<isBalanced(root)<<endl;
	root->left->left->left->left=new TreeNode(8);
	cout<<isBalanced(root)<<endl;
	
	return 0;
}

/*
bool isBalanced(TreeNode *root) 
{
        if(root==nullptr)
            return true;
        return (abs(height(root->left)-height(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right));
}

int height(TreeNode* root)
{
        if(root==nullptr)
            return 0;
        return max(height(root->left), height(root->right))+1;
}
*/

bool isBalanced(TreeNode *root)
{
	return height(root)>=0;
}

// if return -1, not balanced from current node
int height(TreeNode* root)
{
	if(root==nullptr)
		return 0;
	int leftH=height(root->left);
	if(leftH<0)
		return -1;
	int rightH=height(root->right);
	if(rightH<0)
		return -1;
	
	if(abs(rightH-leftH)>1)
		return -1;
	else
		return max(rightH, leftH)+1;
}
