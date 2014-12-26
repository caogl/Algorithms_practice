// Similar problem to "Construct binary tree from preorder and inorder traversal" 

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
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder);
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int istart, int iend, int pstart, int pend);

int main()
{
	vector<int> inorder={4,10,3,1,7,11,8,2};
	vector<int> postorder={4,1,3,10,11,8,2,7};
	TreeNode* root=buildTree(inorder, postorder);
	inorderTraversal(root);
	cout<<endl;
	return 0;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
        return buildTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int istart, int iend, int pstart, int pend)
{
        if(pstart>pend)
            return nullptr;
        
        int parentVal=postorder[pend];
        TreeNode* parent=new TreeNode(parentVal);
        int pivot=0;
        for(int i=istart; i<=iend; i++)
        {
            if(inorder[i]==parentVal)
            {
                pivot=i;
                break;
            }
        }
        
        int size1=pivot-1-istart;
        TreeNode* leftNode=buildTree(inorder, postorder, istart, pivot-1, pstart, pstart+size1);
        int size2=iend-pivot-1;
        TreeNode* rightNode=buildTree(inorder, postorder, pivot+1, iend, pend-1-size2, pend-1);
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
