#include<iostream>
#include<utility>
#include<vector>
using namespace std;

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

int main()
{
	stackWithMin s;
	for(int i=0; i<10; i++)
	{
		s.push(i);
	}
	s.push(-1);
	s.push(-2);
	s.push(11);
	cout<<"The min element is: "<<s.min()<<endl;
	cout<<"The top element is: "<<s.top()<<endl;
	s.pop();
	cout<<"The min element is: "<<s.min()<<endl;
	cout<<"The top element is: "<<s.top()<<endl;
	system("PAUSE");
	return 0;
}