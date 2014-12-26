/* the O(1) memory requirement is too tight, must use a Threaded Binary Tree, which is beyond the normal scope
 * Here try to do the swap in one traversal pass and in place, the memory is O(log(n)) due to recursive call,
 * but can view it as no extra memory. */

/* idea: (1) if 1-3-2-4-5, the two nodes to swap are 3-2 
 * 	 (2) if 1-4-3-2-5, the two nodes to swap are 4-3, then 3-2, find two descending sequence, then finally
 * 	     the two nodes to swap are 4-2
 * 	 do these during inorder traversal */

#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode* root);
void recoverTree(TreeNode *root);
void recoverTree(TreeNode *root, TreeNode* &misc1, TreeNode* &misc2, TreeNode* &prev);

int main()
{
	TreeNode* root=new TreeNode(4);
	root->left=new TreeNode(7); // swapped with 2
	root->right=new TreeNode(6);
	root->left->left=new TreeNode(1);
	root->left->right=new TreeNode(3);
	root->right->left=new TreeNode(5);
	root->right->right=new TreeNode(2); // swapped with 7
	inorderTraversal(root);
	cout<<endl;
	recoverTree(root);
	inorderTraversal(root);
	cout<<endl;
	return 0;
}

void recoverTree(TreeNode *root)
{
	if(root==nullptr)
		return;
	TreeNode* misc1=nullptr;
	TreeNode* misc2=nullptr;
	TreeNode* prev=nullptr;
	recoverTree(root, misc1, misc2, prev);
	swap(misc1->val, misc2->val);
}

void recoverTree(TreeNode *root, TreeNode* &misc1, TreeNode* &misc2, TreeNode* &prev)
{
	if(root==nullptr)
		return;
	recoverTree(root->left, misc1, misc2, prev);
	
	if(prev!=nullptr && prev->val>root->val)
	{
		if(misc1==nullptr)
			misc1=prev;
		misc2=root;
	}
	
	prev=root;
	recoverTree(root->right, misc1, misc2, prev);
}

void inorderTraversal(TreeNode* root)
{
	if(root==nullptr)
		return;
	inorderTraversal(root->left);
	cout<<root->val<<" ";
	inorderTraversal(root->right);
}
