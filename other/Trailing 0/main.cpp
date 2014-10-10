#include<iostream>
using namespace std;

// consider when 4*25, create 2 0s
// also consider 2*50, create 2 0s

int trailingZero(int n);

int main()
{
	cout<<"Trailing zero for 100 is: "<<trailingZero(100)<<endl;
	cout<<"Trailing zero for 25 is: "<<trailingZero(25)<<endl;
	cout<<"Trailing zero for 50 is: "<<trailingZero(50)<<endl;
	return 0;
}

int trailingZero(int n)
{
	int result=0;
	for(int i=5; n/i>=1; i*=5)
	{
		result+=n/i;
	}
	return result;
}
