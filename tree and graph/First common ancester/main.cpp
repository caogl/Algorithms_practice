#include<iostream>
using namespace std;

struct node
{
	node(int data1)
	{
		left=NULL;
		right=NULL;
		data=data1;
	}
	node *left;
	node *right;
	int data;
};

/* lca for binary tree using no extra space*/
/* reference: http://www.hawstein.com/posts/4.6.html */
node* lca(node* root, node* node1, node *node2);
void lca(node* root, node* node1, node* node2, node* & ans);
bool isAns(node* root, node* node1);

/* lca for a binary search tree */
node* lcaBST(node* root, node* node1, node* node2);

int main()
{
	node *root=new node(8);
	root->left=new node(4);
	root->left->left=new node(2);
	node* node1=root->left->left->right=new node(3);
	node* node2=root->left->left->left=new node(1);
	root->left->right=new node(6);
	root->right=new node(12);
	root->right->left=new node(10);
	node* node3=root->right->right=new node(14);
	node *result1=lca(root, node1, node2);
	cout<<"The lca between node 1 and 3 is: "<<result1->data<<endl;
	node *result2=lca(root, node1, node3);
	cout<<"The lca between node 1 and 14 is: "<<result2->data<<endl;
	return 0;
}

node* lca(node* root, node* node1, node *node2)
{
	node* ans=root;
	lca(root, node1, node2, ans);
	return ans;
}

void lca(node* root, node* node1, node* node2, node* & ans)
{
	if(!isAns(root, node1) || !isAns(root, node2))
		return;
	ans=root;
	lca(root->left, node1, node2, ans);
	lca(root->right, node1, node2, ans);
}

bool isAns(node* root, node* node1)
{
	if(root==NULL || node1==NULL)
		return false;
	if(root==node1)
		return true;
	return (isAns(root->left, node1) || isAns(root->right, node1));
}

node* lcaBST(node* root, node* node1, node* node2)
{
	if(node1->data>node2->data)
		return lcaBST(root, node2, node1);
	if(root->data>=node1->data && root->data<=node2->data)
		return root;
	else if(root->data>=node1->data && root->data>=node2->data)
		return lcaBST(root->left, node1, node2);
	else
		return lcaBST(root->right, node1, node2);
}
