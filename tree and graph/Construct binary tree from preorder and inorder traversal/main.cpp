// reference: http://fisherlei.blogspot.com/2013/01/leetcode-construct-binary-tree-from.html

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

void inorderTraversal(TreeNode* root);
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int pstart, int pend, int istart, int iend);


int main()
{
	vector<int> preorder={7,10,4,3,1,2,8,11};
	vector<int> inorder={4,10,3,1,7,11,8,2};
	TreeNode* root=buildTree(preorder, inorder);
	inorderTraversal(root);
	cout<<endl;
	return 0;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
	return buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int pstart, int pend, int istart, int iend)
{
	if(pstart>pend)
		return nullptr;

	/* find the pivot: since preorder[0] is the root, split from here */
	TreeNode* parent=new TreeNode(preorder[pstart]);
	int pivotInorder=0;
	for(int i=istart; i<=inorder.size(); i++)
	{
		if(inorder[i]==preorder[pstart])
		{
			pivotInorder=i;
			break;
		}
	}

	int size1=pivotInorder-istart; // the size of the left subtree of the parent
	TreeNode* leftNode=buildTree(preorder, inorder, pstart+1, pstart+size1, istart, pivotInorder-1);
	int size2=iend-pivotInorder-1; // the size of the right substree of the parent
	TreeNode* rightNode=buildTree(preorder, inorder, pend-size2, pend, pivotInorder+1, iend);
	parent->left=leftNode;
	parent->right=rightNode;
	return parent;
}

void inorderTraversal(TreeNode* root)
{
	if(root==nullptr)
		return;
	inorderTraversal(root->left);
	cout<<root->val<<" ";
	inorderTraversal(root->right);
}
