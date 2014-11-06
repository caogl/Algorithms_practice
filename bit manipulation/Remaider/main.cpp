// interview question form datarobot
// calculate the remainder without division and moduler
/*-- Notice that there is still a possible of overflow, when d^shift can cause overflow

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
	int result=m;
	
	int bitDist=1; // the longest big shift(<<) distance so that after the 
		       // shift the shift number is smaller than dvidend
	result=(d<<bitDist);
	while(result<=m)
	{
		bitDist++;
		result=(d<<bitDist);
	}
	bitDist--;
	
	// to make up the dividend, and get the remainder
	result=m;
	for(int i=bitDist; i>=0; i--)
	{
		if(result>=(d<<i))
		{
			result-=(d<<i);
		}
	}
	cout<<"The calculated result is: "<<result<<endl;

	return 0;
}
