#include<iostream>
#include<unordered_set>
using namespace std;

struct node
{
	int data;
	node* next;
};
node* init(int a[], int n, int m);
node* checkCircle1(node *head);
bool checkCircle2(node *head); // using constant extra space, leetcode, no test in main() function
void printList(node* head);

int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9};
	node *testHead=init(a, 10, 6);
	//printList(testHead);
	node *circleNode=checkCircle1(testHead);
	cout<<"the circle point is: "<<circleNode->data<<endl;
	cout<<endl;
	system("PAUSE");
	return 0;
}

node* init(int a[], int n, int m)
{
	node *head, *p, *q;
	for(int i=0; i<n; i++)
	{
		node *nd=new node();
		nd->data=a[i];
		if(i==0)
		{
			head=nd;
			p=nd;
		}
		else
		{
			p->next=nd;
			p=nd;
		}
		if(i==m)
			q=nd;
	}
	p->next=q;
	return head;
}

bool checkCircle2(node *head)
{
        if(head==nullptr)
            return false;
        ListNode *head1=head->next;
        while(head!=nullptr && head1!=nullptr)
        {
            if(head==head1)
                return true;
            head=head->next;
            if(head1->next!=nullptr)
                head1=head1->next->next;
            else
                return false;
        }
        return false;
}

node* checkCircle1(node *head)
{
	unordered_set<node*> hashSet;
	while(head!=NULL)
	{
		if(hashSet.find(head)!=hashSet.end())
		{
			return head;
		}
		else
			hashSet.insert(head);
		head=head->next;
	}
	return NULL;
}

void printList(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}
