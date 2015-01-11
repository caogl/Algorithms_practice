#include<iostream>
using namespace std;

int sqrt(int x);

int main()
{
	//demo, the rule of conversion in C++
	double a=4.9;
	int b=(int)a;
	cout<<b<<endl;
	// result is 4
	
	cout<<sqrt(4)<<endl<<sqrt(2)<<endl<<sqrt(15)<<endl;
	return 0;
}

int sqrt(int x)
{
	if(x<=0)
		return 0;
	if(x==1)
		return 1;
	long long high=x; 
	long long low=0;
	while(high-low>1) // if >= there would be a dead loop
	{
		long long mid=(high+low)/2;
		if(mid*mid>x)
			high=mid;
		else
			low=mid;
	}
	//return high;---------->must return low! See demo
	return low;
}
