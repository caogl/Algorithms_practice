#include<iostream>
#include<vector>
using namespace std;

int singleNumber(int A[], int n);

/*
* 因为题目已经说了，除了一个数字以外，其他的都出现了3次，如果我们把那个特殊的数剔除，并把剩下的数于每一位来加和的话，
* 每一位上1出现的次数必然都是3的倍数。所以，解法就在这里，将每一位数字分解到32个bit上，统计每一个bit上1出现的次数。 
* 最后对于每一个bit上1出现的个数对3取模，剩下的就是结果。
*/

int singleNumber2(int A[], int n);

int main()
{
	int a[]={12, 23, 432, 43, 41, 541, 23, 12, 542, 541, 43, 41, 432};
	cout<<"the single number is: "<<singleNumber(a, 13)<<endl;
	int b[]={12, 23, 432, 43, 41, 541, 23, 12, 12, 542, 24, 541, 43, 41, 432, 542, 542, 432, 41, 43, 541, 23};
	cout<<"the single number is: "<<singleNumber2(b, 22)<<endl;
	return 0;
}

int singleNumber(int A[], int n)  // for leetcode "single number"
{
	int result=A[0];
	for(int i=1; i<n; i++)
		result=A[i] ^ result;
	return result;
}


int singleNumber2(int A[], int n) // for leetcode "single number ||"
{
	vector<int> bitMap(32, 0);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<32; j++)
		{
			bitMap[j]+=((A[i]>>j) & 1);
		}
	}
	
	for(int i=0; i<32; i++)
	{
		bitMap[i]%=3;
	}
	
	int result=0;
	for(int i=0; i<32; i++)
		result+=bitMap[i]<<i;
	return result;
}


