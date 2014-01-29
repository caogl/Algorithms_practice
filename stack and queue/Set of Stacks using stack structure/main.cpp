#include<iostream>
using namespace std;

const int stackSize=10;
const int stackNum=8;

class stack
{
public:
	stack(int size=stackSize)
	{
		buf=new int[stackSize];
		cur=-1;
		capacity=stackSize;
	}
	~stack()
	{
		delete[] buf;
	}
	void push(int data)
	{
		//cout<<cur<<" ";
		cur++;
		buf[cur]=data;
	}
	void pop()
	{
		cur--;
		//cout<<"poped: "<<cur<<" ";
	}
	int top()
	{
		return buf[cur];
	}
	bool full()
	{
		return (cur==capacity-1);
	}
	bool empty()
	{
		return (cur==-1);
	}
private:
	int *buf;
	int capacity;
	int cur;
};

class setOfStack
{
public:
	setOfStack(int size=stackNum)
	{
		setStack=new stack[size];
		curStack=-1; //Setting this member variable to -1 is very important! Notice the check of this condition when pushing element.
		numOfStack=size;
	}
	~setOfStack()
	{
		delete[] setStack;
	}
	void push(int data)
	{
		//cout<<"current oush stack is: "<<curStack<<" ";
		if(setStack[curStack].full() || curStack==-1)
		{
			curStack++;
		}
		setStack[curStack].push(data);
	}
	void pop()
	{
		if(setStack[curStack].empty())
			curStack--;
		setStack[curStack].pop();
		//cout<<"current pop stack is: "<<curStack<<" ";
	}
	int top()
	{
		if(setStack[curStack].empty())
			curStack--;
		return setStack[curStack].top();
	}
	void popAt(int idx)
	{
		if(setStack[idx].empty())
			idx--;
		setStack[idx].pop();
	}
	bool empty()
	{
		while(curStack!=-1 && setStack[curStack].empty())
			curStack--;
		return curStack==-1;
	}
private:
	stack *setStack;
	int numOfStack;
	int curStack;
};

int main()
{
	setOfStack ss1;
	for(int i=0; i<stackSize*3; i++)
		ss1.push(i);
	while(!ss1.empty())
	{
		cout<<ss1.top()<<" ";
		ss1.pop();
	}
	cout<<endl;
	for(int i=0; i<stackSize*3; i++)
	{
		//cout<<"haha"<<" ";
		ss1.push(i);
	}
	for(int i=0; i<stackSize; i++)
	{
		ss1.popAt(0);
		ss1.popAt(2);
	}
	while(!ss1.empty())
	{
		cout<<ss1.top()<<" ";
		ss1.pop();
	}
	system("PAUSE");
	return 0;
}

