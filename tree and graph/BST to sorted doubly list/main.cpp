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
node* flatten(node *root);
void inOrder(node *root, node* & head, node* & tail);
void append(node* & head, node* & tail);
void printList(node* head);

int main()
{
	node *root=new node(4);
	root->left=new node(2);
	root->left->left=new node(1);
	root->left->right=new node(3);
	root->right=new node(6);
	root->right->left=new node(5);
	root->right->right=new node(7);
	node *head=flatten(root);
	printList(head);
	system("PAUSE");
	return 0;
}

void printList(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->right;
	}
}

node* flatten(node *root)
{
	node *head=NULL;
	node *tail=NULL;
	inOrder(root, head, tail);
	return head;
}

void inOrder(node *root, node* & head, node* & tail)
{
	if(root==NULL)
		return;
	inOrder(root->left, head, tail);
	if(head==NULL)
	{
		head=tail=root;
	}
	else
	{
		tail->right=root;
		root->left=tail;
		tail=root;
	}
	inOrder(root->right, head, tail);
}