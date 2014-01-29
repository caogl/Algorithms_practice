#include<iostream>
using namespace std;

struct Node
{

	Node* left;
	Node* right;
	int data;
};

Node* newNode(int data1);
void inorderTraverse(Node* root);
void preorderTraverse(Node* root);
void leftRotate(Node* & root);
void rightRotate(Node* & root);
int main()
{
	// the testcase for single rotation
	Node* root=newNode(6);
	root->left=newNode(4);
	root->right=newNode(7);
	root->left->left=newNode(2);
	root->left->right=newNode(5);
	root->left->left->left=newNode(1);
	root->left->left->right=newNode(3);
	preorderTraverse(root);
	cout<<endl;
	leftRotate(root);
	preorderTraverse(root);
	cout<<endl;
	// the testcase for double rotation
	Node* root1=newNode(6);
	root1->left=newNode(2);
	root1->right=newNode(7);
	root1->left->left=newNode(1);
	root1->left->right=newNode(4);
	root1->left->right->left=newNode(3);
	root1->left->right->right=newNode(5);
	preorderTraverse(root1);
	cout<<endl;
	rightRotate(root1->left);
	leftRotate(root1);
	preorderTraverse(root1);
	system("PAUSE");
	return 0;
}

void leftRotate(Node* & root)
{
	Node* tmp=root;
	root=root->left;
	tmp->left=root->right;
	root->right=tmp;
}

void rightRotate(Node* & root)
{
	Node* tmp=root;
	root=root->right;
	tmp->right=root->left;
	root->left=tmp;
}
void inorderTraverse(Node* root)
{
	if(root==NULL)
		return;
	inorderTraverse(root->left);
	cout<<root->data<<" ";
	inorderTraverse(root->right);
}

void preorderTraverse(Node* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorderTraverse(root->left);
	preorderTraverse(root->right);
}

Node* newNode(int data1)
{
	Node* node=new Node;
	node->data=data1;
	node->left=NULL;
	node->right=NULL;
	return node;
}

