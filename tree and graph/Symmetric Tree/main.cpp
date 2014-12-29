#include<iostream>
using namespace std;

//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode *root);
bool isSymmetric(TreeNode *leftNode, TreeNode* rightNode);

int main()
{
	TreeNode* head1=new TreeNode(1);
	head1->left=new TreeNode(2);
	head1->right=new TreeNode(2);
	head1->left->left=new TreeNode(3);
	head1->left->left=new TreeNode(3);

	TreeNode* head2=new TreeNode(1);
	head2->left=new TreeNode(2);
	head2->right=new TreeNode(2);
	head2->left->left=new TreeNode(3);
	head2->right->left=new TreeNode(3);

	TreeNode* head3=new TreeNode(2);
	head3->left=new TreeNode(3);
	head3->right=new TreeNode(3);
	head3->left->left=new TreeNode(4);
	head3->left->right=new TreeNode(5);
	head3->right->left=new TreeNode(5);
	
	cout<<isSymmetric(head1)<<endl<<isSymmetric(head2)<<endl<<isSymmetric(head3)<<endl;
	return 0;
}

bool isSymmetric(TreeNode *root)
{
	if(root==nullptr)
		return true;
	return isSymmetric(root->left, root->right);
}

bool isSymmetric(TreeNode *leftNode, TreeNode* rightNode)
{
	if(leftNode==nullptr && rightNode==nullptr)
		return true;
	else if(leftNode==nullptr || rightNode==nullptr)
		return false;
	else if(leftNode->val==rightNode->val)
		return isSymmetric(leftNode->left, rightNode->right) && isSymmetric(leftNode->right, rightNode->left);
	else
		return false;
}
