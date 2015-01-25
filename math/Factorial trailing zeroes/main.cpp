// reference: http://www.hawstein.com/posts/19.3.html

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
	if(n<=0)	return 0;
	int result=0;
	while(n/5>0)
	{
		result+=n/5;
		n/=5;
	}
	return result;
}
