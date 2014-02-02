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
		if(b1.w<b2.w)
			return true;
		else if(b1.w==b2.w && b1.d<b2.d)
			return true;
		return false;
	}
};

int boxStacking(const vector<box>& vec);

int main()
{
	vector<box> vec;
	vec.push_back(box(4, 6, 7));
	vec.push_back(box(1, 2, 3));
	vec.push_back(box(4, 5, 6));
	vec.push_back(box(10, 12, 32));
	cout<<"The maximum possible height of the box stack is: "<<boxStacking(vec)<<endl;
	system("PAUSE");
	return 0;
}

int boxStacking(const vector<box>& vec)
{
	vector<box> boxVec(3*vec.size());
	int index=0;
	for(unsigned int i=0; i<vec.size(); i++)
	{
		boxVec[index++]=vec[i];
		boxVec[index++]=box(vec[i].w, max(vec[i].d, vec[i].h), min(vec[i].d, vec[i].h));
		boxVec[index++]=box(vec[i].d, max(vec[i].w, vec[i].h), min(vec[i].w, vec[i].h));
	}
	boxComp comp;
	vector<int> maxHeight(boxVec.size());
	sort(boxVec.begin(), boxVec.end(), comp);
	for(unsigned int i=0; i<boxVec.size(); i++)
		maxHeight[i]=boxVec[i].h;
	for(unsigned int i=0; i<boxVec.size(); i++)
	{
		for(unsigned int j=0; j<i; j++)
			if(boxVec[j].d<=boxVec[i].d && maxHeight[i]<maxHeight[j]+boxVec[i].h)
				maxHeight[i]=maxHeight[j]+boxVec[i].h;
	}
	cout<<endl;
	return *max_element(maxHeight.begin(), maxHeight.end());
}

