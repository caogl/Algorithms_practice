#include<iostream>
using namespace std;

/*
 * find the first element in the list greater than x, then insert every element on the right that is bigger than x to the left of x, such keep stable
 * Also use the prev->next and cur->next to keep track of the node
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
	//newHead=partition(head, 6);
	//printList(newHead);
	
	return 0;
}

ListNode *partition(ListNode *head, int x)
{
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* sudoHead=new ListNode(-1);
        ListNode* prev=sudoHead;
        sudoHead->next=head;
        while(prev->next!=nullptr && prev->next->val<x)
        {
            prev=prev->next;
        }
        
        ListNode* cur=prev;
        while(prev->next!=nullptr)
        {
            if(prev->next->val<x)
            {
                ListNode* tmp=prev->next->next;
                prev->next->next=cur->next;
                cur->next=prev->next;
		cur=cur->next; // do not change the relative order of the numbers smallers than x !!!
                prev->next=tmp;
            }
            else
                prev=prev->next;
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


