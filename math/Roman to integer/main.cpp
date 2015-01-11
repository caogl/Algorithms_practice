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
