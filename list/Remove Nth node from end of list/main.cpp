#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x)
	{
		val=x;
		next=nullptr;
	}
};

void printList(ListNode* head);
ListNode *removeNthFromEnd(ListNode *head, int n);

int main()
{
	ListNode* head=new ListNode(1);
	head->next=new ListNode(2);
	head->next->next=new ListNode(3);
	head->next->next->next=new ListNode(4);
	head->next->next->next->next=new ListNode(5);
	head->next->next->next->next->next=new ListNode(6);
	head->next->next->next->next->next->next=new ListNode(7);
	printList(head);

	ListNode* newHead=removeNthFromEnd(head, 2);
	//ListNode* newHead=removeNthFromEnd(head, 7);
	//ListNode* newHead=removeNthFromEnd(head, 0);

	printList(newHead);

	return 0;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
	if(head==nullptr)
		return head;
	//Also need the sudo head pointer!!!
	ListNode* sudoHead=new ListNode(-1);
	sudoHead->next=head;
	ListNode* fast=sudoHead;
	while(n>0)
	{
		fast=fast->next;
		n--;
	}
	ListNode* slow=sudoHead;
	ListNode* temp;
	if(fast!=nullptr)
	{
		while(fast->next!=nullptr)
		{
			fast=fast->next;
			slow=slow->next;
		}
	}
	
	if(slow->next!=nullptr)
	{
		temp=slow->next;
		if(temp!=nullptr)
		{
			slow->next=temp->next;
			delete temp;
		}
	}
	
	head=sudoHead->next;
	delete sudoHead;
	return head;
}

void printList(ListNode* head)
{
	while(head!=NULL)
	{
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}

