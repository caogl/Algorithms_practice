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
node* listToTree(int* sortedArray, int begin, int end);
void inorderTraverse(node *root);

int main()
{
	int sortedList[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	node* root=listToTree(sortedList, 0, 14);
	inorderTraverse(root);
	cout<<endl<<root->data;
	system("PAUSE");
	return 0;
}

void inorderTraverse(node *root)
{
	//cout<<"haha"<<" ";
	if(root==NULL)
		return;
	inorderTraverse(root->left);
	cout<<root->data<<" ";
	inorderTraverse(root->right);
}
node* listToTree(int* sortedArray, int begin, int end)
{
	//cout<<"haha"<<" ";
	if(begin>end)
		return NULL;
	int mid=(begin+end)/2;
	node* root=new node(sortedArray[mid]);
	root->left=listToTree(sortedArray, begin, mid-1);
	root->right=listToTree(sortedArray, mid+1, end);
	return root;
}