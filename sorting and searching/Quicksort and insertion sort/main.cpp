#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void insertionSort(vector<int>& vec, int left, int right);
vector<int> convert(int *a, int size);
void output(const vector<int>& vec);
void quickSort(vector<int>& vec);
void quickSort(vector<int>& vec, int left, int right);
int pickPivot(vector<int>& vec, int left, int right);

int main()
{
	int a[]={5,24,7,40,0,19,31,32,33,30,13,39,15,29,12,28,4,2,38,22,37,23,27,21,41,9,36,18,1,17,26,11,25,16,6,10,8,34,14,20,35};
	vector<int> vec=convert(a, 41);
	insertionSort(vec, 0, vec.size()-1);
	output(vec);
	cout<<endl;
	vec=convert(a, 41);
	//output(vec);
	quickSort(vec);
	output(vec);
	system("PAUSE");
    return 0;
}

void quickSort(vector<int>& vec)
{
	quickSort(vec, 0, vec.size()-1);
}
void quickSort(vector<int>& vec, int left, int right)
{
	if(right-left>=10)
	{
		int pivot=pickPivot(vec, left, right);
		int i=left, j=right-1;
		while(true)
		{
			while(vec[++i]<pivot){}
			while(vec[--j]>pivot){}
			if(i<j)
				swap(vec[i], vec[j]);
			else
				break;
		}
		swap(vec[i], vec[right-1]);
		quickSort(vec, left, i-1);
		quickSort(vec, i+1, right);
	}
	else
		insertionSort(vec, left, right);
}
int pickPivot(vector<int>& vec, int left, int right)
{
	int center=(left+right)/2;
	if(vec[center]<vec[left])
		swap(vec[left], vec[center]);
	if(vec[left]<vec[right])
		swap(vec[left], vec[right]);
	if(vec[center]<vec[right])
		swap(vec[center], vec[right]);
	swap(vec[center], vec[right-1]);
	return vec[right-1];
}
void output(const vector<int>& vec)
{
	for(unsigned int i=0; i<vec.size(); i++)
		cout<<vec[i]<<" ";
}
vector<int> convert(int *a, int size)
{
	vector<int> vec(size);
	for(int i=0; i<size; i++)
		vec[i]=a[i];
	return vec;
}
void insertionSort(vector<int>& vec, int left, int right)
{
	int j;
	for(unsigned int i=left+1; i<=right; i++)
	{
		int tmp=vec[i];
		for(j=i; j>0; j--)
		{
			if(tmp<vec[j-1])
				vec[j]=vec[j-1];
			else
				break;
		}
		vec[j]=tmp;
	}
}