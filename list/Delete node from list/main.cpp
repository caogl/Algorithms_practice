#include<iostream>
#include<unordered_set>
using namespace std;

struct node
{
	int data;
	node* next;
};
node* init(int a[], int n);
void remove(node *c);
void printList(node* head);

int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9};
	node* testHead=init(a, 10);
	printList(testHead);
	cout<<endl;
	int nth=4;
	node *c=testHead;
	for(int i=0; i<nth; i++)
	{
		c=c->next;
	}
	remove(c);
	printList(testHead);
	system("PAUSE");
	return 0;
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

void remove(node *c)
{
	if(c==NULL || c->next==NULL)
		return;
	node *d=c->next;
	c->next=d->next;
	c->data=d->data;
	delete d;
}

void printList(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}