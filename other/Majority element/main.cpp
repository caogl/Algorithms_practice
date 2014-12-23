// optimal solution, refer to: http://www.csdn123.com/html/topnews201408/85/11585.htm

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
