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
	RandomListNode* head2=head1->next=new RandomListNode(2);
	RandomListNode* head3=head1->next->next=new RandomListNode(3);
	head1->random=head3;
	head3->random=head2;
	RandomListNode* head4=head1->next->next->next=new RandomListNode(4);
	RandomListNode* head5=head1->next->next->next->next=new RandomListNode(5);
	head1->random=head2;
	head2->random=head2;
	head4->random=head1;

	printList(head1);

	RandomListNode* newHead=copyRandomList(head1);
	printList(newHead);

	printList(head1);
	return 0;
}

RandomListNode *copyRandomList(RandomListNode *head) 
{
        if(head==nullptr)
            return nullptr;

        // step1: insert node
        RandomListNode* head1=head;
        while(head1!=nullptr)
        {
            RandomListNode* prev=head1;
            head1=head1->next;
            prev->next=new RandomListNode(prev->label);
            prev->next->next=head1;
        }

        // step2: copy random pointer
        RandomListNode* prev=head;
        while(prev!=nullptr)
        {
            head1=prev->next;
	    if(prev->random!=nullptr)  // Important check, or there may be prev->random=nullptr:--error!
            	head1->random=prev->random->next;
            prev=prev->next->next;
        }
                
	// step3: split
        RandomListNode* returnHead=head->next;
        prev=head;
        while(prev!=nullptr)
        {
            head1=prev->next;
            if(head1!=nullptr)
                prev->next=head1->next; //check
            prev=head1;
        }
        return returnHead;
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

