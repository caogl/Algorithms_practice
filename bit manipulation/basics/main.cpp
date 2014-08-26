#include<iostream>
using namespace std;

//reference:http://blog.csdn.net/morewindows/article/details/7354571

bool isOdd(int a); // if an integer is odd number
void swap(int& a, int& b); // swap two integers without buffer
int changeSign(int a); //change the sign of a number
int absValue(int a); // get the absolute value

int main()
{
	int a=-7;
	int b=8;
	cout<<"a is: "<<a<<" b is: "<<b<<endl;
	if(isOdd(a))
		cout<<"a is odd"<<endl;
	if(isOdd(b))
		cout<<"b is odd"<<endl;
	swap(a, b);
	cout<<"a is: "<<a<<" b is: "<<b<<endl; 
	cout<<"-a is: "<<changeSign(a)<<" -b is: "<<changeSign(b)<<endl;
	cout<<"|a| is: "<<absValue(a)<<" |b| is: "<<absValue(b)<<endl;
	return 0;
}

bool isOdd(int a)
{
	return (a & 1);
}

void swap(int& a, int& b)
{
	a=a^b;
	b=b^a;
	a=a^b;
}

int changeSign(int a)
{
	return ~a+1;
}

int absValue(int a)
{
	int i=a>>31;
	if(i==0)
		return a;
	else
		return changeSign(a);
}
