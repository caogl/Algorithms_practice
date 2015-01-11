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
