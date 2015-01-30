// reference: http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html
/* For each element in s
 * If *s==*p or *p == ? which means this is a match, then goes to next element s++ p++.
 * If p=='*', this is also a match, but one or many chars may be available, so let us save this *'s position and the matched s position.
 * If not match, then we check if there is a * previously showed up,
 *      if there is no *,  return false;
 *      if there is an *,  we set current p to the next element of *, and set current s to the next saved s position.
 * e.g: 

 * abed
 * ?b*d**

 * a=?, go on, b=b, go on,
 * e=*, save * position star=3, save s position ss = 3, p++
 * e!=d,  check if there was a *, yes, ss++, s=ss; p=star+1
 * d=d, go on, meet the end.
 * check the rest element in p, if all are *, true, else false;
 */
#include<iostream>
using namespace std;

bool isMatch(const char* s, const char* p);
//void isMatch(const char* s, const char* p, bool& match);

int main()
{
	cout<<isMatch("aabbc", "*")<<endl;
	cout<<isMatch("ab", "ab")<<endl;
	cout<<isMatch("aaa", "a")<<endl;
	cout<<isMatch("aa", "*")<<endl;
	cout<<isMatch("aa", "a*")<<endl;
	cout<<isMatch("aa", "?*")<<endl;
	cout<<isMatch("cab", "c*a*b")<<endl;
	cout<<isMatch("cab", "c?a*b")<<endl;
	cout<<isMatch("b", "??")<<endl;
	cout<<isMatch("c", "*?*")<<endl;
	cout<<isMatch("a", "aa")<<endl;
	cout<<isMatch("", "?")<<endl;
	cout<<isMatch("hi", "*?")<<endl;
	// time limit exceeded for solution (1)
	cout<<isMatch("abbaaaabbbbbababbbbbbbbaaabaabbabaabbaaabbbbabbbbab", "a*aaba***b**a*a********b")<<endl;
	cout<<isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b")<<endl;
	cout<<isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb")<<endl;
	return 0;
}

/* solution (2): dynamic programming: runtime: O(m+n), space: O(1)*/
bool isMatch(const char* s, const char* p)
{
	const char* pStar=nullptr; // the most recent '*' position of p
	const char* sMis=s; // the most recent mismatch position of s

	while(*s!='\0')
	{
		if((*s==*p) || (*p=='?'))	
		{
			s++;
			p++;
		}
		else if(*p=='*')
		{
			pStar=p;
			p++;
			sMis=s; // the mismatch position for s
		}
		else if(pStar!='\0')
		{
			p=pStar+1;
			s=++sMis; // mismatch position matched by *p='*', most recent mismatch position go by 1
		}
		else
			return false;
	}

	while(*p=='*')
		p++;
	return (*p=='\0');
}

/* solution (1): recursive --> time limit exceed for large cases even after backtracking
 *                             because of the recursive call in last "while" condition, runtime: O(m*n)     
bool isMatch(const char* s, const char* p)
{
	bool match=false;
	isMatch(s, p, match);
	return match;
}

void isMatch(const char* s, const char* p, bool& match)
{
	if(match==true) 
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
*/
