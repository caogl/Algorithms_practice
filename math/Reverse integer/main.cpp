// reference: leetcode official cleancode handbook
/*
 *  Generally for this kind of question sstream like method is NOT allowed by the interviewer !!!
(0) negative
(1) If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
(2) Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, 
    then the reverse of 1000000003 overflows. How should you handle such cases?
    For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#include<string>
#include<climits>
#include<iostream>
using namespace std;

int reverse(int x);

int main()
{
	int a=123;
	int b=-123;
	cout<<reverse(a)<<endl;
	cout<<reverse(b)<<endl;
	int c=1134236469;
	cout<<reverse(c)<<endl; // 0
	int d=123000000;
	cout<<reverse(d)<<endl; 
	return 0;
}

int reverse(int x)
{
        long result=0;
	int sign=1;
        if(x<0)	sign=-1;
        x=abs(x);
        while(x>0)
        {
            	result=(result*10+x%10);
            	x/=10;
        	if(result>INT_MAX)
                	return 0;
        }
        return result*sign;
}
