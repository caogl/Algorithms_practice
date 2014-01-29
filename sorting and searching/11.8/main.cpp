#include<iostream>
using namespace std;

struct node
{
	int data;
	int leftSize; // This is the size of the left subtree of the current node
	node *left;
	node *right;
	node(int data1):data(data1),leftSize(0),left(NULL),right(NULL){}
};

void insert(node* & head, int data1);
int getRank(node* head, int x);
void buildTree(int *a, int size, node* & head);

int main()
{
	node* head=new node(8);
	int a[]={4,6,5,1,7,9,10,2,0};
	buildTree(a, 9, head);
	//if(head==NULL)
		//cout<<"hahahhaha";
	//cout<<head->data<<" "<<head->left->data<<endl;
	//<<" "<<head->left->left->data<<" "<<head->right<<endl;
	cout<<"The rank of 2 is: "<<getRank(head, 2)<<endl;
	cout<<"The rank of 4 is: "<<getRank(head, 4)<<endl;
	cout<<"The rank of 6 is: "<<getRank(head, 6)<<endl;
	cout<<"The rank of 8 is: "<<getRank(head, 8)<<endl;
	cout<<"The rank of 9 is: "<<getRank(head, 9)<<endl;
	system("PAUSE");
	return 0;
}

void buildTree(int *a, int size, node* & head)
{
	for(int i=0; i<size; i++)
	{
		//cout<<"haha";
		insert(head, a[i]);
	}
}
void insert(node * &head, int data1)
{
	if(head==NULL)
	{
		//cout<<"haha";
		head=new node(data1);
		//cout<<head->data<<" ";
		return;
	}
	//cout<<head->data<<" "<<head->leftSize<<endl;
	if(data1<head->data)
	{
		//cout<<"haha ";
		insert(head->left, data1);
		head->leftSize++;
		//cout<<head->data<<" "<<head->leftSize<<endl;
	}
	else
		insert(head->right, data1);
}
int getRank(node* head, int x)
{
	if(head==NULL)
		return 0;
	if(x==head->data)
		return head->leftSize;
	if(x<head->data)
		return getRank(head->left, x);
	else
		return head->leftSize+1+getRank(head->right, x);
}