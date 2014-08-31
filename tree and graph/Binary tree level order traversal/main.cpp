#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode *root);

int main()
{
	TreeNode* root=new TreeNode(5);
	root->left=new TreeNode(3);
	root->right=new TreeNode(7);
	root->left->left=new TreeNode(2);
	root->left->right=new TreeNode(4);
	root->right->left=new TreeNode(6);
	root->right->right=new TreeNode(8);
	root->left->left->left=new TreeNode(1);
	root->right->right->right=new TreeNode(9);

	vector<vector<int> > result=levelOrder(root);
	for(int i=0; i<result.size(); i++)
	{
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

vector<vector<int> > levelOrder(TreeNode *root)
{
	vector<vector<int> > result;
	if(root==nullptr)
		return result;
	
	vector<int> tmp;
	tmp.push_back(root->val);
	result.push_back(tmp);
	tmp.clear();

	queue<TreeNode*> q;
	q.push(root);
	int prevLevelNum=1;
	int curLevelNum=0;
	TreeNode* curNode;

	while(!q.empty())
	{
		curNode=q.front();
		q.pop();
		if(curNode->left!=nullptr)
		{
			curLevelNum++;
			tmp.push_back(curNode->left->val);
			q.push(curNode->left);
		}
		if(curNode->right!=nullptr)
		{
			curLevelNum++;
			tmp.push_back(curNode->right->val);
			q.push(curNode->right);
		}
		
		prevLevelNum--;
		if(prevLevelNum==0)
		{
			if(!tmp.empty()) //should check here!!
				result.push_back(tmp);
			tmp.clear();
			prevLevelNum=curLevelNum;
			curLevelNum=0;
		}
	}

	return result;
}
