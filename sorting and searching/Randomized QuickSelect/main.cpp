// reference: http://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time/

#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

vector<int> kSmallest(vector<int>& vec, int k);
vector<int> kSmallest(vector<int>& vec, int k, int left, int right);
int randomPartition(vector<int>& vec, int left, int right);
int pivot(vector<int>& vec, int left, int right);

int main()
{
	vector<int> vec={5,24,7,40,0,19,31,32,33,30,13,39,15,29,12,28,4,2,38,22,37,23,27,21,41,9,36,18,1,17,26,11,25,16,6,10,8,34,14,3,20,35};	
	for(int i=0; i<vec.size(); i++)
		vec[i]+=50;

	int k;
	cout<<"input k: "<<endl;
	cin>>k;
	vector<int> result=kSmallest(vec, k);
	for(int i=0; i<k; i++)
		cout<<result[i]<<" ";
	cout<<endl;
	return 0;
}

vector<int> kSmallest(vector<int>& vec, int k)
{
	if(k<=0 || k>vec.size())
	{
		cerr<<"invalid k"<<endl;
		exit(1);
	}
	
	return kSmallest(vec, k, 0, vec.size()-1);
}

vector<int> kSmallest(vector<int>& vec, int k, int left, int right)
{
	int pos=randomPartition(vec, left, right);
	
	if(pos==k-1) // k-1 rather than k!
	{
		vector<int> result(k);
		for(int i=0; i<k; i++)
			result[i]=vec[i];
		return result;
	}
	else if(pos>k-1)
		return kSmallest(vec, k, left, pos-1);
	else
		return kSmallest(vec, k, pos+1, right);
}

// the return value is an index of the vector, that all elements before the index are smaller than
// it and all elements after are bigger
int randomPartition(vector<int>& vec, int left, int right)
{
	if(right-left<2) // only sort these less than 3 values
	{
		if(vec[left]>vec[right])
			swap(vec[left], vec[right]);
		return right;
	}

	int pivotV=pivot(vec, left, right);
	int i=left;
	int j=right-1;
	while(true)
	{
		while(vec[++i]<pivotV){} // must be < rather than <= here, or would go over the pivot 
		while(vec[--j]>pivotV){} // and cause error in the swap after the while loop !!!
		if(i<j)
			swap(vec[i], vec[j]);
		else
			break;
	}
	swap(vec[i], vec[right-1]);

	return i;
}

int pivot(vector<int>& vec, int left, int right)
{
	int n=right-left+1; 
	srand (time(NULL));

	int center=rand()%n+left;
	/* to avoid that center==right and center==left !!! Not efficient but for demo purpose */
	while(center==left || center==right) 
		center=rand()%n+left;

	if(vec[left]>vec[center])
		swap(vec[left], vec[center]);
	if(vec[center]>vec[right])
		swap(vec[center], vec[right]);
	if(vec[left]>vec[center])
		swap(vec[left], vec[center]);
	swap(vec[center], vec[right-1]);

	return vec[right-1];
}
