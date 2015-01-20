// From: coding interview solution mannual 50 questions
/* Gvien two nodes in the tree, find the path ---> solution: find the lca and construct the path */

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

/*
              5
             / \        // n2 is guaranteed to be on right of n1
            4   8       (a):(2,1)--[2,11,4,5,8,4,1]
           /   / \      (b):(13,4)--[13,8,4]
          11  13  4
         /  \    / \
        7    2  5   1
 */
struct TreeNode
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> path(TreeNode* root, TreeNode* n1, TreeNode* n2);
TreeNode* lca(TreeNode* root, TreeNode* n1, TreeNode* n2);
void lca(TreeNode* root, TreeNode* n1, TreeNode* n2, TreeNode* &Ans);
bool isAns(TreeNode* root, TreeNode* n);
void formPath(TreeNode* root, TreeNode* n, vector<int>& vec);

int main()
{
	TreeNode* root=new TreeNode(5);
	root->left=new TreeNode(4);
	root->left->left=new TreeNode(11);
	root->left->left->left=new TreeNode(7);
	root->left->left->right=new TreeNode(2);
	root->right=new TreeNode(8);
	TreeNode* n1=root->right->left=new TreeNode(13);
	TreeNode* n2=root->right->right=new TreeNode(4);
	root->right->right->left=new TreeNode(5);
	root->right->right->right=new TreeNode(1);
	vector<int> result=path(root, n1, n2);
	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<" ";
	cout<<endl;
	return 0;
}

vector<int> path(TreeNode* root, TreeNode* n1, TreeNode* n2)
{
	TreeNode* lcaRoot=lca(root, n1, n2);
	vector<int> result;
	if(lcaRoot==n1)
		result.push_back(lcaRoot->val);
	else
	{
		vector<int> vec;
		vec.push_back(lcaRoot->val);
		formPath(lcaRoot->left, n1, vec);
		reverse(vec.begin(), vec.end());
		result=vec;
	}

	vector<int> vec1;
	formPath(lcaRoot->right, n2, vec1);
	for(int i=0; i<vec1.size(); i++)
		result.push_back(vec1[i]); 
	return result;
}

void formPath(TreeNode* root, TreeNode* n, vector<int>& vec)
{
	if(root==nullptr)	return;
	
	vec.push_back(root->val);
	if(root==n)	
		return;
	formPath(root->left, n, vec);
	formPath(root->right, n, vec);
	vec.pop_back();
}

TreeNode* lca(TreeNode* root, TreeNode* n1, TreeNode* n2)
{
	TreeNode* Ans=nullptr;
	lca(root, n1, n2, Ans);
	return Ans;
}

void lca(TreeNode* root, TreeNode* n1, TreeNode* n2, TreeNode* &Ans)
{
	if(!isAns(root, n1) || !isAns(root, n2))	return;
	
	Ans=root;
	lca(root->left, n1, n2, Ans);
	lca(root->right, n1, n2, Ans);
}

bool isAns(TreeNode* root, TreeNode* n)
{
	if(root==n)	return true;
	if(root==nullptr)	return false;
	return (isAns(root->left, n) || isAns(root->right, n));
}
