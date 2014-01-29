#include<iostream>
#include<vector>
using namespace std;

int binarySearch(const vector<int>& testVec, int value);
int binarySearch(const vector<int>& testVec, int value, int left, int right);
int main()
{
	vector<int> testVec;
	testVec.push_back(1);
	testVec.push_back(3);
	testVec.push_back(8);
	testVec.push_back(9);
	testVec.push_back(11);
	testVec.push_back(13);
	testVec.push_back(14);
	testVec.push_back(15);
	testVec.push_back(20);
	testVec.push_back(22);
	testVec.push_back(23);
	cout<<binarySearch(testVec, 20);
	system("PAUSE");
	return 0;
}

int binarySearch(const vector<int>& testVec, int value)
{
	return binarySearch(testVec, value, 0, testVec.size()-1);
}

int binarySearch(const vector<int>& testVec, int value, int left, int right)
{
	int center=(right-left)/2+left;
	if(value==testVec[center])
		return center;
	else if(value<testVec[center])
		return binarySearch(testVec, value, left, center-1);
	else
		return binarySearch(testVec, value, center+1, right);
}
