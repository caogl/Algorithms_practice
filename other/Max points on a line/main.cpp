// reference: http://fisherlei.blogspot.com/2013/12/leetcode-max-points-on-line-solution.html
/*
   任意一条直线都可以表述为
   y = ax + b
   假设，有两个点(x1,y1), (x2,y2)，如果他们都在这条直线上则有
   y1 = kx1 +b
   y2 = kx2 +b
   由此可以得到关系，k = (y2-y1)/(x2-x1)。即如果点c和点a的斜率为k, 而点b和点a的斜率也为k，那么由传递性，可以知道点c和点b也在一条线上。解法就从这里来
   取定一个点(xk,yk), 遍历所有节点(xi, yi), 然后统计斜率相同的点数，并求取最大值即可
   
   若干注意事项：
1. 垂直曲线， 即斜率无穷大
2. 重复节点。
*/
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
