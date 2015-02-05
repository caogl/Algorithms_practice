// facebook interview questions: http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=107664&extra=page%3D2%26filter%3Dsortid%26sortid%3D311%26searchoption[3046][value][2]%3D2%26searchoption[3046][type]%3Dcheckbox%26sortid%3D311

/*
actually the first part of the leetcode problem: "palindrome partition"  */

#include<iostream>
using namespace std;

int numOfPalin(string s);

int main()
{
	cout<<numOfPalin("aba")<<" "<<numOfPalin("abba")<<endl;
	return 0;
}

int numOfPalin(string s)
{
	bool isPalindrome[s.size()][s.size()];
	int count=0;
	for(int i=0; i<s.size(); i++)
	{
		for(int j=0; j<=i; j++)
		{
			if(s[i]==s[j] && (i-j<2 || isPalindrome[j+1][i-1]))
			{
				count++;
				isPalindrome[j][i]=true;
			}
			else
				isPalindrome[j][i]=false;
		}
	}
	return count;
}
