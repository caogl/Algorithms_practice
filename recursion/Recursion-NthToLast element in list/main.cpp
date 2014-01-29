#include<iostream>
#include<unordered_set>
using namespace std;

struct node
{
	int data;
	node* next;
};
node* init(int a[], int n);
void nthToLast(int& n, node* head, int& ntl);
void printList(node* head);

int main()
{
	int a[]={2,3,5,1,2,4,2,3,7,1,4,7,8,5,6,6,9,0,8};
	node* testHead=init(a, 19);
	printList(testHead);
	cout<<endl;
	int ntl=100;
	int n1=4;
	nthToLast(n1, testHead, ntl);
	cout<<"the 4th last element is: "<<ntl<<endl;
	int n2=10;
	nthToLast(n2, testHead, ntl);
	cout<<"the 10th last element is: "<<ntl<<endl;
	system("PAUSE");
	return 0;
}

void nthToLast(int& n, node* head, int& ntl)
{
	if(head==NULL) //base case
		return;
	nthToLast(n, head->next, ntl);
	if(n==1)
		ntl=head->data;
	n--;
}

node* init(int a[], int n)
{
	node *head, *p;
	for(int i=0; i<n; i++)
	{
		node *nd=new node();
		nd->data=a[i];
		if(i==0)
		{
			head=nd;
			p=nd;
		}
		else
		{
			p->next=nd;
			p=nd;
		}
	}
	return head;
}

void printList(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}