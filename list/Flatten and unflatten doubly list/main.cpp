#include<iostream>
using namespace std;

struct node
{
	node(int data1)
	{
		next=NULL;
		prev=NULL;
		child=NULL;
		data=data1;
	}
	node *next;
	node *prev;
	node *child;
	int data;
};

void flattenList(node *head, node* & tail);
void append(node *child, node* & tail);
//void flattenListRecursion(node *head, node* & tail);
//void appendRecursion(node *child, node* & tail);
void printFlattenList(node *head);
void unflattenList(node *head, node* & tail);
void dispatch(node *head);
void printUnflattenList(node *head);

int main()
{
	node *head=new node(5);
	node *parent1=head;
	head->next=new node(33);
	node *current=head->next;
	current->prev=head;
	current->next=new node(17);
	current->next->prev=current;
	current=current->next;
	current->next=new node(2);
	current->next->prev=current;
	current=current->next;
	node *parent2=current;
	node *tail=current->next=new node(1);
	current->next->prev=current;
	current=parent1->child=new node(6);
	current->next=new node(25);
	current->next->prev=current;
	parent1=current=current->next;
	parent1->child=new node(8);
	current->next=new node(6);
	current->next->prev=current;
	parent1=current->next;
	parent1=parent1->child=new node(9);
	parent1->child=new node(7);
	parent2=current=parent2->child=new node(2);
	current->next=new node(7);
	current->next->prev=current;
	parent2=parent2->child=new node(12);
	parent2->next=new node(5);
	parent2->next->prev=parent2;
	parent2=parent2->child=new node(21);
	parent2->next=new node(3);
	parent2->next->prev=parent2;
	printUnflattenList(head);
	cout<<endl;
	flattenList(head, tail);
	printFlattenList(head);
	cout<<endl;
	unflattenList(head, tail);
	printUnflattenList(head);
	system("PAUSE");
	return 0;
}

void printUnflattenList(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		if(head->child!=NULL)
			printUnflattenList(head->child);
		head=head->next;
	}
}

void unflattenList(node *head, node* & tail)
{
	dispatch(head);
	while(head->next!=NULL)
		head=head->next;
	tail=head;
}

void dispatch(node *head)
{
	while(head!=NULL)
	{
		//cout<<"head data is: "<<head->data<<" ";
		if(head->child!=NULL)
		{
			//cout<<"child data is: "<<head->child->data<<" ";
			if(head->child->prev!=NULL) // MUST implement the check here!
			{
				head->child->prev->next=NULL;
				head->child->prev=NULL;
				dispatch(head->child);
			}
		}
		head=head->next;
	}
}

void flattenList(node *head, node* & tail)
{
	while(head!=NULL)
	{
		if(head->child!=NULL)
		{
			//cout<<tail->data<<" ";
			append(head->child, tail);
		}
		head=head->next;
	}
}

void append(node *child, node* & tail)
{
	tail->next=child;
	child->prev=tail;
	while(child->next!=NULL)
	{
		//cout<<child->data<<" ";
		child=child->next;
	}
	//cout<<tail->data<<" ";
	tail=child;
}

void printFlattenList(node *head)
{
	cout<<head->data<<" ";
	while(head->next!=NULL)
	{
		cout<<head->next->data<<" ";
		head=head->next;
	}
}