#include<iostream>
using namespace std;

/* logic:
 * http://fisherlei.blogspot.com/search?q=rotate+list
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
ListNode *rotateRight(ListNode *head, int k);

int main()
{
	ListNode* head=new ListNode(1);
	head->next=new ListNode(2);
	head->next->next=new ListNode(3);
	head->next->next->next=new ListNode(4);
	head->next->next->next->next=new ListNode(5);
	head->next->next->next->next->next=new ListNode(6);
	printList(head);
	ListNode* newHead=rotateRight(head, 6);
	printList(newHead);
	
	newHead=rotateRight(newHead, 2);
	printList(newHead);

	newHead=rotateRight(newHead, 4);
	printList(newHead);

	newHead=rotateRight(newHead, 7);
	printList(newHead);

	return 0;
}

ListNode *rotateRight(ListNode *head, int k)
{
	if(head==nullptr)
		return head;
	ListNode *head0=new ListNode(-1);
	head0->next=head;
	ListNode *cur=head;
	int len=1;
	while(cur->next!=nullptr)
	{
		len++;
		cur=cur->next;
	}
	cur->next=head;
	ListNode* prev=head0;
	int step=len-k%len; /////////Important: deal with corner case when k>n
	while(step>0)
	{
		prev=prev->next;
		head=head->next;
		step--;
	}
	prev->next=nullptr;
	delete head0;
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

