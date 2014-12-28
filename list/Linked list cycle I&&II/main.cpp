// reference: http://blog.csdn.net/kenden23/article/details/13871699
/*
1. 假设圈的周长L, a is the distance before entering the circle, b is the distance between the cycle node
   and the meeting node
2. 那么相遇的时候slow走：a + b,而fast走：a + b + n*L，（n代表fast走了多少圈）
3. fast走路的路程是slow的两倍，那么2(a+b) = a + b + n*L，得到a = n*L - b
4 从相遇点的时候开始，放一个指针从开始点走起，另一个指针继续走，而且这时走的速度都是一样的，
  那么当一个指针从开始点X走到循环圈点Y的时候，走了a路程，而另一个指针走的路程是n*L-b，
  那么两者的路程是一样的，相遇点必然是Y。
*/

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
