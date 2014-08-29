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
ListNode *swapPairs(ListNode *head);

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

	ListNode* newHead=swapPairs(head);
	printList(newHead);

	return 0;
}

ListNode *swapPairs(ListNode *head)
{
	if(head==nullptr || head->next==nullptr)
		return head;
	ListNode* sudoHead=new ListNode(-1);
	sudoHead->next=head;
	ListNode* prev=sudoHead;
	ListNode* cur=head;
	ListNode* post=head->next;
	ListNode* temp;
	while(post!=nullptr)
	{
		temp=post->next;
		prev->next=post;
		post->next=cur;
		cur->next=temp;

		prev=post;
		cur=prev->next;
		post=cur->next;
		if(post==nullptr)
			break;
		prev=prev->next;
		cur=cur->next;
		post=post->next;
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

