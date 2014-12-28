#include<iostream>
#include<unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head);
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

int main()
{
	ListNode* head1=new ListNode(7);
	head1->next=new ListNode(0);
	head1->next->next=new ListNode(5);
	head1->next->next->next=new ListNode(9);

	ListNode* head2=new ListNode(6);
	head2->next=new ListNode(9);
	head2->next->next=new ListNode(4);
	
	ListNode* head=addTwoNumbers(head1, head2);
	printList(head);
	return 0;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	if(l1==nullptr)
		return l2;
	if(l2==nullptr)
		return l1;
	
	ListNode* sudoHead=new ListNode(-1);
	ListNode* head=sudoHead;
	int addNext=0; // to add to the next position
	
	while(l1!=nullptr && l2!=nullptr)
	{
		int num=l1->val+l2->val+addNext;
		int digit=num%10;
		head->next=new ListNode(digit);
		addNext=num/10;
		head=head->next;
		l1=l1->next;
		l2=l2->next;
	}
	
	while(l1!=nullptr)
	{
		int num=l1->val+addNext;
		int digit=num%10;
		head->next=new ListNode(digit);
		addNext=num/10;
		head=head->next;
		l1=l1->next;
	}
	while(l2!=nullptr)
	{
		int num=l2->val+addNext;
		int digit=num%10;
		head->next=new ListNode(digit);
		addNext=num/10;
		head=head->next;
		l2=l2->next;
	}

	// don't forget the remaining addNext!!!
	if(addNext!=0)
		head->next=new ListNode(addNext);
	
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
