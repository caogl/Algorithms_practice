// idea: while recursively copy the graph node, we need to keep track of whether the neight node of every vertex is created
//       before. If not, create one and add the edge. If yes, just add the edge 

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

//Definition for the graph
struct UndirectedGraphNode 
{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*>& visited);
void printGraph(UndirectedGraphNode* node);
void printGraph(UndirectedGraphNode* node, unordered_set<int>& visited);

int main()
{
	UndirectedGraphNode* head0=new UndirectedGraphNode(0);
	UndirectedGraphNode* head1=new UndirectedGraphNode(1);
	UndirectedGraphNode* head2=new UndirectedGraphNode(2);
	head0->neighbors.push_back(head1);	
	head0->neighbors.push_back(head2);
	//head1->neighbors.push_back(head0);
	head1->neighbors.push_back(head2);
	//head2->neighbors.push_back(head0);
	//head2->neighbors.push_back(head1);
	head2->neighbors.push_back(head2);
	printGraph(head0);

	cout<<"Here is the copied graph: "<<endl;
	UndirectedGraphNode* head3=cloneGraph(head0);
	printGraph(head3);

	return 0;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
	unordered_map<int, UndirectedGraphNode*> visited; // must use int as the key to track!!!
	return cloneGraph(node, visited);
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*>& visited)
{
	if(node==nullptr)
		return node;
	UndirectedGraphNode* head=new UndirectedGraphNode(node->label);
	visited[node->label]=head;
	for(int i=0; i<node->neighbors.size(); i++)
	{
		if(visited.find(node->neighbors[i]->label)==visited.end())
			head->neighbors.push_back(cloneGraph(node->neighbors[i], visited));
		else
			head->neighbors.push_back(visited[node->neighbors[i]->label]);
	}
	return head;
}

void printGraph(UndirectedGraphNode* node)
{
	unordered_set<int> visited;
	printGraph(node, visited);
}

void printGraph(UndirectedGraphNode* node, unordered_set<int>& visited)
{
	if(node==nullptr)
		return;
	cout<<node->label<<"	";
	visited.insert(node->label);
	for(int i=0; i<node->neighbors.size(); i++)
	{
		cout<<node->neighbors[i]->label<<" ";
	}
	cout<<endl;

	for(int i=0; i<node->neighbors.size(); i++)
	{
		if(visited.find(node->neighbors[i]->label)==visited.end())
			printGraph(node->neighbors[i]);
	}
}
