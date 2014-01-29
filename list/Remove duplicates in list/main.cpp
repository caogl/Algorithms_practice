#include<iostream>
#include<unordered_set>
using namespace std;

struct node
{
	int data;
	node* next;
};
node* init(int a[], int n);
void removeDuplicate1(node* head); // Direct, not the in place method.
void removeDuplicate2(node* head); // The in place method
void printList(node* head);

int main()
{
	int a[]={2,3,5,1,2,4,2,3,7,1,4,7,8,5,6,6,9,0,8};
	node* testHead=init(a, 19);
	printList(testHead);
	cout<<endl;
	removeDuplicate1(testHead);
	printList(testHead);
	cout<<endl;
	int a1[]={2,3,5,1,2,4,2,3,7,1,4,7,8,5,6,6,9,0,8};
	testHead=init(a1, 19);
	printList(testHead);
	cout<<endl;
	removeDuplicate2(testHead);
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

/*   //This is a self-written version, but it is very subtle and easy to make mistakes, since addtional checks must be applied
void removeDuplicate2(node* head)
{
	node *tmp=head;
	node *tmp1=tmp;
	int tmpInt;
	while(tmp!=NULL)
	{
		tmpInt=tmp->data;
		while(tmp1->next!=NULL)
		{
			if(tmp1->next->data==tmpInt)
			{
				node *d=tmp1->next;
				tmp1->next=tmp1->next->next;
				delete d;
			}
			tmp1=tmp1->next;
			if(tmp1==NULL) // additional check must be applied here to avoid "NULL->next" mistake
				break;
		}
		tmp=tmp->next;
		tmp1=tmp;
	}
}
*/

void removeDuplicate2(node* head)
{
	node *a, *b, *c;
	c=head;
	while(c!=NULL)
	{
		a=c;
		b=a->next;
		int tmp=c->data;
		while(b!=NULL)
		{
			if(b->data==tmp)
			{
				node *d=b;
				a->next=b->next;
				b=b->next;
				delete d;
			}
			else
			{
				a=a->next;
				b=b->next;
			}
		}
		c=c->next;
	}
}

void removeDuplicate1(node* head)
{
	unordered_set<int> hashSet;
	node *c=head;
	node *a=c->next;
	hashSet.insert(c->data);
	while(a!=NULL)
	{
		if(hashSet.find(a->data)!=hashSet.end())
		{
			node *d=a;
			c->next=a->next;
			a=a->next;
			delete d;
		}
		else
		{
			hashSet.insert(a->data);
			c=a;
			a=a->next;
		}
	}
}

void printList(node* head)
{
	node *tmp=head;
	while(tmp!=NULL)
	{
		cout<<tmp->data<<" ";
		tmp=tmp->next;
	}
}