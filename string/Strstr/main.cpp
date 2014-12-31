#include<iostream>
#include<cstring>
using namespace std;

char *strStr(char *haystack, char *needle);

int main()
{
	char a[]="a";
	char b[]="a";
	char* result=strStr(a, b);
	cout<<a<<endl<<b<<endl<<result<<endl;

	char c[]="abcdefg";
	char d[]="def";
	result=strStr(c, d);
	cout<<c<<endl<<d<<endl<<result<<endl;

	return 0;
}

char *strStr(char *haystack, char *needle)
{
        int len1=strlen(haystack);
        int len2=strlen(needle);
        if(haystack==nullptr || needle==nullptr || len2>len1)
        {
            return nullptr;
        }
        char tmp[len2+1];
	tmp[len2]='\0';

        for(int i=0; i<=len1-len2; i++)
        {
            memcpy(tmp, &haystack[i], len2);
            if(strcmp(tmp, needle)==0)
	    {
                return &haystack[i];
	    }
        }
        return nullptr;
}
