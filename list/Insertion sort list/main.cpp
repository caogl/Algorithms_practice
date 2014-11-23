#include<iostream>
using namespace std;

struct ListNode
{
        int val;
        ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insertionSortList(ListNode *head);
void traverse(ListNode* head);

int main()
{
	ListNode* head=new ListNode(4);
	head->next=new ListNode(5);
	head->next->next=new ListNode(3);
	head->next->next->next=new ListNode(0);
	head->next->next->next->next=new ListNode(6);
	head->next->next->next->next->next=new ListNode(1);
	head->next->next->next->next->next->next=new ListNode(2);
	traverse(head);
	head=insertionSortList(head);
	traverse(head);
	return 0;
}

ListNode *insertionSortList(ListNode *head)
{
	if(head==nullptr)
		return head;
	
	ListNode* sudoHead=new ListNode(-1);
	sudoHead->next=head;
	ListNode* cur=sudoHead; // !!! cur->next is the real node that we want to perform insert on
	ListNode* pre;

	while(cur->next!=nullptr)
	{
		pre=sudoHead;
		bool inserted=false;
		while(pre!=cur)
		{
			if(pre->next->val>cur->next->val)
			{
				/* perform insert */
				ListNode* tmp=cur->next;
				cur->next=cur->next->next;
				tmp->next=pre->next;
				pre->next=tmp;
				inserted=true;
				break;
			}
			else
				pre=pre->next;
		}
		if(!inserted)
			cur=cur->next;
	}
	head=sudoHead->next;
	delete sudoHead;
	return head;
}

void traverse(ListNode* head)
{
	while(head!=nullptr)
	{
		cout<<head->val;
		head=head->next;
	}
	cout<<endl;
}
