// reference: http://www.hawstein.com/posts/3.2.html

#include<iostream>
#include<utility>
#include<vector>
#include<stack>
using namespace std;

/* This method takes too many extra space thus cannot pass leetcode test cases! 
 * eg: if we push 1,2...10000 to the stack, we store 1 10000 times, clearly redundent!
 *
class stackWithMin
{
public:
	void push(int data)
	{
		if(node.size()==0)
			node.push_back(make_pair(data, data));
		else if(data<node[node.size()-1].second)
			node.push_back(make_pair(data, data));
		else
			node.push_back(make_pair(data, node[node.size()-1].second));
	}
	void pop()
	{
		if(node.size()==0)
		{
			cerr<<"cannot pop from an empty stack"<<endl;
			exit(1);
		}
		node.pop_back();
	}
	int top(){return node[node.size()-1].first;}
	int min(){return node[node.size()-1].second;}
private:
	vector<pair<int, int> > node; // the first element in the pair is the value while the second is the min for this node
};
*/

class MinStack 
{
public:
    void push(int x) 
    {
        if(Stack.size()==0 || Min.top()>=x) // first check condition important !!!
            Min.push(x);
	Stack.push(x);
    }
    void pop()
    {
        if(Stack.size()==0)
            exit(1);
        if(Stack.top()==Min.top())
        {
            Min.pop();
        }
        Stack.pop();
    }
    int top() 
    {
        return Stack.top();
    }
    int getMin() 
    {
        return Min.top();
    }

private:
    stack<int> Stack;
    stack<int> Min;
};

int main()
{
	MinStack s;
	for(int i=0; i<10; i++)
	{
		s.push(i);
	}
	s.push(-1);
	s.push(-2);
	s.push(11);
	cout<<"The min element is: "<<s.getMin()<<endl;
	cout<<"The top element is: "<<s.top()<<endl;
	s.pop();
	cout<<"The min element is: "<<s.getMin()<<endl;
	cout<<"The top element is: "<<s.top()<<endl;
	return 0;
}


/* here use vector will exceed memory limit, because it will actually preallocate more memory than size 
class MinStack 
{
public:
    void push(int x) 
    {
        if(Stack.size()==0 || Min[Min.size()-1]>=x)
            Min.push_back(x);
	Stack.push_back(x);
    }
    void pop()
    {
        if(Stack.size()==0)
            exit(1);
        if(Min[Min.size()-1]==Stack[Stack.size()-1])
        {
            Min.pop_back();
        }
        Stack.pop_back();
    }
    int top() 
    {
        return Stack[Stack.size()-1];
    }
    int getMin() 
    {
        return Min[Min.size()-1];
    }

private:
    vector<int> Stack;
    vector<int> Min;
};

int main()
{
	MinStack s;
	for(int i=1; i<10000; i++)
		s.push(i);
	cout<<"The min element is: "<<s.getMin()<<endl;
	cout<<s.Min.size()<<endl;
	return 0;
}
*/
