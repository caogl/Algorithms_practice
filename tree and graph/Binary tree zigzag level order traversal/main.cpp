// idea: using the property of stacks, as opposed to the BFS by queue, 
//       two stacks: preLevel and curLevel until next level is empty

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode *root);

int main()
{
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(6);
	root->right->right=new TreeNode(7);
	vector<vector<int> > result=zigzagLevelOrder(root);
	for(int i=0; i<result.size(); i++)
	{
		for(int j=0; j<result[i].size(); j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

vector<vector<int> > zigzagLevelOrder(TreeNode *root)
{
	vector<vector<int> > result;
	if(root==nullptr)
		return result;

	stack<TreeNode*> preLevel;
	stack<TreeNode*> curLevel;
	stack<TreeNode*> emptyStack;
	preLevel.push(root);
	result.push_back(vector<int> (1, root->val));
	bool odd=false;
	
	while(true)
	{
		vector<int> vec;
		while(!preLevel.empty())
		{
			if(odd)
			{
				if(preLevel.top()->left!=nullptr)
				{
					vec.push_back(preLevel.top()->left->val);
					curLevel.push(preLevel.top()->left);
				}
				if(preLevel.top()->right!=nullptr)
				{
					vec.push_back(preLevel.top()->right->val);
					curLevel.push(preLevel.top()->right);
				}
			}
			else
			{
				if(preLevel.top()->right!=nullptr)
				{
					vec.push_back(preLevel.top()->right->val);
					curLevel.push(preLevel.top()->right);
				}
				if(preLevel.top()->left!=nullptr)
				{
					vec.push_back(preLevel.top()->left->val);
					curLevel.push(preLevel.top()->left);
				}
			}
			preLevel.pop();
		}
		
		if(!vec.empty())
		{
			result.push_back(vec);
			preLevel=curLevel;
			curLevel=emptyStack;;
			odd=!odd;
		}
		else // next level is empty
			break;
	}
	return result;
} 
