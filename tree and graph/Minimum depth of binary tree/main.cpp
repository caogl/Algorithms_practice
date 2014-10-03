#include<climits>
#include<iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode *root);
void minDepth(TreeNode* root, int currentD, int& minD);

int main()
{
	TreeNode* head=new TreeNode(1);
	head->left=new TreeNode(2);
	//head->right=new TreeNode(3);
	cout<<minDepth(head)<<endl;
	return 0;
}

int minDepth(TreeNode *root) 
{
        int minD=INT_MAX;
        if(root==nullptr)
            return 0;
        minDepth(root, 1, minD);
        return minD;
}

void minDepth(TreeNode* root, int currentD, int& minD)
{
    if(root->left==nullptr && root->right==nullptr)
    {
        minD=min(minD, currentD);
        return;
    }
    if(root->left!=nullptr)
        minDepth(root->left, currentD+1, minD);
    if(root->right!=nullptr)
        minDepth(root->right, currentD+1, minD);
}
