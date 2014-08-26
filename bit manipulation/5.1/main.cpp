#include<iostream>
#include <vector>
using namespace std;

void print_binary(int n);
int updateBit(int n, int m, int i, int j);

int main()
{
	int n = 1<<10, m = 21;
    	int ans = updateBit(n, m, 2, 6);
    	print_binary(n);
    	print_binary(m);
    	print_binary(ans);
    	return 0;
}
int updateBit(int n, int m, int i, int j)
{
	int temp=(1<<i)-1; // the position from 0 to (i-1) are 1, others 0
	temp=temp & n; // temp stores the bit in n from position 0 to (i-1);
	int result = n>>(j+1)<<(j+1); // first j+1 positions are 0
	result=result | temp |(m<<i); 
	return result;
}

void print_binary(int n)
{
    	vector<int> v;
    	int len = 8 * sizeof(int);
    	int mask = 1;
    	while(len--)
	{
        	if(n&mask) 
			v.push_back(1);
        	else v.push_back(0);
        		mask <<= 1;
    	}
    	while(!v.empty())
	{
        	cout<<v.back();
        	v.pop_back();
    	}
    	cout<<endl;
}
