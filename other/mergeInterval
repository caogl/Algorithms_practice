#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval 
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

struct compare
{
	bool operator()(const Interval& i1, const Interval& i2)
	{
		if(i1.start<i2.start)
			return true;
		else if(i1.end<i2.end)
			return true;
		else
			return false;
	}
};

vector<Interval> merge(vector<Interval> &intervals);
void print(vector<Interval>& intervals);

int main()
{
	vector<Interval> intervals;
	intervals.push_back(Interval(1,3));
	intervals.push_back(Interval(2,6));
	intervals.push_back(Interval(8,10));
	intervals.push_back(Interval(15,18));
	intervals.push_back(Interval(1,4));
	intervals.push_back(Interval(12,19));
	print(intervals);
	intervals=merge(intervals);
	print(intervals);

	system("pause");
	return 0;
}

void print(vector<Interval>& intervals)
{
	for(unsigned int i=0; i<intervals.size(); i++)
		cout<<"["<<intervals[i].start<<","<<intervals[i].end<<"]"<<" ";
	cout<<endl;
}

vector<Interval> merge(vector<Interval> &intervals) 
{
	compare comp;
	sort(intervals.begin(), intervals.end(), comp);
	vector<Interval> result;
	if(intervals.empty())
		return result;
	result.push_back(*intervals.begin());
	for(vector<Interval>::iterator itr=intervals.begin()+1; itr!=intervals.end(); itr++)
	{
		if(result.back().end>itr->start)
			result.back().end=max(itr->end, result.back().end);
		else
			result.push_back(*itr);
	}
	return result;
}
