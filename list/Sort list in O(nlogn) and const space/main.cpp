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
ListNode* sortList(ListNode *head);
ListNode* mergeSort(ListNode* a, ListNode*b);

int main()
{
	ListNode* head=new ListNode(5);
	head->next=new ListNode(7);
	head->next->next=new ListNode(3);
	head->next->next->next=new ListNode(9);
	head->next->next->next->next=new ListNode(1);
	head->next->next->next->next->next=new ListNode(2);
	ListNode* head1=head->next->next->next->next->next->next=new ListNode(8);
	head1->next=new ListNode(6);
	head1->next->next=new ListNode(4);
	printList(head);

	ListNode* newHead=sortList(head);
	printList(newHead);

	return 0;
}

ListNode *sortList(ListNode *head)
{
	if(head==nullptr || head->next==nullptr)
		return head;
	ListNode* a=head;
	ListNode* b=head->next; // if simply assign ListNode* b=head; ----> will be segmentation fault
				// because if there are only 2 nodes (1->2->nullptr)in the list,
				// will always partition to (1->2->nullptr) and (nullptr), deadloop!!! 
	// when partition the list, iif b can go forward two steps not one or zero, a go one step!!!
	while(b!=nullptr && b->next!=nullptr)
	{
		a=a->next;
		b=b->next->next;
	}

	b=a->next;
	a->next=nullptr;
	return mergeSort(sortList(head), sortList(b));
}

ListNode* mergeSort(ListNode* a, ListNode* b)
{
	if(a==nullptr)	return b;
	if(b==nullptr)	return a;

	ListNode* head;
	if(a->val<b->val)
	{
		head=a;
		a=a->next;
	}
	else
	{
		head=b;
		b=b->next;
	}
	ListNode* head0=head;
	
	while(a!=nullptr && b!=nullptr)
	{
		if(a->val<b->val)
		{
			head->next=a;
			a=a->next;
		}
		else
		{
			head->next=b;
			b=b->next;
		}
		head=head->next;
	}
	
	if(a!=nullptr)
		head->next=a;
	else	
		head->next=b;
	return head0;
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

