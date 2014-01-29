#include<iostream>
using namespace std;

template<typename object>
struct node
{
	node(){next=NULL;}
	node(object data1):data(data1){}
	node(object data1, node *node1):data(data1),next(node1){}
	object data;
	node* next;
};

template<typename object>
class stack
{
public:
	stack(){head=NULL;} // Notice here that head must be SET TO NULL! Should not use the default constructor.
	~stack()
	{
		while(head)
			pop();
	}
	void push(object data1)
	{
		node<object> *ptr=new node<object>(data1, head);
		head=ptr;
	}
	void pop()
	{
		node<object> *ptr=head;
		if(head!=NULL)
		{
			head=head->next;
			delete ptr;
		}
		else
		{
			cerr<<"cannnot pop from an empty stack"<<endl;
			exit(1);
		}
	}
	object top(){return head->data;}
private:
	node<object> *head;
};

template<typename object>
class queue
{
public:
	queue(){front=NULL;	back=NULL;}
	~queue()
	{
		while(front!=NULL)
			pop_front();
	}
	void push_back(object data1)
	{
		node<object> *ptr=new node<object>(data1, NULL); //Notice here must cannot use the constructor "node<object> *ptr=new node<object>(data1);"!!!!
		if(back==NULL)
		{
			front=ptr;
			back=ptr;
		}
		else
		{
			back->next=ptr;
			back=back->next;
		}
	}
	void pop_front()
	{
		if(front==NULL) 
		{
			cerr<<"cannot pop from an empty queue"<<endl;
			exit(1);
		}
		node<object> *ptr=front;
		if(front->next!=NULL)  // Notice the check and set NULL must be implemented here, or there is mistake in checking whether the front node is NULL!
			front=front->next;
		else
		{
			front=NULL;
			back=NULL;
		}
		delete ptr; //Notice here after popping all the front elements we must set the front node to NULL!!!!!!
	}
	object front_elem(){return front->data;}
	object back_elem(){return back->data;}
private:
	node<object> *front;
	node<object> *back;
};
int main()
{
	stack<int> stack1;
	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	stack1.push(4);
	cout<<"the top element of the stack is:"<<stack1.top()<<endl;
	stack1.pop();
	stack1.pop();
	cout<<"the top element of the stack is:"<<stack1.top()<<endl;
	queue<int> queue1;
	queue1.push_back(1);
	queue1.push_back(2);
	queue1.push_back(3);
	queue1.push_back(4);
	cout<<"the front element in the queue is: "<<queue1.front_elem()<<endl;
	cout<<"the back element in the queue is: "<<queue1.back_elem()<<endl;
	queue1.pop_front();
	cout<<"the front element in the queue is: "<<queue1.front_elem()<<endl;
	system("PAUSE");
	return 0;
}



