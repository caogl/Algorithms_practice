// check whether a tree satisfies the following property: the parent is 
// always a the difference of left node and right node
// can assume that a parent always have left and right child

#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
	node(int data1)
	{
		data=data1;
		left=NULL;
		right=NULL;
	}
};

bool isDifBalance(node *root);

int main()
{
	// the difBalanced tree
	node *root1=new node(1);
	root1->left=new node(1);
	root1->right=new node(2);
	root1->left->left=new node(3);
	root1->left->right=new node(4);
	root1->right->left=new node(5);
	root1->right->right=new node(7);
	root1->left->left->left=new node(1);
	root1->left->left->right=new node(4);
	root1->left->right->left=new node(2);
	root1->left->right->right=new node(6);
	root1->right->left->left=new node(5);
	root1->right->left->right=new node(10);
	root1->right->right->left=new node(2);
	root1->right->right->right=new node(9);
	// a non-difBalanced tree
	node *root2=new node(1);
	root2->left=new node(1);
	root2->right=new node(2);
	root2->left->left=new node(3);
	root2->left->right=new node(4);
	root2->right->left=new node(5);
	root2->right->right=new node(7);
	root2->left->left->left=new node(1);
	root2->left->left->right=new node(4);
	root2->left->right->left=new node(2);
	root2->left->right->right=new node(8);
	root2->right->left->left=new node(5);
	root2->right->left->right=new node(10);
	root2->right->right->left=new node(2);
	root2->right->right->right=new node(9);
	if(isDifBalance(root1))
		cout<<"This tree is diff-balanced"<<endl;
	else
		cout<<"This tree is not diff-balanced"<<endl;
	if(isDifBalance(root2))
		cout<<"This tree is diff-balanced"<<endl;
	else
		cout<<"This tree is not diff-balanced"<<endl;	
	return 0;
}

bool isDifBalance(node *root)
{
	if(root==NULL)
		return true;
	else if(root->left==NULL || root->right==NULL)
		return true;
	else if(root->right->data-root->left->data!=root->data)
		return false;
	else
		return(isDifBalance(root->left) && isDifBalance(root->right));
}
