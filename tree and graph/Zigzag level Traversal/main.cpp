// idea: using the property of queues, using two queuse interchangably to keep track oth the node

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
	if(root!=nullptr)
	{
		vector<int> vec;
		vec.push_back(root->val);
		result.push_back(vec);
	}
	else
		return result;

	vector<stack<TreeNode*> > levelStack(2);
	int cur=1;
	levelStack[0].push(root);
	while(!levelStack[!cur].empty())
	{
		vector<int> vec;
		if(cur&1) // odd level
		{
			while(!levelStack[!cur].empty())
			{
				TreeNode* tmp=levelStack[!cur].top();
				if(tmp->right)
				{
					vec.push_back(tmp->right->val);
					levelStack[cur].push(tmp->right);
				}
				if(tmp->left)
				{
					vec.push_back(tmp->left->val);
					levelStack[cur].push(tmp->left);
				}
				levelStack[!cur].pop();
			}
		}
		else // even level
		{
			while(!levelStack[!cur].empty()) // odd level
			{
				TreeNode* tmp=levelStack[!cur].top();
				if(tmp->left)
				{
					vec.push_back(tmp->left->val);
					levelStack[cur].push(tmp->left);
				}
				if(tmp->right)
				{
					vec.push_back(tmp->right->val);
					levelStack[cur].push(tmp->right);
				}
				levelStack[!cur].pop();
			}
		}
		if(!vec.empty()) // important check!
			result.push_back(vec);
		cur=!cur;
	}
	return result;
} 
