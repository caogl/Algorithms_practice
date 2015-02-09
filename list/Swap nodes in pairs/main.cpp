#include<iostream>
using namespace std;

/*
	1->2->3->4->5
	(-1)->1->2->3->4->5
	(-1)->1-> <-2 3->4->5
	(-1)->2->1->3->4->5
	...... 
	key: keep track of 4 positions: prevCon (keep track of the previous node before the swapping pair)
					prev, con (the swapping node)
					post (the starting position of next possible pair)
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
        if(!head || !head->next)    return head;

        ListNode* sudoHead=new ListNode(-1);
        sudoHead->next=head;
        ListNode* prev1=sudoHead;
        ListNode* prev=head;
        ListNode* cur=head->next;
        ListNode* post=nullptr;
        while(true)
        {
            post=cur->next;
            cur->next=prev;
            prev->next=post;
            prev1->next=cur;
            prev1=prev; // important step, since now cur->prev->post. assign prev1 to prev rather than cur !!!
            prev=post;

            if(!prev || !prev->next)   break;
            cur=prev->next;
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

