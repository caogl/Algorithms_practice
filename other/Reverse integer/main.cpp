// reference: leetcode official cleancode handbook
/*
 *  Generally for this kind of question sstream like method is NOT allowed by the interviewer !!!
(0) negative
(1) If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
(2) Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, 
    then the reverse of 1000000003 overflows. How should you handle such cases?
    For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
--->To check for overflow/underflow, we could check if ret>214748364 or ret<-214748364 before multiplying by 10.
    On the other hand, if ret==214748364, it must not overflow because the last reversed digit is guaranteed to be 1 due 
    to constraint of the input x.
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
        int bound=INT_MAX/10;
        int result=0;
	int sign=1;
        if(x<0)	sign=-1;
        x=abs(x);
        while(x>0)
        {
        	if(result>bound)
                	return 0;
            	result=(result*10+x%10);
            	x/=10;
        }
        return result*sign;
}
