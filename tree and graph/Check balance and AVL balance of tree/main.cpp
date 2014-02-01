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
void checkBalance(node *root, int depth, vector<int>& depthVec);
bool isBalanced(const vector<int>& vec);
bool isAVLBalanced(node *root);
int height(node *root);

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
	root1->left->left->left->left=new node(13);
	//root1->right->right->left=new node(13);
	//root1->right->right->right=new node(15);
	vector<int> depthVec;
	int depth=0;
	checkBalance(root1, depth, depthVec);
	for(unsigned int i=0; i<depthVec.size(); i++)
		cout<<depthVec[i]<<" ";
	cout<<endl;
	if(isBalanced(depthVec)==true)
		cout<<"The tree is balanced"<<endl;
	else
		cout<<"The tree is not balanced"<<endl;
	if(isAVLBalanced(root1)==true)
		cout<<"The tree is AVL balanced"<<endl;
	else
		cout<<"The tree is not AVL balanced"<<endl;
	system("PAUSE"); 
	return 0;
}

bool isAVLBalanced(node *root)
{
	if(root==NULL)
		return true;
	return (abs(height(root->left)-height(root->right))<=1 && isAVLBalanced(root->left) && isAVLBalanced(root->right));
}

int height(node *root)
{
	if(root==NULL)
		return 0;
	return max(height(root->left), height(root->right))+1;
}

void checkBalance(node *root, int depth, vector<int>& depthVec)
{
	//base case
	if(root==NULL)
		return;
	//cout<<root->data<<" ";
	//depth++;
	if(root->left==NULL && root->right==NULL)
	{
		//cout<<"haha"<<" ";
		depthVec.push_back(depth+1);
	}
	checkBalance(root->left, depth+1, depthVec);
	checkBalance(root->right, depth+1, depthVec);
	//depth--;
}

bool isBalanced(const vector<int>& vec)
{
	int max=*(max_element(vec.begin(), vec.end()));
	int min=*(min_element(vec.begin(), vec.end()));
	if((max-min)>=2)
		return false;
	else return true;
}
