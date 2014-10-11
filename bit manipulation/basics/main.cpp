#include<iostream>
using namespace std;

//reference:http://blog.csdn.net/morewindows/article/details/7354571

/*
C++中关于位操作，记录几点需要注意的地方：

    一个有符号数，如果它的最高位为1，它右移若干位后到达位置i， 那么最高位到第i位之间全是1，例如：

int a = 1;
a <<= 31;    //a:1后面带31个0
a >>= 31;    //a:32个1，即-1
cout<<a<<endl;    //输出-1(写下负号，然后取反加1)

    一个无符号数，如果它的最高位为1，它右移若干位后到达位置i， 那么最高位到第i位之间全是0，例如：

unsigned int a = 1;
a <<= 31;    //a:1后面带31个0
a >>= 31;    //a:31个0后面带一个1，即1
cout<<a<<endl;    //输出1

    无论是有符号数还是无符号数，左移若干位后，原来最低位右边新出现的位全为0
    一个有符号的正数，它的最高位为0，如果因为左移使得最高位为1，那么它变为负数， 而后无论怎样右移，它都还是负数。除非因为再次左移使最高位变为0，那么它变回正数。
    int的最大值：~(1<<31)，即0后面跟31个1
    int的最小值：1<<31，即1后面跟31个0
    unsigned int最大值：~0，即32个1
    unsigned int最小值：0
    其它数据类型与int类似，只是位长不一样。

*/


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
