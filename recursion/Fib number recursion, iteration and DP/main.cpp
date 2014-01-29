#include<iostream>
using namespace std;

const int max_n=100;

unsigned long long fib(int n)
{
	if(n==1 || n==2)
		return 1;
	else
		return (fib(n-1)+fib(n-2));
}

unsigned long long fibIter(int n)
{
	if(n==1 || n==2)
		return 1;
	else
	{
		unsigned long long a=1, b=1;
		unsigned long long c;
		for(int i=3; i<=n; i++)
		{
			c=a+b;
			a=b;
			b=c;
		}
		return b;
	}
}

unsigned long long fibDP(int n)
{
	int f[max_n];
	f[0]=0;
	f[1]=1;
	for(int i=2; i<=n; i++)
		f[i]=f[i-1]+f[i-2];
	return f[n];
}

int main()
{
	for(int i=1; i<=10; i++)
		cout<<fib(i)<<" ";
	cout<<endl;
	for(int i=1; i<=10; i++)
		cout<<fibIter(i)<<" ";
	cout<<endl;
	for(int i=1; i<=10; i++)
		cout<<fibDP(i)<<" ";
	system("PAUSE");
	return 0;
}

