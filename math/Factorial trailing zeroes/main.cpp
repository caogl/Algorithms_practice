// reference: http://www.hawstein.com/posts/19.3.html
/*
5!, 包含1*5, 1个5
10!, 包含1*5,2*5, 2个5
15!, 包含1*5,2*5,3*5, 3个5
20!, 包含1*5,2*5,3*5,4*5, 4个5
25!, 包含1*5,2*5,3*5,4*5,5*5, 6个5
...
*/

#include<iostream>
using namespace std;

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
