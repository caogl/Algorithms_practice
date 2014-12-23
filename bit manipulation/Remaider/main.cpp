// interview question form datarobot
// calculate the remainder without division and moduler

#include<iostream>
using namespace std;

int main()
{
	cout<<"Please input the dividend: "<<endl;
	int m;
	cin>>m;
	cout<<"Please input the divisor: "<<endl;
	int d;
	cin>>d;
	cout<<"The correct remainder is: "<<m%d<<endl;
	long long result=m;
	

	/*(1)-- Notice that there is a possible of overflow, when d^shift can cause overflow,
         *      use long long instead!!! */
	long long m1=m; 
	long long d1=d;

	/*(2)-- Notice that we should go from the high bit to low bit! */
	for(int i=31; i>=0; i--)
	{
		if(result>=(d1<<i))
		{
			result-=(d1<<i);
		}
	}

	cout<<"The calculated result is: "<<result<<endl;
	return 0;

/*
 * 	all these are optionl
 *
	int bitDist=1; // the longest big shift(<<) distance so that after the 
		       // shift the shift number is smaller than dvidend
	result=(d1<<bitDist);
	while(result<=m1)
	{
		bitDist++;
		result=(d1<<bitDist);
	}
	bitDist--;
	
	// to make up the dividend, and get the remainder
	result=m1;
	for(int i=bitDist; i>=0; i--)
	{
		if(result>=(d1<<i))
		{
			result-=(d1<<i);
		}
	}
*/
}
