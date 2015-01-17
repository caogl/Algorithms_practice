// google interview question: http://www.careercup.com/question?id=16759664
/*
You have k lists of sorted integers. Find the smallest range that includes at least one number from each of the k lists.

For example,
List 1: [4, 10, 15, 24, 26]
List 2: [0, 9, 12, 20]
List 3: [5, 18, 22, 30]

The smallest range here would be [20, 24] as it contains 24 from list 1, 20 from list 2, and 22 from list 3.

Solution:

There are k lists of sorted integers. Make a min heap of size k containing 1 element from each list. Keep track of min and max element and calculate the range.
In min heap, minimum element is at top. Delete the minimum element and another element instead of that from the same list to which minimum element belong. Repeat the process till any one of the k list gets empty.
Keep track of minimum range.

For eg.
List 1: [4, 10, 15, 24, 26]
List 2: [0, 9, 12, 20]
List 3: [5, 18, 22, 30]

Min heap of size 3. containing 1 element of each list
Heap [0, 4, 5]
Range - 6

Remove 0 and add 9
Heap [4, 9, 5]
Range - 6

Remove 4 and add 10
Heap [5, 9, 10]
Range - 6

and so on....

Finally you will yield the result.
 */

#include<queue>
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Definition for singly-linked list.
struct ListNode 
{
	int val;
    	ListNode *next;
    	ListNode(int x) : val(x), next(NULL) {}
};

struct cmp
{
	bool operator()(const ListNode* l1, const ListNode* l2)
	{
		return l1->val>l2->val;
	}
};

ListNode* toList(vector<int> vec);
int smallestRange(vector<ListNode*> vec);

int main()
{
	vector<int> vec1={4,10,15,24,26};
	vector<int> vec2={0,9,12,20};
	vector<int> vec3={5,18,22,30};
	vector<ListNode*> vec={toList(vec1), toList(vec2), toList(vec3)};
	cout<<smallestRange(vec)<<endl;
	return 0;
}

ListNode* toList(vector<int> vec)
{
	ListNode* sudoHead=new ListNode(-1);	
	ListNode* head=sudoHead;

	for(int i=0; i<vec.size(); i++)
	{
		head->next=new ListNode(vec[i]);
		head=head->next;
	}
	head=sudoHead->next;
	delete sudoHead;
	return head;
}

int smallestRange(vector<ListNode*> vec)
{
	priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
	int maxV=INT_MIN;
	int result=INT_MAX;
	for(int i=0; i<vec.size(); i++)
	{
		maxV=max(maxV, vec[i]->val);
		pq.push(vec[i]);
	}
	while(true)
	{
		result=min(result, maxV-pq.top()->val);
		ListNode* tmp=pq.top();
		pq.pop();
		if(tmp->next==nullptr)	break;
		pq.push(tmp->next);
		maxV=max(maxV, tmp->next->val);
	}
	return result;
}
