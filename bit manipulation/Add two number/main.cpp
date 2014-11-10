/* reference: http://www.hawstein.com/posts/20.1.html */

#include<iostream>
using namespace std;

int add(int a, int b)
{
	if(b==0)
		return a;
	int sum=a^b; //各位相加，不计进位
	int carry=((a & b)<<1); //记下进位
	return add(sum, carry);
}
int main()
{
	int a=876;
	int b=761;
	cout<<"The sum is: "<<add(a, b)<<" while the correct sum is: "<<a+b<<endl;
	return 0;
}
