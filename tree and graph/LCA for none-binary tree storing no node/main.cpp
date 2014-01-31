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
void lca1(node* root, node* node1, node *node2, node* & ans);
bool isAns(node* node1, node* node2);

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
	lca1(root, node1, node2, ans);
	return ans;
}

void lca1(node* root, node* node1, node* node2, node* & ans)
{
	//base case
	if(!isAns(root, node1) || !isAns(root, node2))
		return;
	ans=root;
	lca1(root->left, node1, node2, ans);
	lca1(root->right, node1, node2, ans);
}

bool isAns(node* node1, node* node2)
{
	//two base cases
	if(node1==NULL || node2==NULL)
		return false;
	if(node1==node2)
		return true;
	return(isAns(node1->left, node2) || isAns(node1->right, node2));
}
