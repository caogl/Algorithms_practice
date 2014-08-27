#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

struct node
{
	int data;
	node* next;
	node(int data1):data(data1), next(nullptr){}
};
node* init(int a[], int n);
void removeDuplicate1(node* head); // Direct, not the in place method.
void removeDuplicate2(node* head); // The in place method with constant additional memory
node* removeDuplicate3(node* head); // remove all the elemnets appear more than once

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

	cout<<endl;
	int a2[]={2,3,5,1,2,4,2,3,7,1,4,7,8,5,6,6,9,0,8};
	testHead=init(a2, 19);
	printList(testHead);
	cout<<endl;
	testHead=removeDuplicate3(testHead);
	printList(testHead);
	cout<<endl;

	return 0;
}

node* init(int a[], int n)
{
	node *head, *p;
	for(int i=0; i<n; i++)
	{
		node *nd=new node(a[i]);
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

node* removeDuplicate3(node* head)
{
	unordered_map<int, int> hashMap;
	node* head1=head;
	while(head1!=nullptr)
	{
		if(hashMap.find(head1->data)==hashMap.end())
			hashMap[head1->data]=1;
		else
			hashMap[head1->data]++;
		head1=head1->next;
	}
	node* head2=new node(0);
	head2->next=head;
	node* prev=head2;
	node* currentP=head;
	while(currentP!=nullptr)
	{
		if(hashMap[currentP->data]>1)
		{
			node *temp=currentP;
			currentP=currentP->next;
			prev->next=currentP;
			delete temp;
		}
		else
		{
			prev=prev->next;
			currentP=currentP->next;
		}
	}
	return head2->next;
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
