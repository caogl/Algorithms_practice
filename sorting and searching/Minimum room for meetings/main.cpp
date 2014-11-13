/* dropbox interview question: 

You have a number of meetings (with their start and end times). You need to schedule them using the minimum number of rooms. 
Return the minimum room number.

First we need to realize that randomly schedule meetings to available rooms won¿t give you an optimal solution. 
For example, suppose there are 4 meetings, the (start, end) time are (1, 3), (1, 5), (6, 7), (4, 7). 
When (1, 3) comes, assign to room A, then (1, 5) comes, assign to room B, then (6, 7) comes, assign to room A as it is available, then (4, 7) comes, both room A and B are not available so we have to assign a new room C for it. 
However, a better solution is two rooms, room A for meeting (1, 3) (4, 7) and room B for meeting (1, 5) (6, 7).

However, the optimal solution solution is not far from it. If we first sort all the meeting by the start time, then we could just assign them one by one and to the first available room.

The reason is simple, when considering a meeting from s[i] to e[i], as there is no unschedule meeting before s[i], by putting the (s[i], e[i]) meeting in any available room (if there is one) would leads to the same results.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct cmp
{
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
	{
		return (p1.first<p2.first);
	}
};

int minRoom(vector<pair<int, int> >& meetings);

int main()
{
	vector<pair<int, int> > meetings={make_pair(1, 3), make_pair(1, 5), make_pair(6, 7), make_pair(4, 7)};
	cout<<minRoom(meetings)<<" rooms needs to be assigned!"<<endl;
	
	return 0;
}

/* sort using the beging time and plug in/create new rooms using the end time */ 
int minRoom(vector<pair<int, int> >& meetings)
{
	cmp cmp1;
	sort(meetings.begin(), meetings.end(), cmp1);
	vector<int> result;
	if(meetings.size()==0)
		return 0;
	result.push_back(meetings[0].second);
	for(int i=1; i<meetings.size(); i++)
	{
		bool newRoom=true;
		for(int j=0; j<result.size(); j++)
		{
			if(result[j]<meetings[i].first)
			{
				result[j]=meetings[i].second;
				newRoom=false;
				break;
			}
		}
		if(newRoom==true)
			result.push_back(meetings[i].second);
	}
	return result.size();
}
