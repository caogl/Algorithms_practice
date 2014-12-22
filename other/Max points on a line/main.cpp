// http://fisherlei.blogspot.com/2013/12/leetcode-max-points-on-line-solution.html
#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

struct Point 
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

int maxPoints(vector<Point> &points);

int main()
{
	Point tmp(0, 0);
	vector<Point> points;
	points.push_back(tmp);
	tmp.y=1;
	points.push_back(tmp);
	tmp.x=1;
	points.push_back(tmp);
	tmp.x=0;
	points.push_back(tmp);
	cout<<maxPoints(points)<<endl;
	return 0;
}

int maxPoints(vector<Point> &points)
{
	if(points.size()==0)
		return 0; // must check here then initialize maxV=1!

	unordered_map<double, int> slope_map; //  the key is the slope, value is the number of points on the same line
	int maxV=1;
	for(int i=0; i<points.size(); i++)
	{
		int duplicate=0;
		slope_map.clear();
		for(int j=0; j<points.size(); j++)
		{
			if(points[i].x==points[j].x && points[i].y==points[j].y)
			{
				duplicate++;
				continue;
			}
			if(points[i].x==points[j].x)
			{
				slope_map[INT_MAX]++;
				continue;
			}
			double slope=double(points[j].y-points[i].y)/(points[j].x-points[i].x);
				slope_map[slope]++;
		}	
		maxV=max(maxV, duplicate); // This line is necessary because: if all points are duplicates, not even go into this loop, cannot update maxV!!!
		for(auto itr=slope_map.begin(); itr!=slope_map.end(); itr++)
		{
			maxV=max(maxV, itr->second+duplicate); 
		}
	}
	return maxV;
}
