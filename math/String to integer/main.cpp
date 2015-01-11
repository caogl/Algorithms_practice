/*
(1): The function first discards as many whitespace characters as necessary until the first non-whitespace 
     character is found. Then, starting from this character, takes an optional initial plus or minus sign followed
     by as many numerical digits as possible, and interprets them as a numerical value.
(2): The string can contain additional characters after those that form the integral number, 
     which are ignored and have no effect on the behavior of this function.
(3): If the first sequence of non-whitespace characters in str is not a valid integral number,
     or if no such sequence exists because either str is empty or it contains only whitespace characters,
     no conversion is performed.
(4): If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned. 
*/

#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

int atoi1(const char* str);

int main()
{
	char a[]="6784"; // 6787
	char b[]="   -82613 213"; //-82613
	char c[]=" 25436712%$#2131"; // 25436712
	char d[]="-2147483647"; // -2147483647
	char e[]=" - 123"; // 0
	char f[]="++12"; // 0
	char g[]="2147483649"; // 2147483647
	char h[]="+-213"; // 0, easy to mistake!
	cout<<atoi1(a)<<endl;
	cout<<atoi1(b)<<endl;
	cout<<atoi1(c)<<endl;
	cout<<atoi1(d)<<endl;
	cout<<atoi1(e)<<endl;
	cout<<atoi1(f)<<endl;
	cout<<atoi1(g)<<endl;
	cout<<atoi1(h)<<endl;
	return 0;
}

int atoi1(const char* str)
{
	int num=0; 
	int sign=1;
	int len=strlen(str);
	int i=0;
	while(str[i]==' ')
	{
		i++;
		if(i==len)
			return 0;
	}
	if(str[i]=='+')
		i++;
	else if(str[i]=='-')
	{
		i++;
		sign=-1;
	}
	while(i<len)
	{
		if(str[i]==' ' || str[i]<'0' || str[i]>'9')
			break;
		if(INT_MAX/10<num || (INT_MAX/10==num && INT_MAX%10<(str[i]-'0')))
		{
			if(sign==1)
				return INT_MAX;
			else
				return INT_MIN;
		}
		num=num*10+str[i]-'0';
		i++;
	}
	return num*sign;
}
