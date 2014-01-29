#include<iostream>
#include<cstring>
using namespace std;

void removeDuplicate(char* s); // this removes duplicate chars IN PLACE!

int main()
{
	char s1[]="caoguanglei loves weichunlei";
	char s2[]="ababababab";
	char s3[]="";
	char s4[]="a";
	char s5[]="abcdefghijklmn";
	removeDuplicate(s1);
	removeDuplicate(s2);
	removeDuplicate(s3);
	removeDuplicate(s4);
	removeDuplicate(s5);
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;
	cout<<s4<<endl;
	cout<<s5<<endl;
	system("PAUSE");
	return 0;
}

void removeDuplicate(char* s)
{
	int n=strlen(s);
	int p=0;
	for(int i=0; i<n; i++)
	{
		if(s[i]!='\0')
		{
			s[p++]=s[i];
			for(int j=i+1; j<n; j++)
			{
				if(s[i]==s[j])
					s[j]='\0';
			}
		}
	}
	s[p]='\0';
}