// reference: leetcode cleancode handbook
// cannot use the sstream solution because the space must be O(1) for this question

#include<iostream>
using namespace std;

bool isPalindrome(int x);

int main()
{	cout<<isPalindrome(-121)<<endl; // handle negative number --> not palindrome
	cout<<isPalindrome(1671761)<<endl;
	cout<<isPalindrome(1234567899)<<endl; // handle overflow case
	return 0;
}

/* solution (1): reverse integer solution, but we use long to handle overflow, rather than return -1 */
bool isPalindrome(int x)
{
	int y=x;
	if(y<0)	return false;
	long x1=0;
	while(y>0)
	{
		x1=x1*10+y%10;
		y/=10;
	}
	return x==x1;
}

/* solution (2): compare the left and right and shrink, slower */
bool isPalindrome(int x)
{
	if(x<0)	return false;
	int div=1;
	while(x/div>=10)	div*=10;
	while(x!=0)
	{
		int left=x/div;
		int right=x%10;
		if(left!=right)	return false;
		x=(x%div)/10;
		div/=100;
	}
	return true;
}
