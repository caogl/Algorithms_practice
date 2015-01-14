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
#include<unordered_map>
#include<iostream>
using namespace std;

int romanToInt(string s);

int main()
{
	string s="MXCVI";
	cout<<romanToInt(s)<<endl;
	s="DCXXI";
	cout<<romanToInt(s)<<endl;
	return 0;
}

int romanToInt(string s)
{
	unordered_map<char, int> RomInt;
	RomInt['I']=1;
	RomInt['V']=5;
	RomInt['X']=10;
	RomInt['L']=50;
	RomInt['C']=100;
	RomInt['D']=500;
	RomInt['M']=1000;
	int result=0;
	int prev=0;
	for(int i=0; i<s.size(); i++)
	{
		int cur=RomInt[s[i]];
		if(cur<=prev)	result+=cur;
		else	result+=(cur-2*prev);
		prev=cur;
	}
	return result;
}
