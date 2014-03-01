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

node* lca(node* root, node* node1, node *node2);
void lca(node* root, node* node1, node* node2, node* & ans);
bool isAns(node* root, node* node1);

int main()
{
	node *root=new node(8);
	root->left=new node(4);
	root->left->left=new node(2);
	node *node1=root->left->left->left=new node(1);
	root->left->left->right=new node(3);
	node *node2=root->left->right=new node(6);
	root->left->right->left=new node(5);
	root->left->right->right=new node(7);
	root->right=new node(2);
	node *node3=root->right->left=new node(10);
	root->right->right=new node(14);
	node *result1=lca(root, node1, node2);
	cout<<"The lca between node 1 and 6 is: "<<result1->data<<endl;
	node *result2=lca(root, node1, node3);
	cout<<"The lca between node 1 and 10 is: "<<result2->data<<endl;
	system("PAUSE");
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
