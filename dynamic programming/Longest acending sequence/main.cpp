#include<iostream>
#include<vector>
using namespace std;

int LAS(int *l, int n);
int main()
{
	int l[]={5,3,4,8,6,7};
	cout<<"The longest sub-acending sequnence is: "<<LAS(l, 6)<<endl;
	system("PAUSE");
	return 0;
}

int LAS(int *l, int n)
{
	vector<int> longest;
	longest.assign(n, 1);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<i; j++)
			if(l[j]<l[i] && longest[j]+1>longest[i])
				longest[i]=longest[j]+1;
	}
	return longest[n-1];
}
