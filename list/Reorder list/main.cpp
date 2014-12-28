// reference: http://yucoding.blogspot.com/2013/12/leetcode-question-reorder-list.html

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
void reorderList(ListNode *head);

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

	reorderList(head);
	printList(head);
	return 0;
}

void reorderList(ListNode *head) 
{
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr)
            return;

        /* step(1): partition */
        ListNode* head1=head;
        ListNode* head2=head;
        head2=head2->next;
        while(head2!=nullptr && head2->next!=nullptr)
        {
            head2=head2->next->next;
            head1=head1->next;
        }
        head2=head1->next;
        head1->next=nullptr;

        /* step(2): reorder second list */
        ListNode* prev=head2; // cannot be nullptr since the length of the list is at least 2
        ListNode* cur=prev->next;
        prev->next=nullptr;
        ListNode* post;
        while(cur!=nullptr)
        {
            post=cur->next;
            cur->next=prev;
            prev=cur;
            cur=post;
        }
        head2=prev;
        head1=head;

        /* step(3): merge two list */
        head1=head1->next; // This step necessary!!! or when head=head2, head1 still equals head, mess......!!!
        while(head1!=nullptr || head2!=nullptr)
        {
            if(head2!=nullptr)
            {
                head->next=head2;
                head2=head2->next;
                head=head->next;
            }
            if(head1!=nullptr)
            {
                head->next=head1;
                head1=head1->next;
                head=head->next;
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
