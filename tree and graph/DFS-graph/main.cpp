#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool DFS(const vector<vector<int> > graph, int p1, int p2);
int main()
{
	vector<vector<int> > graph(6);
	graph[0].push_back(1);
	graph[0].push_back(2);
	graph[1].push_back(0);
	graph[1].push_back(3);
	graph[2].push_back(3);
	graph[3].push_back(4);
	graph[4].push_back(2);
	graph[4].push_back(3);
	graph[4].push_back(5);
	graph[5].push_back(0);
	graph[5].push_back(2);
	if(DFS(graph, 0, 5))
		cout<<"There is path between point 0 and 5";
	else
		cout<<"No path between 0 and 5";
	cout<<endl;
	graph[4].pop_back();
	graph[5].push_back(4);
	if(DFS(graph, 0, 5))
		cout<<"There is path between point 0 and 5";
	else
		cout<<"No path between 0 and 5";
	system("PAUSE");
	return 0;
}

bool DFS(const vector<vector<int> > graph, int p1, int p2)
{
	vector<vector<int> > test=graph;
	stack<int> s;
	s.push(p1);
	int tmp;
	while(!s.empty()) // Notice here in DFS the top element should be removed first!!
	{
		tmp=s.top();
		s.pop(); //Must pop here, rather than before the end bracket of the first while loop!!!
		//cout<<"top elemnet in stack: "<<s.top()<<" ";
		while(!test[tmp].empty())
		{
			//cout<<"the back element: "<<test[s.top()].back()<<" ";
			//cout<<"size: "<<test[s.top()].size()<<" ";
			if(test[tmp].back()==p2)
				return true;
			s.push(test[tmp].back());
			test[tmp].pop_back();
			//cout<<"size: "<<s.size()<<" ";
		}
	}
	return false;
}

