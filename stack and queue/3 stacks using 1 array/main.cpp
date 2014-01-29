#include<iostream>
using namespace std;

class stack3
{
public:
	stack3(int sizeOfStack)
	{
		buf=new int[sizeOfStack*3];
		ptop[0]=ptop[1]=ptop[2]=-1;
		size=sizeOfStack;
	}
	~stack3()
	{
		delete[] buf;
	}
	void push(int stackNum, int val)
	{
		ptop[stackNum]++;
		buf[stackNum*size+ptop[stackNum]]=val;
	}
	void pop(int stackNum)
	{
		ptop[stackNum]--;
	}
	int top(int stackNum)
	{
		return buf[stackNum*size+ptop[stackNum]];
	}
private:
	int *buf; // the array used to hold the three stacks
	int ptop[3]; // the position of the top element in the three stacks
	int size; // the size of each stack
};

int main()
{
	stack3 s(100);
	for(int i=0; i<10; i++)
	{
		s.push(0, i);
		s.push(1, 10*i);
		s.push(2, 100*i);
	}
	cout<<s.top(0)<<" "<<s.top(1)<<" "<<s.top(2)<<endl;
	s.pop(0);
	s.pop(1);
	s.pop(2);
	s.pop(0);
	cout<<s.top(0)<<" "<<s.top(1)<<" "<<s.top(2)<<endl;
	system("PAUSE");
	return 0;
}
