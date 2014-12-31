#include<iostream>
#include<cstring>
using namespace std;

int strStr(char *haystack, char *needle);
bool compare(char* str1, char* str2, int len2);

int main()
{
	char a[]="a";
	char b[]="a";
	cout<<a<<endl<<b<<endl<<strStr(a, b)<<endl;

	char c[]="abcdefg";
	char d[]="def";
	cout<<c<<endl<<d<<endl<<strStr(c, d)<<endl;

	return 0;
}

int strStr(char *haystack, char *needle)
{
        int len1=strlen(haystack);
        int len2=strlen(needle);
        if(haystack==nullptr || needle==nullptr || len2>len1)
        {
            return -1;
        }

        for(int i=0; i<=len1-len2; i++)
        {
            if(compare(needle, &haystack[i], len2))
                return i;
        }
        return -1;
}

bool compare(char* str1, char* str2, int len2)
{
    for(int i=0; i<len2; i++)
        if(str1[i]!=str2[i])
            return false;
    return true;
}
