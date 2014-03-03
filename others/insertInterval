#include<iostream>
#include<vector>
using namespace std;

struct Interval 
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval);
void print(vector<Interval>& intervals);

int main()
{
	vector<Interval> intervals;
	intervals.push_back(Interval(1,3));
	intervals.push_back(Interval(6,9));
	print(intervals);
	Interval newInterval1(2,5);
	intervals=insert(intervals, newInterval1);
	print(intervals);
	intervals.clear();

	intervals.push_back(Interval(1,2));
	intervals.push_back(Interval(3,5));
	intervals.push_back(Interval(6,7));
	intervals.push_back(Interval(8,10));
	intervals.push_back(Interval(12,16));
	print(intervals);
	Interval newInterval2(4,9);
	intervals=insert(intervals, newInterval2);
	print(intervals);

	intervals.clear();
	intervals.push_back(Interval(0,1));
	intervals.push_back(Interval(4,5));
	intervals.push_back(Interval(6,7));
	intervals.push_back(Interval(8,10));
	intervals.push_back(Interval(12,16));
	print(intervals);
	Interval newInterval3(2,3);
	intervals=insert(intervals, newInterval3);

	intervals.clear();
	Interval newInterval4(2,3);
	intervals=insert(intervals, newInterval4);

	system("pause");
	return 0;
}

void print(vector<Interval>& intervals)
{
	for(unsigned int i=0; i<intervals.size(); i++)
		cout<<"["<<intervals[i].start<<","<<intervals[i].end<<"]"<<" ";
	cout<<endl;
}
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
	vector<Interval> result;
	if(intervals.empty())
	{
		result.push_back(newInterval);
		return result;
	}
	vector<Interval>::iterator itr;
	for(itr=intervals.begin(); itr!=intervals.end(); itr++)
	{
		if(itr->start>newInterval.start)
		{
			intervals.insert(itr, newInterval);
			break;
		}
	}
	if(itr==intervals.end())
		intervals.push_back(newInterval);
	result.push_back(*intervals.begin());
	for(itr=intervals.begin()+1; itr!=intervals.end(); itr++)
	{
		if(result.back().end>=itr->start)
			result.back().end=max(result.back().end, itr->end);
		else
			result.push_back(*itr);
	}
	return result;
}
