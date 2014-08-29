#include<iostream>
#include<vector>
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
ListNode *mergeKLists(vector<ListNode *> &lists);
ListNode *merge2Lists(ListNode* l1, ListNode* l2);

int main()
{
	ListNode* head1=new ListNode(1);
	head1->next=new ListNode(7);
	head1->next->next=new ListNode(10);
	head1->next->next->next=new ListNode(13);
	head1->next->next->next->next=new ListNode(25);
	head1->next->next->next->next->next=new ListNode(26);
	head1->next->next->next->next->next->next=new ListNode(37);
	printList(head1);

	ListNode* head2=new ListNode(11);
	head2->next=new ListNode(12);
	head2->next->next=new ListNode(14);
	head2->next->next->next=new ListNode(23);
	head2->next->next->next->next=new ListNode(24);
	head2->next->next->next->next->next=new ListNode(39);
	//head1->next->next->next->next->next->next=new ListNode(37);
	printList(head2);

	ListNode* head3=new ListNode(0);
	head3->next=new ListNode(3);
	head3->next->next=new ListNode(4);
	head3->next->next->next=new ListNode(8);
	head3->next->next->next->next=new ListNode(10);
	head3->next->next->next->next->next=new ListNode(46);
	head3->next->next->next->next->next->next=new ListNode(67);
	printList(head3);

	vector<ListNode*> vec;
	vec.push_back(head1);
	vec.push_back(head2);
	vec.push_back(head3);
	ListNode* head=mergeKLists(vec);	
	printList(head);
	return 0;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
	if(lists.size()==0)
		return nullptr;
	ListNode* head=lists[0];
	for(int i=1; i<lists.size(); i++)
	{
		head=merge2Lists(head, lists[i]);
	}
	return head;
}

ListNode *merge2Lists(ListNode* l1, ListNode* l2)
{
	if(l1==nullptr)
		return l2;
	if(l2==nullptr)
		return l1;
	ListNode* sudoHead=new ListNode(-1);
	ListNode* head=sudoHead;
	while(l1!=nullptr && l2!=nullptr)
	{
		if(l1->val<l2->val)
		{
			head->next=l1;
			l1=l1->next;
			head=head->next;
		}
		else
		{
			head->next=l2;
			l2=l2->next;
			head=head->next;
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

