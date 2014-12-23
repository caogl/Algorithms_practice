//cracking the coding interview
//for the definition of the balance here, and the solution, refer to: http://www.hawstein.com/posts/4.1.html 


#include<iostream>
#include<vector>
#include<algorithm>
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

bool isBalanced(node* root);
void isBalanced(node* root, int tmpHeight, vector<int>& height);

int main()
{
	// this tree is balanced, but not balanced in the definition of this question
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
	root1->left->left->left->left=new node(13);

	if(isBalanced(root1)==true)
		cout<<"The tree is balanced"<<endl;
	else
		cout<<"The tree is not balanced"<<endl;
	return 0;
}

bool isBalanced(node* root)
{
	if(root==NULL)
		return true;
	vector<int> height; // the height vector, each correspond to one leaf node
	int tmpHeight=1;
	isBalanced(root, tmpHeight, height);
	return(*max_element(height.begin(), height.end())-*min_element(height.begin(), height.end())<=1);
}

void isBalanced(node* root, int tmpHeight, vector<int>& height)
{
	if(root->left==NULL && root->right==NULL)
	{
		height.push_back(tmpHeight);
		return;
	}
	if(root->left!=NULL)
		isBalanced(root->left, tmpHeight+1, height);
	if(root->right!=NULL)
		isBalanced(root->right, tmpHeight+1, height);
}

