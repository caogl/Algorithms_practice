/* reference: http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html 
 * This problem is far too hard to solve
 * intuitive solution is recursive, but it will timeout and tend to ignore a lot of corner cases like when d is '?' while s is '\0'
 * optimal and acceptable solution is very hard!!!!
 */ 


#include<iostream>
using namespace std;

bool isMatch(const char* s, const char* p);
void isMatch(const char* s, const char* p, bool& match);

int main()
{
	//cout<<isMatch("aa", "a")<<endl;
	//cout<<isMatch("ab", "ab")<<endl;
	//cout<<isMatch("aaa", "a")<<endl;
	//cout<<isMatch("aa", "*")<<endl;
	//cout<<isMatch("aa", "a*")<<endl;
	//cout<<isMatch("aa", "?*")<<endl;
	//cout<<isMatch("cab", "c*a*b")<<endl;
	//cout<<isMatch("cab", "c?a*b")<<endl;
	//cout<<isMatch("b", "??")<<endl;
	//cout<<isMatch("c", "*?*")<<endl;
	//cout<<isMatch("a", "aa")<<endl;
	//cout<<isMatch("", "?")<<endl;
	cout<<isMatch("hi", "*?")<<endl;
	// time limit exceeded
	//cout<<isMatch("abbaaaabbbbbababbbbbbbbaaabaabbabaabbaaabbbbabbbbab", "a*aaba***b**a*a********b")<<endl;
	//cout<<isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b")<<endl;
	//cout<<isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb")<<endl;
	return 0;
}


bool isMatch(const char* s, const char* p)
{
	const char* pStart=nullptr;
	const char* sNextPos=s;

	while(*s!='\0')
	{
		/* must be if all here because you need to always check whether s is '\0' 
		   in all of the three if statement, if *s=='\0', the if condition no longer true!*/
		if((*s==*p) || (*p=='?'))	
		{
			s++;
			p++;
			continue;
		}
		if(*p=='*')
		{
			pStart=p;
			p++;
			sNextPos=s;
			continue;
		}
		if(pStart!='\0')
		{
			p=pStart+1;
			s=++sNextPos; //----when p is found , s should not ++, then after first not match, s++ 
			continue;
		}
		return false;
	}

	while(*p=='*')
		p++;
	return (*p=='\0');
}


/* time limit exceed for recursive solution , this one although tried to optimize, also cannot pass ("b", "??")
   but should pay attention to (1)(2) optimization
bool isMatch(const char* s, const char* p)
{
	bool match=false;
	isMatch(s, p, match);
	return match;
}

void isMatch(const char* s, const char* p, bool& match)
{
	if(match==true) // optimize(1): add this step as branching can speed up, as long as can match, step all the recursive calls
		return;

	while(*s==*p || *p=='?')
	{
		if(*s=='\0' && *p=='\0')
		{
			match=true;
			return;
		}
		s++;
		p++;
	}
	if(*p=='*')
	{
		// cannot assign const char* to char* !
		p++;
		while(*p=='*') //optimize(2): add this step because more than one '*' is same as one '*'
			p++;
		if(*p=='\0')
		{
			match=true;
			return;
		}
		isMatch(s, p, match);
		while(*s!='\0')
		{
			s++;
			isMatch(s, p, match);
		}
	}
}

*********initial solution, pass the test cases listed, but time limit exceeded for very large case,
         should not exist error  ************
class Solution {
public:
bool isMatch(const char* s, const char* p)
{
	bool match=false;
	isMatch(s, p, match);
	return match;
}

void isMatch(const char* s, const char* p, bool& match)
{
	if(match==true) // add this step as branching can speed up, but still cannot pass all test cases
		return;
	if(*s=='\0' && *p=='\0')
	{
		match=true;
		return;
	}
	else if(s=='\0')
	{
		while(*p=='*')
			p++;
		if(*p=='\0')
			match=true;
		return;
	}
	
	if(*s==*p || *p=='?')
	{
		s++;
		p++;
		isMatch(s, p, match);
	}
	else if(*p=='*')
	{
		// cannot assign const char* to char* !
		p++;
		while(*p=='*')
			p++;
		isMatch(s, p, match);
		while(*s!='\0')
		{
			s++;
			isMatch(s, p, match);
		}
	}
}

};

*/
