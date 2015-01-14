/* reference: leetcode official clean code handbook
Roman Literal Decimal
I 1
V 5
X 10
L 50
C 100
D 500
M 1000
Let’s work through some examples. Assume the input is “VII”, using the [additive
notation], we could simply add up each roman literal, ‘V’ + ‘I’ + ‘I’ = 5 + 1 + 1 = 7.
Now let’s look at another example input “IV”. Now we need to use the [subtractive 
notation]. We first look at ‘I’, and we add 1 to it. Then we look at ‘V’ and since a 
smaller roman literal ‘I’ appears before it, we need to subtract ‘I’ from ‘V’. Remember 
that we already added another ‘I’ before it, so we need to subtract a total of two one’s 
from it.
Below is a more complex example that involves both additive and subtractive notation: 
“MXCVI”. 
Roman literals from left to right Accumulated total
M 1000
MX 1000 + 10 = 1010
MXC 1010 + (100 – 2 * 10) = 1010 + 80 = 1090 
MXCV 1090 + 5 = 1095
MXCVI 1095 + 1 = 1096
 */

#include<string>
#include<iostream>
using namespace std;

int romanToInt(string s);

int main()
{
	string s="MMCMXXXVIII";
	cout<<romanToInt(s)<<endl;
	return 0;
}

int romanToInt(string s)
{
	int result=0;
	char pre=' '; // good trick
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]=='M' && pre!='C') result+=1000;
		if(s[i]=='M' && pre=='C') result+=800;
		if(s[i]=='C' && pre!='X') result+=100;
		if(s[i]=='C' && pre=='X') result+=80;
		if(s[i]=='X' && pre!='I') result+=10;
		if(s[i]=='X' && pre=='I') result+=8;
		
		if(s[i]=='I')	result+=1;
	
		if(s[i]=='D' && pre!='C') result+=500;
		if(s[i]=='D' && pre=='C') result+=300;
		if(s[i]=='L' && pre!='X') result+=50;
		if(s[i]=='L' && pre=='X') result+=30;
		if(s[i]=='V' && pre!='I') result+=5;
		if(s[i]=='V' && pre=='I') result+=3;
		pre=s[i];
	}	
	return result;
}
