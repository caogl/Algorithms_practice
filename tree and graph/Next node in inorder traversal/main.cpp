#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
	node *parent;
	node(int data1)
	{
		data=data1;
		left=NULL;
		right=NULL;
		parent=NULL;
	}
};
node* nextAns(node* node1);

int main()
{
	node *root1=new node(8);
	root1->left=new node(4);
	root1->left->parent=root1;
	root1->right=new node(12);
	root1->right->parent=root1;
	root1->left->left=new node(2);
	root1->left->left->parent=root1->left;
	node *root2=root1->left->right=new node(6);
	root1->left->right->parent=root1->left;
	node *root3=root1->right->left=new node(10);
	root1->right->left->parent=root1->right;
	root1->right->right=new node(14);
	root1->right->right=root1->right;
	/*
	root1->left->left->left=new node(1);
	root1->left->left->right=new node(3);
	root1->left->right->left=new node(5);
	root1->left->right->right=new node(7);
	node *root2=root1->right->left->left=new node(9);
	root1->right->left->right=new node(11);
	root1->right->right->left=new node(13);
	root1->right->right->right=new node(15);
	*/
	node *result=nextAns(root2);
	cout<<result->data<<endl;
	result=nextAns(root3);
	cout<<result->data<<endl;
	system("PAUSE");
	return 0;
}

node* nextAns(node* node1)
{
	// if the right subtree is not empty
	if(node1->right!=NULL)
	{
		node *result=node1->right;
		while(result->left!=NULL)
		{
			result=result->left;
		}
		return result;
	} 
	else
	{
		// find the first parent whose data is bigger than the current node
		while(node1->parent!=NULL)
		{
			if(node1->parent->data>node1->data)
				return node1->parent;
			node1=node1->parent;
		}
	}
	return NULL;
}
