#include<iostream>
#include<cstring>
using namespace std;

void reverse(char* s);
void swap(char& a, char& b);

int main()
{
	char s[]="caoguanglei loves weichunlei";
	char a[]="abc";
	reverse(s);
	cout<<s<<endl;
	a[2]='\0';
	cout<<strlen(a)<<endl;
	cout<<a;
	system("PAUSE");
	return 0;
}

void swap(char& a, char& b)
{
	char c=a;
	a=b;
	b=c;
}
void reverse(char* s)
{
	int n=strlen(s);
	for(int i=0;i<n/2; i++)
		swap(s[i], s[n-i-1]);
}