#include<iostream>
using namespace std;

double power(double x, int n); 
double pow(double x, int n);

int main()
{
	double x=1.67;
	int n=1000;
	cout<<"pow(x, n) is: "<<pow(x, n)<<endl;
	return 0;
}

double power(double x, int n)
{
	if(n==0)
		return 1;
	double v=power(x, n/2);
	if(n%2==0)
		return v*v;
	else
		return v*v*x;
}

double pow(double x, int n)
{
	if(n<0)
		return 1/power(x, -n);
	else
		return power(x, n);
}
