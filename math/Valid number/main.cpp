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

A number could contain an optional exponent part, which is marked by a character ‘e’ followed by a whole number */

#include<string>
#include<cstring>
#include<iostream>
using namespace std;

bool isNumber(const char *s);

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

bool isNumber(const char *s) 
{
        string ss=s;
        // delete leading and trailing spaces
        int i=0; 
        while(ss[i]==' ')   i++;
        int j=ss.size()-1;
        while(ss[j]==' ')   j--;
        ss=ss.substr(i, j-i+1);
        
        i=0;
        bool isNumeric=false;
        int n=ss.size();
        if(i<n && (ss[i]=='+' || ss[i]=='-')) i++;
        while(i<n && isdigit(ss[i]))
        {
            i++;
            isNumeric=true;
        }
        if(i<n && ss[i]=='.')
        {
            i++;
            while(i<n && isdigit(ss[i]))
            {
                i++;
                isNumeric=true;
            }
        }
        
        // deal with the optional exponential part
        if(isNumeric && i<n && ss[i]=='e') // must check the first condition because "e9" is not a valid number !!!
        {
            i++;
            isNumeric=false;
            if(i<n && (ss[i]=='+' || ss[i]=='-'))   i++;
            while(i<n && isdigit(ss[i]))
            {
                i++;
                isNumeric=true;
            }
        }
        
        return isNumeric && (i==n);
}
