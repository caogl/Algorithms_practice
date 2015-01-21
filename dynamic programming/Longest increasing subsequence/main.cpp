// Cracking the coding interview 11.7

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int LAS(int *l, int n);
int main()
{
	int l[]={5,9,3,4,8,6,7,10,1,2,9,11,12,14,13,-10,-9,-8,-7,-6,15,-5,-4,-3,-1,0,-11};
	cout<<"The longest sub-acending sequnence is: "<<LAS(l, 27)<<endl;
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
	// Notice unlike the sum coin problem, here we must return the largest element in the result vector
	// not the last one.
	return *max_element(longest.begin(), longest.end()); 
}
