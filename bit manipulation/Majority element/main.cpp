// optimal solution, refer to: http://www.csdn123.com/html/topnews201408/85/11585.htm
// bit manipulation is a trival solution to this problem for linear runtime and constant space

#include<vector>
#include<iostream>

using namespace std;

int majorityElement(vector<int> &num);

int main()
{
	vector<int> vec={1,2,1,1,5,3,1,4,1,2,1,1,3,7,1,1,1,1,1,5,2,9,1,1,1,1,1,1,1};
	cout<<majorityElement(vec)<<endl;
	return 0;
}

int majorityElement(vector<int> &num)
{
	vector<int> bitMap(32, 0);
	for(int i=0; i<32; i++)
	{
		int zeros=0;
		int ones=0;
		for(int j=0; j<num.size(); j++)
		{
			if(num[j]>>i & 1)
				ones++;
			else
				zeros++;
		}
		if(ones>zeros)
			bitMap[i]=1;
		else
			bitMap[i]=0;
	}
	int result=0;
	for(int i=0; i<32; i++)
		result+=bitMap[i]<<i;
	return result;
}

/*
 * The solution that delete duplicates in pairs
int majorityElement(vector<int> &num)
{
	int elem=0;
	int count=0;
	for(int i=0; i<num.size(); i++)
	{
		if(count==0) // if already deleted all pairs and no more elements left over
		{
			elem=num[i];
			count++;
		}
		else
		{
			if(num[i]==elem)
				count++;
			else
				count--;
		}
	}
	return elem;
}
*/
