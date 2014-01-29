#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class queue
{
public:
	void push_back(T data)
	{
		move(out, in);
		in.push(data);
	}
	void pop_front()
	{
		move(in, out);
		out.pop();
	}
	T front()
	{
		move(in, out);
		return out.top();
	}
	T back()
	{
		move(out, in);
		return in.top();
	}
	void move(stack<T>& stack1, stack<T>& stack2)
	{
		while(!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
private:
	stack<T> in, out;
};

int main()
{
	queue<int> q;
	for(int i=0; i<10; i++)
	{
		q.push_back(i);
	}
	cout<<"the front element in the queue is: "<<q.front()<<endl;
	cout<<"the back element in the queue is: "<<q.back()<<endl;
	q.pop_front();
	cout<<"the front element in the queue is: "<<q.front()<<endl;
	cout<<"the back element in the queue is: "<<q.back()<<endl;
	system("PAUSE");
	return 0;
}