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
void removeDuplicate2(node* head); // The in place method with constant additional memory
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

void removeDuplicate2(node* head)
{
	if(head==NULL || head->next==NULL)
	return;
	node* checkStart1;
	node* checkStart2;
	while(head->next!=NULL)
	{
		checkStart1=head;
		checkStart2=head->next;
		while(checkStart2!=NULL)
		{
			if(checkStart2->data==head->data)
			{
				if(checkStart2->next!=NULL)
				{
					node* tmp=checkStart2;
					checkStart2=checkStart2->next;
					checkStart1->next=checkStart2;
					delete tmp;
				}
				else
				{
					delete checkStart2;
					checkStart1->next=NULL;
					checkStart2=NULL;
				}
			}
			if(checkStart2!=NULL) // since checkStart2 has moved, remember whenever a node tries 
					      // to access next, test whether it is NULL first!!!
			{
				checkStart1=checkStart1->next;
				checkStart2=checkStart2->next;
			}
		}
		head=head->next;
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
