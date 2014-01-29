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
	node(int data1)
	{
		data=data1;
		left=NULL;
		right=NULL;
	}
};
void findAndPrintSum(node *root, int sum, int& level, vector<int>& v);
void print(const vector<int>& vec, int level);

int main()
{
	node *root1=new node(8);
	root1->left=new node(4);
	//root1->left->parent=root1;
	root1->right=new node(12);
	//root1->right->parent=root1;
	root1->left->left=new node(2);
	//root1->left->left->parent=root1->left;
	node *root2=root1->left->right=new node(6);
	//root1->left->right->parent=root1->left;
	node *root3=root1->right->left=new node(10);
	//root1->right->left->parent=root1->right;
	root1->right->right=new node(14);
	root1->right->right=root1->right;
	root1->left->left->left=new node(1);
	root1->left->left->right=new node(3);
	root1->left->right->left=new node(5);
	root1->left->right->right=new node(7);
	root1->right->left->left=new node(9);
	root1->right->left->right=new node(11);
	root1->right->right->left=new node(13);
	root1->right->right->right=new node(15);
	int level=0;
	vector<int> vec;
	findAndPrintSum(root1, 12, level, vec);
	system("PAUSE");
	return 0;
}

void print(const vector<int>& vec, int level)
{
	cout<<"The path is: ";
	for(unsigned int i=level; i<vec.size(); i++)
		cout<<vec[i]<<" ";
	cout<<endl;
}

void findAndPrintSum(node *root, int sum, int& level, vector<int>& v)
{
	if(root==NULL)
		return;
	v.push_back(root->data);
	int tmp=0;
	for(int i=level; i>=0; i--)
	{
		tmp+=v[i];
		if(tmp==sum)
			print(v, i);
	}
	level++;
	findAndPrintSum(root->left, sum, level, v);
	findAndPrintSum(root->right, sum, level, v);
}