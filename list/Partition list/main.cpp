#include<iostream>
using namespace std;

/* logic:
 * find the first element in the list greater than x, then insert every element on the right that is bigger than x to the left of x, such keep stable
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
ListNode* partition(ListNode* head, int x);

int main()
{
	ListNode* head=new ListNode(1);
	head->next=new ListNode(4);
	head->next->next=new ListNode(3);
	head->next->next->next=new ListNode(2);
	head->next->next->next->next=new ListNode(5);
	head->next->next->next->next->next=new ListNode(0);
	printList(head);
	ListNode* newHead=partition(head, 3);
	printList(newHead);
	
	return 0;
}

ListNode* partition(ListNode* head, int x)
{
	if(head==nullptr || head->next==nullptr)
		return head;
	ListNode* sudoHead=new ListNode(-1);
	sudoHead->next=head;
	ListNode* prev=sudoHead;
	while(head!=nullptr && head->val<x)
	{
		head=head->next;
		prev=prev->next;
	}

	if(head!=nullptr && head->next!=nullptr)
	{
		ListNode* prevCur=head;
		ListNode* cur=prevCur->next;
		while(cur!=nullptr)
		{
			if(cur->val<x)
			{
				prev->next=cur;
				prev=prev->next;
				prevCur->next=cur->next;
				cur->next=head;
				cur=prevCur->next;
			}
			else
			{
				prevCur=prevCur->next;
				cur=cur->next;
			}
		}
	}
	ListNode* result=sudoHead->next;
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


