/* idea: while working on the current level by current=current->next, update and connect next node of the lower level! */

#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root);

int main()
{
	TreeLinkNode *root=new TreeLinkNode(1);
	root->left=new TreeLinkNode(2);
	root->right=new TreeLinkNode(3);
	root->left->left=new TreeLinkNode(4);
	root->left->right=new TreeLinkNode(5);
	root->right->left=new TreeLinkNode(6);
	root->right->right=new TreeLinkNode(7);
	connect(root);
	while(root!=nullptr)
	{
		TreeLinkNode *tmp=root;
		while(tmp!=nullptr)
		{
			cout<<tmp->val<<" ";
			tmp=tmp->next;
		}
		cout<<endl;
		root=root->left;
	}
}

/* constant space solution */
void connect(TreeLinkNode* root)
{
	while(root!=nullptr)
	{
		TreeLinkNode* levelTmp=root;
		while(levelTmp!=nullptr)
		{
			if(levelTmp->left!=nullptr)
				levelTmp->left->next=levelTmp->right;

			if(levelTmp->right!=nullptr && levelTmp->next!=nullptr) // notice the second check!!!!!
				levelTmp->right->next=levelTmp->next->left;

			levelTmp=levelTmp->next;
		}
		root=root->left;
	}
}

/* Using bfs can pass the leetcode testcases, but the real memory usage is 2^(level of tree) rather than constant
void connect(TreeLinkNode *root)
{
	if(root==nullptr)
		return;
	queue<TreeLinkNode*> q;
	q.push(root);

	// level and index, tracked when poped out of the queue! 
	int level=1;
	int index=1;
	while(!q.empty())
	{
		TreeLinkNode* tmp=q.front();
		q.pop();
		if(tmp->left!=nullptr && tmp->right!=nullptr)
		{
			q.push(tmp->left);
			q.push(tmp->right);
		}
		if(index==pow(2, level)-1)
		{
			tmp->next=nullptr;
			index++;
			level++;
		}
		else
		{
			tmp->next=q.front();
			index++;
		}
	}
}
*/
