// reference: leetcode clean code hand book
/*
Anytime when you found that doing top down approach uses a lot of repeated calculation, 
bottom up approach usually is able to be more efficient.

    _____Node_____
   /              \
left subtree  right subtree

Try the bottom up approach. At each node, the potential maximum path could be one of these cases:
(i). max(left subtree) + node
(ii). max(right subtree) + node
(iii). max(left subtree) + max(right subtree) + node
(iv). the node itself

Then, we need to return the maximum path sum that goes through this node and to either 
one of its left or right subtree to its parent. There’s a little trick here: If this maximum 
happens to be negative, we should return 0, which means: “Do not include this subtree as 
part of the maximum path of the parent node”, which greatly simplifies our code.
*/

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSum(TreeNode *root);
// return the "one side" maximum value so that the above node can connect to this one to compute the maximum path
int maxPathSum(TreeNode *root, int& maxV);

int main()
{
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(4);
	root->left->left=new TreeNode(2);
	root->left->right=new TreeNode(3);

	TreeNode* root1=new TreeNode(-5);
	root1->left=new TreeNode(2);
	root1->right=new TreeNode(3);
	root1->left->left=new TreeNode(-1);
	root1->left->right=new TreeNode(4);
	
	cout<<maxPathSum(root)<<endl;
	cout<<maxPathSum(root1)<<endl;

	return 0;
}

int maxPathSum(TreeNode *root)
{
	int maxV=INT_MIN;
	maxPathSum(root, maxV);
	return maxV;
}

int maxPathSum(TreeNode *root, int& maxV)
{
	if(root==nullptr)
		return 0;
		
	int leftV=maxPathSum(root->left, maxV);
	int rightV=maxPathSum(root->right, maxV);
	
	maxV=max(maxV, root->val+leftV+rightV); // max sum of two-sided tree using current node as root
	int retV=max(root->val+leftV, root->val+rightV); // max sum of one side tree
	return max(0, retV); // max sum of one side tree
}
