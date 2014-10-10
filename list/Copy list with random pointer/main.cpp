// reference: http://fisherlei.blogspot.com/search?q=Copy+List+with+Random+Pointer

#include<iostream>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
    	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

void printList(RandomListNode* head);
RandomListNode *copyRandomList(RandomListNode *head);

int main()
{
	RandomListNode* head1=new RandomListNode(1);
	//RandomListNode* head2=head1->next=new RandomListNode(2);
	//RandomListNode* head3=head1->next->next=new RandomListNode(3);
	//head1->random=head3;
	//head3->random=head2;
	//RandomListNode* head4=head1->next->next->next=new RandomListNode(4);
	//RandomListNode* head5=head1->next->next->next->next=new RandomListNode(5);
	//head1->random=head2;
	//head2->random=head2;
	//head4->random=head1;

	//head->next->next->next->next->next=new ListNode(6);
	//head->next->next->next->next->next->next=new ListNode(7);
	printList(head1);

	RandomListNode* newHead=copyRandomList(head1);
	printList(newHead);

	printList(head1);
	return 0;
}

RandomListNode *copyRandomList(RandomListNode *head)
{
	if(head==nullptr)
		return head;

	// step 1: insert nodes
	RandomListNode* cur=head;
	RandomListNode* temp;
	while(cur!=nullptr)
	{
		temp=cur->next;
		cur->next=new RandomListNode(cur->label);
		cur->next->next=temp;
		cur=temp;
	}

	// step 2: copy random pointer
	cur=head;
	while(cur!=nullptr)
	{
		temp=cur->next;
		if(cur->random!=nullptr)
			temp->random=cur->random->next;
		else
			temp->random=nullptr;
		cur=cur->next->next;
	}

	// step 3: decouple two list
	temp=head->next;
	cur=head;
	
        RandomListNode* result=temp;
	while(temp!=nullptr)
	{
		cur->next=temp->next;
		if(temp->next!=nullptr)
			temp->next=temp->next->next;
		cur=cur->next;
		temp=temp->next;
	}
	
	return result;
}

void printList(RandomListNode* head)
{
	while(head!=NULL)
	{
		if(head->random!=nullptr)
			cout<<"("<<head->label<<", "<<head->random->label<<")->";
		else
			cout<<"("<<head->label<<", nullptr)->";
		head=head->next;
	}
	cout<<endl;
}

