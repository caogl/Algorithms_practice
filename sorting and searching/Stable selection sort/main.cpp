// See explanations at: http://forums.codeguru.com/showthread.php?362340-How-to-make-selection-sort-stable 
#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2);
void selectionSort(vector<pair<int, int> >& vec, int left, int right);
void stableSelectionSort(vector<pair<int, int> >& vec, int left, int right);

int main()
{
	vector<pair<int, int> > vec;
	vec.push_back(make_pair(5,1));
	vec.push_back(make_pair(3,1));
	vec.push_back(make_pair(5,2));
	vec.push_back(make_pair(2,1));
	for(int i=0; i<4; i++)
		cout<<vec[i].first<<" "<<vec[i].second<<endl;
	stableSelectionSort(vec, 0, 3);
	cout<<"After sort: "<<endl;
	for(int i=0; i<4; i++)
		cout<<vec[i].first<<" "<<vec[i].second<<endl;
	system("PAUSE");
	return 0;
}

void stableSelectionSort(vector<pair<int, int> >& vec, int left, int right)
{
	for(int i=left; i<=right; i++)
	{
		int min=i;
		for(int j=i; j<=right; j++)
		{
			if(compare(vec[j], vec[min]))
				min=j;
		}
		pair<int, int> tmp=vec[min];
		for(int k=min; k>i; k--)  // Very Very tricky part!!!
			vec[k]=vec[k-1];
		vec[i]=tmp;
		//for(int i=0; i<4; i++)
			//cout<<vec[i].first<<" "<<vec[i].second<<endl;
		//cout<<endl;
	}
}
bool compare(const pair<int, int>& p1, const pair<int, int>& p2)
{
	return(p1.first<p2.first);
}
void selectionSort(vector<pair<int, int> >& vec, int left, int right)
{
	for(int i=left; i<=right; i++)
	{
		int min=i;
		for(int j=i; j<=right; j++)
		{
			if(compare(vec[j], vec[min]))
				min=j;
		}
		swap(vec[i], vec[min]);
	}
}