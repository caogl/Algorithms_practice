#include<iostream>
#include<cstring>
using namespace std;

bool isMatch(const char *s, const char *p);
void isMatch(const char *s, const char *p, bool& match);

int main()
{
	char s1[]="aa";
	char p1[]="a";
	cout<<isMatch(s1, p1)<<endl;
	char s2[]="aa";
	char p2[]="aa";
	cout<<isMatch(s2, p2)<<endl;
	char s3[]="aaa";
	char p3[]="aa";
	cout<<isMatch(s3, p3)<<endl;
	char s4[]="aa";
	char p4[]="a*";
	cout<<isMatch(s4, p4)<<endl;
	char s5[]="aa";
	char p5[]=".*";
	cout<<isMatch(s5, p5)<<endl;
	char s6[]="ab";
	char p6[]=".*";
	cout<<isMatch(s6, p6)<<endl;
	char s7[]="aab";
	char p7[]="c*a*b";
	cout<<isMatch(s7, p7)<<endl;
	char s8[]="a";
	char p8[]="ab*";
	cout<<isMatch(s8, p8)<<endl;

	return 0;
}

bool isMatch(const char *s, const char *p)
{
	bool match=false;
	isMatch(s, p, match);
	return match;
}

void isMatch(const char *s, const char *p, bool& match)
{
	/* base */
	if(*s=='\0' && *p=='\0')
	{
		match=true;
		return;
	}	
	if(*s=='\0')
	{
		if(*p=='*' || *(p+1)=='*') // important check to pass test 8
		{
			isMatch(s, p+1, match);
			return;
		}
		else
			return;	
	}	
	if(*p=='\0')
		return;

	/* recursive */
	//(1): if the next char of p is not '*', move to p+1, must match the current char
	if(*(p+1)!='*')
	{
		if(*p!=*s && *p!='.')
			return;
		else
			isMatch(s+1, p+1, match);
	}
	//(2): if next char of p is '*', move to p+2
	else
	{
		isMatch(s, p+2, match); // '*' matches 0 preceding char

		// '*' matches one or more preceding chars		
		int lens=strlen(s);
		if(*p=='.')
		{
			for(int i=0; i<lens; i++) // to pass case 6
				isMatch(s+i+1, p+2, match);
		}
		else 
		{
			for(int i=0; i<lens; i++)
			{
				if(*p!=*(s+i))
					break;
				isMatch(s+i+1, p+2, match);
			}
		}
/*
 * -------------slow, time limit exceeded!-------------
		// '*' matches 1 or more chars
		if(*p==*s)
		{
			isMatch(s+1, p, match); // go on to try to match more same char
			isMatch(s+i+1, p+2, match); // only match one same char
		}
		
		else if(*p=='.')
		{
			int lens=strlen(s);
			for(int i=0; i<lens; i++)
			{	
				isMatch(s+i+1, p+2, match);
			}
		}
*/		
	}
}

