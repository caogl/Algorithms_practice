#include<iostream>
using namespace std;
// Logic of the code:
//      1               1            1
//     / \               \            \
//    2   5     =>        2       =>   2
//   / \   \             / \            \
//  3   4   6           3   4            3
//                           \            \
//                            5            4 
//                             \            \
//                              6            5
//                                            \
//                                             6

//Definition for binary tree
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode *root);
void inorderTraversal(TreeNode* head);

int main()
{
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->left->left=new TreeNode(3);
	root->left->right=new TreeNode(4);
	root->right=new TreeNode(5);
	root->right->right=new TreeNode(6);
	
	inorderTraversal(root);
	flatten(root);
	cout<<"After flatten: "<<endl;
	inorderTraversal(root);
	return 0;
}

void inorderTraversal(TreeNode* head)
{
	if(head==nullptr)
		return;
	inorderTraversal(head->left);
	cout<<head->val<<" ";
	inorderTraversal(head->right);
}

void flatten(TreeNode *root) 
{
	while(root!=nullptr)
	{
		if(root->left!=nullptr)
		{
			TreeNode* in=root->left;
			while(in->right!=nullptr)
				in=in->right;
			in->right=root->right;
			root->right=root->left;
			root->left=nullptr;
		}
		root=root->right;
	}
	return;
}
