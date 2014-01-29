#include<iostream>
#include<vector>
using namespace std;

void percolateDown(vector<int>& vec, int hole);
vector<int> buildHeap(vector<int>& testVec);

int main()
{
	vector<int> testVec;
	testVec.push_back(10);
	testVec.push_back(2);
	testVec.push_back(11);
	testVec.push_back(13);
	testVec.push_back(3);
	testVec.push_back(1);
	testVec.push_back(7);
	testVec.push_back(9);
	testVec.push_back(6);
	testVec.push_back(21);
	vector<int> vec=buildHeap(testVec);
	for(unsigned int i=0; i<vec.size(); i++)
		cout<<vec[i]<<" ";
	system("PAUSE");
	return 0;
}

vector<int> buildHeap(vector<int>& testVec)
{
	vector<int> vec(testVec.size()+1);
	for(unsigned int i=0; i<testVec.size(); i++)
		vec[i+1]=testVec[i];
	for(unsigned int i=testVec.size()/2; i>0; i--)
		percolateDown(vec, i);
	return vec;
}

void percolateDown(vector<int>& vec, int hole)
{
	int child;
	int tmp=vec[hole];
	while(hole*2<vec.size())
	{
		child=hole*2;
		if(child!=vec.size()-1 && vec[child+1]<vec[child])
			child++;
		if(vec[child]<tmp)
			vec[hole]=vec[child];
		else
			break;
		hole=child;
	}
	vec[hole]=tmp;
}