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
void prsStack(Node* root);
int LCA(Node* root, int value1, int value2);
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
	//cout<<LCA(root, 125, 175);
	preOrderTraversal(root);
	//cout<<endl;
	//prsStack(root);
	system("PAUSE");
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

int LCA(Node* root, int value1, int value2)
{
	while(true)
	{
		if(root->data>=value1 && root->data<=value2)
			return root->data;
		else if(root->data>=value1 && root->data>=value2)
			root=root->left;
		else
			root=root->right;
	}
}

void preOrderTraversal(Node* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void prsStack(Node* root)
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
