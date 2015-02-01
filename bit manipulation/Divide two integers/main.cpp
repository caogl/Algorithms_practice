#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

int divide(int dividend, int divisor);

int main()
{
	cout<<divide(1, -1)<<endl;
	return 0;
}

int divide(int dividend, int divisor) 
{
        //long long dividend1=abs(dividend); // wrong abs(INT_MIN)>INT_MAX! 
        //long long divisor1=abs(divisor);
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        long long dividend1=dividend;
        long long divisor1=divisor;
	dividend1=abs(dividend1);
	divisor1=abs(divisor1);

        int sign=1;
        if((dividend>0)^(divisor>0))    sign=-1;

        int result=0;
        for(int i=31; i>=0; i--)
        {
            if(dividend1>=(divisor1<<i))
            {
                result+=(1<<i);
                dividend1-=(divisor1<<i);
            }
        }
        return sign*result;
}
