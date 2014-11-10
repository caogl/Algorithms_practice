#include<iostream>
#include<stack>
using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int data;
};

Node* newNode(int data1);
void preOrderTraversal(Node* root);
void prStack(Node* root);

void inOrderTraversal(Node* root);
void inStack(Node* root);

void postOrderTraversal(Node* root);
void postStack(Node* root);

int main()
{
	Node* root=newNode(100);
	root->left=newNode(50);
	root->right=newNode(150);
	root->left->left=newNode(25);
	root->left->right=newNode(75);
	root->right->left=newNode(125);
	root->right->left->left=newNode(110);
	root->right->right=newNode(175);
	//cout<<LCA(root, 125, 175)<<endl;
	//cout<<LCA(root, 25, 125)<<endl;
	preOrderTraversal(root);
	cout<<endl;
	prStack(root);
	cout<<endl;

	inOrderTraversal(root);
	cout<<endl;
	inStack(root);
	cout<<endl;

	postOrderTraversal(root);
	cout<<endl;
	postStack(root);

	return 0;
}

Node* newNode(int data1)
{
	Node* node=new Node;
	node->data=data1;
	node->left=NULL;
	node->right=NULL;
	return node;
}

void preOrderTraversal(Node* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void prStack(Node* root)
{
	stack<Node*> stack1;
	stack1.push(root);
	while(!stack1.empty())
	{
		cout<<stack1.top()->data<<" ";
		Node* tmp=stack1.top();
		stack1.pop();
		if(tmp->right!=NULL)
			stack1.push(tmp->right);
		if(tmp->left!=NULL)
			stack1.push(tmp->left);
	}
}

void inOrderTraversal(Node* root)
{
	if(root==NULL)
		return;
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);
}

void inStack(Node* root)
{
	stack<Node*> stack1;
	while(root!=nullptr || !stack1.empty())
	{
		if(root!=nullptr)
		{
			stack1.push(root);
			root=root->left;
		}
		else
		{
			cout<<stack1.top()->data<<" ";
			root=stack1.top();
			stack1.pop();
			root=root->right;
		}
	}
}

void postOrderTraversal(Node* root)
{
	if(root==NULL)
		return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout<<root->data<<" ";
}

void postStack(Node* root)
{
	stack<Node*> stack1;
	while(root!=nullptr || !stack1.empty())
	{
		if(root!=nullptr)
		{
			stack1.push(root);
			root=root->left;
		}
		else
		{
			cout<<stack1.top()->data<<" ";
			Node* tmp=stack1.top();
			stack1.pop();
			if(!stack1.empty() && tmp!=stack1.top()->right)
				root=stack1.top()->right;
			else
				root=root->right;
		}
	}
}

