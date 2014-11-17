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
	root->left->right=new TreeLinkNode(5);
	root->right->left=new TreeLinkNode(6);
	root->right->right=new TreeLinkNode(7);
	root->left->right->left=new TreeLinkNode(10);
	root->right->left->left=new TreeLinkNode(12);
	root->right->right->right=new TreeLinkNode(15);

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

		while(root->left==nullptr && root->right==nullptr && root->next!=nullptr)
			root=root->next;
		if(root->left!=nullptr)
			root=root->left;
		else
			root=root->right;
	}
}

/* constant space solution */
void connect(TreeLinkNode* root)
{
	while(root!=nullptr)
	{
		TreeLinkNode* nextLeftmost=nullptr; // the next level starting node
		TreeLinkNode* prev=nullptr; // prev node to point to the current node (prev->next=levelCurrent)
		TreeLinkNode* current=root; //current node in this level
		while(current!=nullptr)
		{
			if(nextLeftmost==nullptr)
			{
				if(current->left!=nullptr)
					nextLeftmost=current->left;
				else
					nextLeftmost=current->right;
			}
			if(current->left!=nullptr)
			{
				if(prev!=nullptr)
					prev->next=current->left;
				prev=current->left;
			}
			if(current->right!=nullptr)
			{
				if(prev!=nullptr)
					prev->next=current->right;
				prev=current->right;
			}
			current=current->next;
		}
		root=nextLeftmost;
	}
}


