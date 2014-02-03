#include<iostream>
#include<set>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

struct box
{
	int h;
	int d;
	int w;
	box(){}
	box(int h1, int w1, int d1)
	{
		h=h1;
		d=d1;
		w=w1;
	}
};

struct boxComp
{
	bool operator()(const box& b1, const box& b2)
	{
		if(b1.w>b2.w)
			return true;
		else if(b1.w==b2.w && b1.d>b2.d)
			return true;
		return false;
	}
};

int boxStacking(vector<box>& vec);

int main()
{
	vector<box> vec;
	vec.push_back(box(4, 6, 7));
	vec.push_back(box(1, 2, 3));
	vec.push_back(box(3, 9, 7));
	vec.push_back(box(4, 7, 6));
	vec.push_back(box(3, 3, 8));
	vec.push_back(box(10, 12, 32));
	cout<<"The maximum possible height of the box stack is: "<<boxStacking(vec)<<endl;
	system("PAUSE");
	return 0;
}

int boxStacking(vector<box>& vec)
{
	boxComp comp;
	vector<int> maxHeight(vec.size());
	sort(vec.begin(), vec.end(), comp);
	for(unsigned int i=0; i<vec.size(); i++)
		maxHeight[i]=vec[i].h;
	for(unsigned int i=0; i<vec.size(); i++)
	{
		for(unsigned int j=0; j<i; j++)
			if(vec[j].d>=vec[i].d && maxHeight[i]<maxHeight[j]+vec[i].h)
				maxHeight[i]=maxHeight[j]+vec[i].h;
	}
	return *max_element(maxHeight.begin(), maxHeight.end());
}
