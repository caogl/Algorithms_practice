#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
 * In order to merge k sort lists, there are many solutions.Time complexity analysed based on a simplified situation that that are m lists and each of them contains n elements.
       
   (1)each time merge two lists, and then merge the result list with another one until no list. If so the time complexity is O(m*m*n). 
      However if use binary merge that first we merge all the original lists into n/2 lists and then merge these n/2 lists into n/4 and so forth until only one list left. This could be more efficient.
   (2)One straightforward solution is just store all the elements in a vector, and then sort them. It's simple but works with O((n*m)*log(n*m)), but as for memory, except for the return list, there are O(m*n) extra memory.
   (3)A good solution in theoretical perspective is that we can maintain a priority queue with m elements. Each time we pop up the smallest element in the priority queue in O(1) time and then push in the element,
      which is the next node of the popped one in O(log(m)) time. The overall time complexity is O((n*m)*log(m)), and it only uses O(m) extra memory.
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

struct cmp
{
	bool operator()(const ListNode*a, const ListNode*b)
	{
		return a->val>b->val; /*****!!!!! notice > ! *****/
	}
};

void printList(ListNode* head);
ListNode *mergeKLists(vector<ListNode *> &lists);
//ListNode *merge2Lists(ListNode* l1, ListNode* l2);

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

/* ----------------solution (3)------------------ */
ListNode *mergeKLists(vector<ListNode *> &lists)
{
	ListNode* sudoHead=new ListNode(-1);
	ListNode* head=sudoHead;
	priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
	for(int i=0; i<lists.size(); i++)
	{
		if(lists[i]!=nullptr)
			pq.push(lists[i]);
	}
	
	while(!pq.empty())
	{
		head->next=pq.top();
		pq.pop();
		head=head->next;
		if(head->next!=nullptr)
			pq.push(head->next);
	}
	head=sudoHead->next;
	delete sudoHead;
	return head;
}

/* ----------------solution (1)------------------ */
/*
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
*/

void printList(ListNode* head)
{
	while(head!=NULL)
	{
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}

