#include<iostream>
using namespace std;

void swap(int& a, int& b)
{
	a=a^b;
	b=b^a; // which is in fact b=b^a=b^a^b=a^b^b=a
	a=a^b; // which is in fact a=a^b=a^b^a=a^a^b=b
}

int main()
{
	int a=-7;
	int b=8;
	swap(a,b);
	cout<<a<<" "<<b<<endl;
}
