#include<iostream>
using namespace std;

/* logic:
 * 
 * !! notice the corner case when k>=length of list
*/

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
void reorderList(ListNode *head);

int main()
{
	ListNode* head=new ListNode(1);
	head->next=new ListNode(2);
	//head->next->next=new ListNode(3);
	//head->next->next->next=new ListNode(4);
	//head->next->next->next->next=new ListNode(5);
	//head->next->next->next->next->next=new ListNode(6);
	//head->next->next->next->next->next->next=new ListNode(7);
	printList(head);

	reorderList(head);
	printList(head);
	return 0;
}

void reorderList(ListNode *head)
{
	if(head==nullptr || head->next==nullptr)
		return;

	// step 1: find the middle node and split
	ListNode *head0=head;
	ListNode *head1=head;
	ListNode *first=head;
	ListNode *second=head;
	while(true)
	{
		second=second->next;
		if(second==nullptr)
			break;
		second=second->next;
		if(second==nullptr)
			break;
		first=first->next;
	}
	head1=first->next; // the head of the second list
	first->next=nullptr; // split
	
	// step 2: reverse the second list
	ListNode* cur=head1;
	ListNode* post=head1->next;
	ListNode* temp;
	while(post!=nullptr)
	{
		temp=post->next;
		post->next=cur;
		cur=post; 
		post=temp;
	}
	head1->next=nullptr;
	head1=cur;
	
	// step 3: merge two list
	cur=head;
	head0=head0->next;
	while(head0!=nullptr || head1!=nullptr)
	{
		if(head1!=nullptr)
		{
			cur->next=head1;
			cur=cur->next;
			head1=head1->next;
		}
		if(head0!=nullptr)
		{
			cur->next=head0;
			cur=cur->next;
			head0=head0->next;
		}
	}
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

