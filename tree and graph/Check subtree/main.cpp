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
bool isSubtree(node *root1, node *root2);
bool match(node *node1, node *node2);

int main()
{
	node *root1=new node(8);
	root1->left=new node(4);
	root1->right=new node(12);
	root1->left->left=new node(2);
	root1->left->right=new node(6);
	root1->right->left=new node(10);
	root1->right->right=new node(14);
	root1->left->left->left=new node(1);
	root1->left->left->right=new node(3);
	root1->left->right->left=new node(5);
	root1->left->right->right=new node(7);
	root1->right->left->left=new node(9);
	root1->right->left->right=new node(11);
	root1->right->right->left=new node(13);
	root1->right->right->right=new node(15);
	node *root2=root1->left->right;
	node *root3=new node(4);
	root3->left=new node(2);
	root3->right=new node(6);
	root3->left->left=new node(1);
	root3->left->right=new node(3);
	root3->right->left=new node(5);
	root3->right->right=new node(700);
	if(isSubtree(root1, root2))
		cout<<"tree 2 is a subtree of tree 1"<<endl;
	else
		cout<<"tree 2 is not a subtree of tree 1"<<endl;
	if(isSubtree(root1, root3))
		cout<<"tree 3 is a subtree of tree 1"<<endl;
	else
		cout<<"tree 3 is not a subtree of tree 1"<<endl;
	system("PAUSE");
	return 0;
}

bool isSubtree(node *root1, node *root2) // check whether root2 is a subtree of root1
{
	// two base cases
	if(root1==NULL)
		return false;
	if(root1->data==root2->data)
	{
		if(match(root1, root2))
			return true;
	}
	else
		return(isSubtree(root1->left, root2) || isSubtree(root1->right, root2));
}

bool match(node *node1, node *node2)
{
	// three base cases
	if(node1==NULL && node2==NULL)
		return true;
	else if(node1==NULL || node2==NULL)
		return false;
	else if(node1->data!=node2->data)
		return false;
	else
		return (match(node1->left, node2->left) && match(node1->right, node2->right));
}

