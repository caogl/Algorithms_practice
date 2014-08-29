#include<iostream>
using namespace std;

//My own solution is space and time right, but cannot pass leetcode test cases

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
ListNode *sortList(ListNode *head);
ListNode* sortSubList(ListNode* l1, int step);

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
	if(head==nullptr)
		return head;
	int len=0; // length of the list
	ListNode* sudoHead=new ListNode(-1);
	sudoHead->next=head;
	ListNode* temp=sudoHead;
	while(temp!=nullptr)
	{
		temp=temp->next;
		len++;
	}

	int interval_len=2;
	ListNode* head0=sudoHead;
	ListNode* prev=head;
	ListNode* post;
	ListNode* cur=head;
	int step=1;
	while(interval_len<=len)
	{
		while(cur!=nullptr)
		{
			if(step==interval_len)
			{
				post=cur->next;
				cur->next=nullptr;
				prev=sortSubList(prev, interval_len/2);
				head0->next=prev;
				while(head0->next!=nullptr)
					head0=head0->next;
				prev=post;
				cur=post;
				step=1;
			}
			else
			{
				cur=cur->next;
				step++;
			}
		}
		prev=sortSubList(prev, interval_len);
		step=1;
		head0->next=prev;
		
		cur=sudoHead->next;
		prev=cur;
		head0=sudoHead;
		interval_len=interval_len*2;
	}
	
	head=sortSubList(sudoHead->next, interval_len/2);
	delete sudoHead;
	return head;
}

ListNode* sortSubList(ListNode* l1, int step)
{
	if(l1==nullptr || l1->next==nullptr)
		return l1;

	ListNode* l2=l1;
	while(step>1)
	{
		l2=l2->next;
		step--;
	}
	ListNode* l3=l2;
	l2=l2->next;
	l3->next=nullptr;

	if(l2==nullptr)
		return l1;

	ListNode* sudoHead=new ListNode(-1);
	ListNode* head=sudoHead;
	while(l1!=nullptr && l2!=nullptr)
	{
		if(l1->val<=l2->val)
		{
			head->next=l1;
			head=head->next;
			l1=l1->next;
			head->next=nullptr;
		}
		else
		{
			head->next=l2;
			head=head->next;
			l2=l2->next;
			head->next=nullptr;
		}
	}
	if(l1!=nullptr)
		head->next=l1;
	if(l2!=nullptr)
		head->next=l2;
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

// Following is the solution that can pass all test cases
/*
  ListNode *sortList(ListNode *head) {  
       // Get length first  
       ListNode* p = head;  
       int len = 0;  
       while (p != NULL)  
       {  
            p = p->next;  
            len++;  
       }  
       ListNode* fakehead = new ListNode(-1);  
    fakehead->next = head;       
       for (int interval = 1; interval <= len; interval = interval * 2)  
       {  
            ListNode* pre = fakehead;  
            ListNode* slow = fakehead->next, *fast = fakehead->next;  
            while (fast != NULL || slow != NULL)  
            {  
                 int i = 0;  
                 while (i< interval && fast != NULL)  
                 {  
                      fast = fast->next; //move fast pointer ahead 'interval' steps  
                      i++;  
                 }  
                 //merge two lists, each has 'interval' length  
                 int fvisit = 0, svisit = 0;  
                 while (fvisit < interval && svisit<interval && fast != NULL && slow != NULL)  
                 {  
                      if (fast->val < slow->val)  
                      {  
                           pre->next = fast;  
                           pre = fast;  
                           fast = fast->next;  
                           fvisit++;  
                      }  
                      else  
                      {  
                           pre->next = slow;  
                           pre = slow;  
                           slow = slow->next;  
                           svisit++;  
                      }  
                 }  
                 while (fvisit < interval && fast != NULL)  
                 {  
                      pre->next = fast;  
                      pre = fast;  
                      fast = fast->next;  
                      fvisit++;  
                 }  
                 while (svisit < interval && slow != NULL)  
                 {  
                      pre->next = slow;  
                      pre = slow;  
                      slow = slow->next;  
                      svisit++;  
                 }  
                 pre->next = fast;  
                 slow = fast;  
            }  
       }  
       ListNode* newhead = fakehead->next;  
       delete fakehead;  
       return newhead;  
  }
*/  
