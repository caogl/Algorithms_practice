// reference: http://www.cnblogs.com/yuzhangcmu/p/4128794.html

#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

int main()
{
	ListNode* headA=new ListNode(1);
	ListNode* headB=new ListNode(5);
	headA->next=new ListNode(2);
	headA->next->next=new ListNode(3);
	headA->next->next->next=new ListNode(4);
	ListNode* headI=new ListNode(6);
	headI->next=new ListNode(7);
	headI->next=new ListNode(8);
	headB->next=headI;
	headA->next->next->next->next=headI;
	
	headI=getIntersectionNode(headA, headB);
	cout<<headI->val<<endl;
	return 0;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	int lenA=0;
	int lenB=0;
	if(headA==nullptr || headB==nullptr)
		return nullptr;

	ListNode* head=headA;
	while(head!=nullptr)
	{
		lenA++;
		head=head->next;
	}
	head=headB;
	while(head!=nullptr)
	{
		lenB++;
		head=head->next;
	}

	int diff=abs(lenA-lenB);
	if(lenA>lenB)
	{
		for(int i=0; i<diff; i++)
			headA=headA->next;
	}
	else
	{
		for(int i=0; i<diff; i++)
			headB=headB->next;
	}

	while(headA!=headB)
	{
		headA=headA->next;
		headB=headB->next;
	}

	return headA;
}
