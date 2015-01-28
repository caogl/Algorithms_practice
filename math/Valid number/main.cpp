// reference: leetcode cleancode official handbook
/*
Example Questions Candidate Might Ask:
Q: How to account for whitespaces in the string?
A: When deciding if a string is numeric, ignore both leading and trailing whitespaces.
Q: Should I ignore spaces in between numbers – such as “1 1”?
A: No, only ignore leading and trailing whitespaces. “1 1” is not numeric.
Q: If the string contains additional characters after a number, is it considered valid?
A: No. If the string contains any non-numeric characters (excluding whitespaces and decimal
point), it is not numeric.
Q: Is it valid if a plus or minus sign appear before the number?
A: Yes. “+1” and “-1” are both numeric.
Q: Should I consider only numbers in decimal? How about numbers in other bases such as
hexadecimal (0xFF)?
A: Only consider decimal numbers. “0xFF” is not numeric.
Q: Should I consider exponent such as “1e10” as numeric?
A: No. But feel free to work on the challenge that takes exponent into consideration. (The Online
Judge problem does take exponent into account.)

A string could be divided into these four substrings in the order from left to right:
s1. Leading and trailing whitespaces (optional).
s2. Plus (+) or minus (–) sign (optional).
s3. Number.
We ignore s1, s2 and evaluate whether s3 is a valid number.
On the other hand, a decimal number could be further divided into three parts:
a. Integer part
b. Decimal point
c. Fractional part
The integer and fractional parts contain only digits. For example, the number “3.64” has integer part (3)
and fractional part (64). Both of them are optional, but at least one of them must present. For example, 
a single dot ‘.’ is not a valid number, but “1.”, “.1”, and “1.0” are all valid. Please note that “1.” is valid 
because it implies “1.0”.
*/

#include<string>
#include<cstring>
#include<iostream>
using namespace std;

//reference : http://yucoding.blogspot.com/2013/05/leetcode-question-118-valid-number.html

string deleteSpace(const char* s);
bool isValid(string &s);
bool isNumber(const char* s);

int main()
{
	char a[]=" 0.1";
	char b[]="abc";
	char c[]="2e10";
	char d[]=".";
	char e[]="1.";
	char f[]="1.e2";
	char g[]="-1.e+5";
	cout<<isNumber(a)<<isNumber(b)<<isNumber(c)<<isNumber(d)<<isNumber(e)<<isNumber(f)<<isNumber(g)<<endl;
	return 0;
}

// delete starting and trailing zeros
string deleteSpace(const char* s)
{
	if(strlen(s)==0)
		return "";
	int i=0;
	while(s[i]==' ')
		i++;
	int j=strlen(s)-1;
	while(s[j]==' ')
		j--;
	string result="";
	for(int k=i; k<=j; k++)
		result=result+s[k];
	return result;
}

bool isValid(string &s)
{
	int i=0;// position
	// check if '.', 'e' or '0-9' exists before the current position
	bool e=false;
	bool dot=false;
	bool digit=false;
	
	//for the fist char, the number can start with +, -, .
	if(!isdigit(s[0]))
	{
		if(s[0]=='+' || s[0]=='-' || s[0]=='.')
		{
			if(s.size()==1)
				return false;
			if(s[0]=='.')
				dot=true;
		}
		else
			return false;
	}
	else
		digit=true;
	
	for(int i=1; i<s.size()-1; i++)
	{
		switch (s[i])
		{
			case 'e':
			case 'E': // e cannot occur follow +, -
				if(e==false && s[i-1]!='+' && s[i-1]!='-' && digit==true && i!=s.size()-1)
					e=true;
				else
					return false;
				break;
			case '+': // +, - can only occur after e
			case '-':
				if(s[i-1]!='e' && s[i-1]!='E')
					return false;
				break;
			case '.':
				if(dot==false && e==false)
					dot=true;
				else
					return false;
				break;
			default:
				if(isdigit(s[i]))
					digit=true;
				else
					return false;
				break;
		}
	}
	
	if(isdigit(s[s.size()-1]))
		return true;
	if(s[s.size()-1]=='.' && !dot && !e && isdigit(s[s.size()-2]))
		return true;
	return false;
}

bool isNumber(const char* s)
{
	string s1=deleteSpace(s);
	if(s1.size()==0)
		return false;
	return isValid(s1);
}

