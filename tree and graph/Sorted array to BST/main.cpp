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

node* sortedArrayToTree(int* sortedArray, int begin, int end);
void inorderTraverse(node *root);
void sortedArrayToTree(int* sortedArray, int begin, int end, node* &head);

int main()
{
	int sortedList[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	//node* root=sortedArrayToTree(sortedList, 0, 14);
	node* head=NULL;
	sortedArrayToTree(sortedList, 0, 14, head);
	inorderTraverse(head);
	cout<<endl<<head->data;
	system("PAUSE");
	return 0;
}

void inorderTraverse(node *root)
{
	if(root==NULL)
		return;
	inorderTraverse(root->left);
	cout<<root->data<<" ";
	inorderTraverse(root->right);
}

// recursion version 1
node* sortedArrayToTree(int* sortedArray, int begin, int end)
{
	if(begin>end)
		return NULL;
	int mid=(begin+end)/2;
	node *root=new node(sortedArray[mid]);
	root->left=sortedArrayToTree(sortedArray, begin, mid-1);
	root->right=sortedArrayToTree(sortedArray, mid+1, end);
	return root;
}

// recursion version 2
void sortedArrayToTree(int* sortedArray, int begin, int end, node* &head)
{
	if(begin>end)
	{
		return;
	}
	int mid=(begin+end)/2;
	head=new node(sortedArray[mid]);
	sortedArrayToTree(sortedArray, mid+1, end, head->right);
	sortedArrayToTree(sortedArray, begin, mid-1, head->left);
}
