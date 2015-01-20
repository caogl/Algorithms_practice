// cracking the coding interview/google interview
// keep two priority_queues and ensure that the difference in size is smaller than 2

#include<iostream>
#include<queue>
using namespace std;

class Median
{
public: 
	int getMedian()
	{
		if(maxHeap.size()>minHeap.size())	return maxHeap.top();
		else if(maxHeap.size()<minHeap.size())	return minHeap.top();
		else	return (maxHeap.top()+minHeap.top())/2;
	}
	void insert(int x)
	{
		// deal with empty heap corner cases-->
		// we only need to ensure that top elem in minHeap is greater than the top elem in maxHeap 		
		if(maxHeap.empty())
			minHeap.push(x);
		else if(minHeap.empty())
			maxHeap.push(x);
		else
		{
			if(x>minHeap.top())	minHeap.push(x);
			else	maxHeap.push(x);
		}
		
		// adjust the size
		// must compare first then get the difference, or the unsigned int operation is always wrong
		if(maxHeap.size()>minHeap.size() && maxHeap.size()-minHeap.size()>1) //
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		else if(minHeap.size()>maxHeap.size() && minHeap.size()-maxHeap.size()>1)
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}
private:
	priority_queue<int, vector<int>, less<int> > maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
};

int main()
{
	Median median;
	for(int i=1; i<=10; i++)
	{
		median.insert(i);
		cout<<median.getMedian()<<" ";
	}
	for(int i=20; i>=10; i--)
	{
		median.insert(i);
		cout<<median.getMedian()<<" ";
	}
	for(int i=120; i>=100; i--)
	{
		median.insert(i);
		cout<<median.getMedian()<<" ";
	}

	return 0;
}
