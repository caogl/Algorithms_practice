#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head);

int main()
{
	ListNode *head=new ListNode(1);
	ListNode *head1=head;
	head1->next=new ListNode(2);
	head1=head1->next;
	head1->next=new ListNode(9);
	head1=head1->next;
	head1->next=new ListNode(4);
	head1=head1->next;
	head1->next=new ListNode(9);
	head1=head1->next;
	head1->next=new ListNode(7);
	head1=head1->next;
	head1->next=new ListNode(6);
	head1=head1->next;
	head1->next=new ListNode(10);
	head1=head1->next;
	head1->next=new ListNode(3);
	head1=head1->next;

	//ListNode* head2=head1;

	head1->next=new ListNode(5);
	head1=head1->next;
	head1->next=new ListNode(9);
	head1=head1->next;
	head1->next=new ListNode(9);
	head1=head1->next;
	head1->next=new ListNode(12);
	head1=head1->next;

	ListNode* head2=head1;

	head1->next=new ListNode(3);
	head1=head1->next;
	head1->next=new ListNode(7);
	head1=head1->next;
	head1->next=new ListNode(10);
	head1=head1->next;
	head1->next=new ListNode(8);
	head1=head1->next;
	head1->next=head2;

	ListNode *cycle=detectCycle(head);
	cout<<"the cycle val is: "<<cycle->val<<" "<<cycle->next->val<<"..."<<endl;
	
}

ListNode *detectCycle(ListNode *head)
{
	if(head==nullptr)
        	return nullptr;
        ListNode * first = head;
        ListNode * second = head;
        while(first != NULL && second != NULL)
        {
        	first = first->next;
        	second = second->next;
        	if(second != NULL)
         		second = second->next;
        	else
                	return nullptr;
        	if(first == second)
                	break;
        }
         
        if(second == NULL)
		return NULL;

        first = head;
        while(first!=second)
        {
        	first = first->next;
        	second = second->next;
        }
        return second;
}
