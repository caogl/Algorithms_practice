#include<iostream>
#include<stack>
using namespace std;

stack<int> sortStack(stack<int>& s1);
void printStack(stack<int>& s);

int main()
{
	stack<int> test;
	test.push(5);
	test.push(6);
	test.push(4);
	test.push(3);
	test.push(8);
	test.push(7);
	stack<int> test1=sortStack(test);
	printStack(test1);
	system("PAUSE");
	return 0;
}

stack<int> sortStack(stack<int>& s1)
{
	stack<int> s2;
	while(!s1.empty())
	{
		int data=s1.top();
		s1.pop(); // notice that this pop fuction must be implemented here
		if(s2.empty())
		{
			s2.push(data);
		}
		else
		{
			while(!s2.empty() && data>s2.top())
			{
				s1.push(s2.top());
				s2.pop();
			}
			s2.push(data);
		}
	}
	return s2;
}

void printStack(stack<int>& s)
{
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}


