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
ListNode *reverseKGroup(ListNode *head, int k);
ListNode *reverseList(ListNode *head);

int main()
{
	ListNode* head=new ListNode(1);
	head->next=new ListNode(2);
	head->next->next=new ListNode(3);
	head->next->next->next=new ListNode(4);
	head->next->next->next->next=new ListNode(5);
	head->next->next->next->next->next=new ListNode(6);
	head->next->next->next->next->next->next=new ListNode(7);
	head->next->next->next->next->next->next->next=new ListNode(8);
	printList(head);

	ListNode* newHead=reverseKGroup(head, 3);
	printList(newHead);

	return 0;
}

ListNode *reverseList(ListNode *head)
{
	if(head==nullptr || head->next==nullptr)
		return head;
	ListNode* cur=head;
	ListNode* post=head->next;
	ListNode* temp;
	while(post!=nullptr)
	{
		temp=post->next;
		post->next=cur;
		cur=post;
		post=temp;
	}
	head->next=nullptr;
	return cur;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
	if(head==nullptr || k==1)
		return head;
	ListNode* sudoHead=new ListNode(-1);
	ListNode* head0=sudoHead;
	ListNode* cur=head;
	ListNode* prev=head;
	ListNode* post;
	int num=1;
	while(cur!=nullptr)
	{
		if(num==k)
		{
			post=cur->next;
			cur->next=nullptr;
			prev=reverseList(prev);
			head0->next=prev;
			while(head0->next!=nullptr)
				head0=head0->next;
			prev=post;
			cur=post;
			num=1;
		}
		else
		{
			num++;
			cur=cur->next;
		}
	}
	head0->next=prev;

	ListNode* result=sudoHead->next; //Important!!!
	delete sudoHead;
	return result;
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

