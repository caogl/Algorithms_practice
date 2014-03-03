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
//void removeLast(node* c);

int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9};
	node* testHead=init(a, 10);
	printList(testHead);
	int nth=8;
	node *c=testHead;
	for(int i=0; i<nth; i++)
	{
		c=c->next;
	}
	remove(c);
	printList(testHead);

	// if try to delete the last node in the list by using the removeLast function, 
	// the result turns to be not application
	int b[]={0,1,2,3,4,5,6,7,8,9};
	testHead=init(b, 10);
	printList(testHead);
	nth=9;
	node *d=testHead;
	for(int i=0; i<nth; i++)
	{
		d=d->next;
	}
	//removeLast(d);
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

/*
if remove the last node like this, when print the list, the last node will still be printed
with a wield value, THE REASON IS THAT THIS NEXT TO LAST NODE STILL POINTS TO THE MEMORY ADDRESS 
THE HEAP, IT DOES NOT KNOW THAT THIS MEMORY IS DEALLOCATED !!!! --------DELETING THE LAST NODE IS
IMPOSSIBLE AND NEED TO BE EXPLAINED
void removeLast(node* c)
{
	delete c;
	c=NULL;
}
*/

void remove(node* c)
{
	if(c==NULL || c->next==NULL)
		return;
	// whenever want to access next->, need to test whether it is NULL beforehand
	c->data=c->next->data; 
	node* d=c->next;
	c->next=d->next;
	delete d;
}

void printList(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
