#include<iostream>
#include<unordered_set>
using namespace std;

struct node
{
	int data;
	node* next;
};
node* init(int a[], int n);
node* addList(node *node1, node *node2);
void printList(node* head);

int main()
{
	int a[]={9,8,7,6};
	node *testHeada=init(a, 4);
	cout<<"a is: ";
	printList(testHeada);
	cout<<endl;
	int b[]={9,0,8,9};
	node *testHeadb=init(b, 4);
	cout<<"b is: ";
	printList(testHeadb);
	cout<<endl;
	node *testHeadSum=addList(testHeada, testHeadb);
	cout<<"the sum of a and b is: ";
	printList(testHeadSum);
	cout<<endl;
	int c[]={9,9};
	node *testHeadc=init(c,2);
	cout<<"c is: ";
	printList(testHeadc);
	cout<<endl;
	testHeadSum=addList(testHeada, testHeadc);
	cout<<"the sum of a and c is: ";
	printList(testHeadSum);
	cout<<endl;
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

node* addList(node *node1, node *node2)
{
	node *head=NULL; //Must initialize like this, without "=NULL" there will be errors!!!!
	node *p;
	int c=0;
	int digit;
	if(node1==NULL)
		return node2;
	if(node2==NULL)
		return node1;
	while(node1!=NULL && node2!=NULL)
	{
		node *nd=new node();
		if(head==NULL)
		{
			head=nd;
			c=node1->data+node2->data+c;
			digit=c%10;
			head->data=digit;
			c=c/10;
			p=head;
		}
		else
		{
			p->next=nd;
			p=p->next;
			c=node1->data+node2->data+c;
			digit=c%10;
			p->data=digit;
			c=c/10;
		}
		node1=node1->next;
		node2=node2->next;
	}
	while(node1!=NULL)
	{
		node *nd=new node();
		p->next=nd;
		p=p->next;
		c+=node1->data;
		digit=c%10;
		p->data=digit;
		c=c/10;
		node1=node1->next;
	}
	while(node2!=NULL)
	{
		node *nd=new node();
		p->next=nd;
		p=p->next;
		c+=node2->data;
		digit=c%10;
		p->data=digit;
		c=c/10;
		node2=node2->next;
	}
	if(c>0)
	{
		node *nd=new node();
		p->next=nd;
		p=p->next;
		p->data=c;
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