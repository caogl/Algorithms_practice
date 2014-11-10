/* online interview from pure storage */ 

#include<iostream>
using namespace std;

class LinkedListNode
{
public:
	int val;
	LinkedListNode* next;
	LinkedListNode(int val1)
	{
		val=val1;
		next=nullptr;
	}
};

/* The highlight is the function parameter **list! */
void removeAll(int val, LinkedListNode **list) 
{
    LinkedListNode* sudoHead=new LinkedListNode(-1);
    sudoHead->next=*list;
    LinkedListNode* head=*list;
    LinkedListNode* pre=sudoHead;
    while(head!=nullptr)
    {
        if(head->val==val)
        {
            pre->next=head->next;
            LinkedListNode* tmp=head;
            head=head->next;
            delete tmp;
        }
        else
        {
            pre=pre->next;
            head=head->next;
        }
    }
    /* must do it like this, because we can only change what list points to */
    *(list)=sudoHead->next;
    // list=&(sudoHead->next) ---->will not change anything, so when delete first node, there is an error!
    delete sudoHead;
}

int main()
{
	LinkedListNode* head=new LinkedListNode(1);
	LinkedListNode* head1=head;
	head->next=new LinkedListNode(2);
	head->next->next=new LinkedListNode(3);
	head->next->next->next=new LinkedListNode(4);
	removeAll(1, &head1);
	while(head1!=nullptr)
	{
		cout<<head1->val<<" ";
		head1=head1->next;
	}
	return 0;
}
