/*
Given a link list with right pointers and each element of the list has a down link contains another link list with down pointers as:

 5 -> 7 -> 9 -> 18
 |    |    |    |
10    6    14   20
 |    |    |    |
11    8    19   22
 |    |         |
12    13        24
 |    
15

each right and down list are sorted.
Write a function flatten() which flattens this link list to a single link list with all the elements in sorted order as:
5->6->7->8->9->10->11->12->13->14->15->18->19->20->22->24
*/

#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode *down;
	ListNode(int x)
	{
		val=x;
		next=nullptr;
		down=nullptr;
	}
};

ListNode* merge(ListNode* node1, ListNode* node2);
ListNode* flatten(ListNode* head);

int main()
{
	ListNode* head=new ListNode(5);
	ListNode* start=head;
	head->down=new ListNode(10);
	head->down->down=new ListNode(11);
	head->down->down->down=new ListNode(12);
	head->down->down->down->down=new ListNode(15);
	head->next=new ListNode(7);
	head=head->next;
	head->down=new ListNode(6);
	head->down->down=new ListNode(8);
	head->down->down->down=new ListNode(13);
	head->next=new ListNode(9);
	head=head->next;
	head->down=new ListNode(14);
	head->down->down=new ListNode(19);
	head->next=new ListNode(18);
	head=head->next;
	head->down=new ListNode(20);
	head->down->down=new ListNode(22);
	head->down->down->down=new ListNode(24);

	head=flatten(start);
	// print result
	while(head!=nullptr)
	{
		cout<<head->val<<" ";
		head=head->down;
	}
	return 0;
}

ListNode* merge(ListNode* node1, ListNode* node2)
{
	ListNode* sudoHead=new ListNode(-1);
	ListNode* current=sudoHead;
	while(node1!=nullptr && node2!=nullptr)
	{
		if(node1->val<node2->val)
		{
			current->down=node1;
			node1=node1->down;
			current=current->down;
		}
		else
		{
			current->down=node2;
			node2=node2->down;
			current=current->down;
		}
	}
	if(node1!=nullptr)
		current->down=node1;
	if(node2!=nullptr)
		current->down=node2;
	
	ListNode* head=sudoHead->down;
	delete sudoHead;
	return head;
}

ListNode* flatten(ListNode* head)
{
	if(head==nullptr || head->next==nullptr)
		return head;
	
	return merge(head, flatten(head->next));
}

