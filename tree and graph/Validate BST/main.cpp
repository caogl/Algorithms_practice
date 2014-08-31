#include<iostream>
#include<vector>
using namespace std;

//Definition for binary tree
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode *root);
void inorderTraversal(TreeNode* root, vector<int>& vec);

int main()
{
	TreeNode* root=new TreeNode(10);
	root->left=new TreeNode(5);
	root->right=new TreeNode(15);
	root->right->left=new TreeNode(6);
	root->right->right=new TreeNode(20);
	
	if(isValidBST(root))
		cout<<"This is a BST"<<endl;
	else
		cout<<"This is not a BST"<<endl;
	return 0;
}

bool isValidBST(TreeNode *root)
{    
        if(root==nullptr)
            return true;
        vector<int> vec;
        inorderTraversal(root, vec);
        for(int i=0; i<vec.size()-1; i++)
        {
            if(vec[i]>=vec[i+1])
                return false;
        }
        return true;
}
    
void inorderTraversal(TreeNode* root, vector<int>& vec)
{
        if(root==nullptr)
            return;
        inorderTraversal(root->left, vec);
        vec.push_back(root->val);
        inorderTraversal(root->right, vec);
}
/*
 * the following solution can not pass the test case
bool isValidBST(TreeNode *root) 
{
        if(root==nullptr)
            return true;
        if(root->left!=nullptr)
        {
            if(root->val<=root->left->val)
                return false;
        }
        if(root->right!=nullptr)
        {
            if(root->right->val<=root->val)
                return false;
        }
        return (isValidBST(root->left) && isValidBST(root->right));
}
*/
