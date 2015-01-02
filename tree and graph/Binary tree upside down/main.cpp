/*

key: all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty
     original right nodes turned into left leaf nodes

From bottom up:
    1		         4   1                   4
   / \		        / \ / \                 / \
  2   3      --->      5   2   3     --->      5   2
 / \                                              / \
4   5                    		         3   1

The recursive relationship:
	(1) current->left=parent->right
	(2) current->right=parent
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// test function
vector<vector<int> > levelOrder(TreeNode *root);
TreeNode *upsideDownBinaryTree(TreeNode *root);
TreeNode* upsideDownBinaryTree(TreeNode* current, TreeNode* parent);

int main()
{
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	vector<vector<int> > result=levelOrder(root);
	for(int i=0; i<result.size(); i++)
	{
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	TreeNode* root1=upsideDownBinaryTree(root);
	result=levelOrder(root1);
	for(int i=0; i<result.size(); i++)
	{
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	return 0;
}

TreeNode *upsideDownBinaryTree(TreeNode *root)
{
	return upsideDownBinaryTree(root, nullptr);
}

// take two parameters current and parent, build the subtree to replace the node position of current
TreeNode* upsideDownBinaryTree(TreeNode* current, TreeNode* parent)
{
	if(current==nullptr) 
		return parent;

	TreeNode* root=upsideDownBinaryTree(current->left, current); // just for return the new root purpose

        if(parent==nullptr) // deal with the root in original tree
        {
            current->left=nullptr;
            current->right=nullptr;
        }
        else // now after
        {
            current->left=parent->right;
            current->right=parent;
        }
	return root;
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
