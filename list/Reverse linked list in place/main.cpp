#include<iostream>
using namespace std;

/* logic:
 * list before reverse: 1->2->3->4->5->6
 * if reverseBetween(listName, 2, 5) is called:
 * -1->1->2->3->4->5->6 (create sudo head -1, which is useful if m=1, reverse from head)
 * -1->1->2<->3, 4->5->6, where prev=1, cur=2, post=3, temp=4
 * -1->1->2<->3<-4, 5->6, where prev=1, cur=3, post=4, temp=5
 * -1->1->2<->3<-4<-5, 6, where prev=1, cur=4, post=5, temp=6
 * -1->1->5->4->3->2->6, namely in this step, 2->6, 1->5
 * 1->5->4->3->2->6, return sudoHead->next and delete sudoHead.
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
void printList1(ListNode* head, int num);
ListNode *reverseBetween(ListNode *head, int m, int n);

int main()
{
	ListNode* head=new ListNode(1);
	head->next=new ListNode(2);
	head->next->next=new ListNode(3);
	head->next->next->next=new ListNode(4);
	head->next->next->next->next=new ListNode(5);
	head->next->next->next->next->next=new ListNode(6);
	printList(head);
	ListNode* newHead=reverseBetween(head, 1, 6);
	printList(newHead);

	newHead=reverseBetween(newHead, 2, 5);
	printList(newHead);		
	return 0;
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

void printList1(ListNode* head, int num)
{
	for(int i=0; i<num; i++)
	{
		cout<<head->val<<"	";
		head=head->next;
	}
	cout<<endl;
}

ListNode *reverseBetween(ListNode *head, int m, int n)
{
	if(head==nullptr || head->next==nullptr)
		return head;
	ListNode* sudoHead=new ListNode(-1);
	sudoHead->next=head;
	ListNode *prev=sudoHead;
	
	int steps=n-m; // the length that need to be reversed
	while(m>1)
	{
		prev=prev->next; // move prev to the position before the sublist to be reversed
		m--;
	}
	
	ListNode* cur=prev->next; 
	ListNode* post=cur->next;
	ListNode* temp;
	
	while(steps>0 && post!=nullptr)
	{
		temp=post->next;
		post->next=cur;
		cur=post;
		post=temp;
		steps--;
	}
	prev->next->next=post;
	prev->next=cur;
	ListNode* result=sudoHead->next;
	delete sudoHead;
	return result;
}
