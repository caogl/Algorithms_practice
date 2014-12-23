// reference: http://fisherlei.blogspot.com/2012/12/leetcode-gray-code.html

#include<iostream>
#include<vector>
using namespace std;

vector<int> grayCode(int n);
void printVec(const vector<int>& vec);

int main()
{
	vector<int> result=grayCode(5);
	printVec(result);
	return 0;
}

void printVec(const vector<int>& vec)
{
	for(int i=0; i<vec.size(); i++)
		cout<<vec[i]<<" ";
	cout<<endl; 
}

vector<int> grayCode(int n)
{
	vector<int> result;
	result.push_back(0);
	for(int i=0; i<n; i++) // iteratively, generate vector<int> for length=1,2, 3...n
	{
		int highestBit=(1<<i);
		for(int j=result.size()-1; j>=0; j--)
			result.push_back(highestBit+result[j]);
	}
	return result;
}


