// idea: use bottom-up approach rather than top-down approach
// reference: leetcode clean code hand book

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
	maxV=max(maxV, root->val+leftV+rightV);
	int retV=max(root->val+leftV, root->val+rightV);
	return max(0, retV);
}
