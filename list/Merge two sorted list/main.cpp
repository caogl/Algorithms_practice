#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	node(int data1)
	{
		data=data1;
		next=NULL;
	}
};

void printList(node* head);
node* mergeList(node* head1, node* head2);

int main()
{
	node* head1=new node(1);
	head1->next=new node(5);
	head1->next->next=new node(6);
	head1->next->next->next=new node(8);
	head1->next->next->next->next=new node(9);
	head1->next->next->next->next->next=new node(10);
	printList(head1);

	node* head2=new node(2);
	head2->next=new node(3);
	head2->next->next=new node(4);
	head2->next->next->next=new node(7);
	head2->next->next->next->next=new node(11);
	head2->next->next->next->next->next=new node(12);
	head2->next->next->next->next->next->next=new node(13);
	printList(head2);

	node* newHead=mergeList(head1, head2);
	printList(newHead);
	system("pause");
	return 0;
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

node* mergeList(node* head1, node* head2)
{
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;
	node *head0=new node(0);
	node* head=head0;
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data<head2->data)
		{
			head->next=head1;
			head1=head1->next;
			head=head->next;
		}
		else
		{
			head->next=head2;
			head2=head2->next;
			head=head->next;
		}
	}
	if(head1!=NULL)
		head->next=head1;
	else
		head->next=head2;
	return head0->next;
}
