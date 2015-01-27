#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

// n = length of target
// m = length of pattern

/* solution (1): brute and force algorithm: O(mn) time, O(1) space
int strStr(char *haystack, char *needle);
bool compare(char* str1, char* str2, int len2); */

/* solution (2): KMP algorithm: O(n) runtime, O(m) space
 *               reference: http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm 
 * step[1] --> preprocessing:
   lps indicates longest proper prefix which is also suffix.. For each sub-pattern pat[0¿i] where i = 0 to m-1,  
   lps[i] stores length of the maximum matching proper prefix which is also a suffix of the sub-pattern pat[0..i]
   lps[i] = the longest proper prefix of pat[0..i] 
              which is also a suffix of pat[0..i]. 
   Examples:
   For the pattern "AABAACAABAA", lps[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]
   For the pattern "ABCDE", lps[] is [0, 0, 0, 0, 0]
   For the pattern "AAAAA", lps[] is [0, 1, 2, 3, 4]
   For the pattern "AAABAAA", lps[] is [0, 1, 2, 0, 1, 2, 3]
   For the pattern "AAACAAAAAC", lps[] is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4] 
   
   step[2] --> search based on lps:
   if current index of pattern and target mismatch, target index shrink back to suffix position correspond
   to target[index-1] */

int strStr(char *haystack, char *needle);
vector<int> LPS(char* pattern);

/* solution (3): Building trie: O(n^2) time, O(n^2) space, each query O(m) time, see the OOP design dir for the code*/

int main()
{
	char b[]="AAAAAAAAAAAAAAAAAB";
	char a[]="AAAAB";
	cout<<a<<endl<<b<<endl<<strStr(b, a)<<endl;

	char d[]="ABABABCABABABCABABABC";
	char c[]="ABABAC";
	cout<<c<<endl<<d<<endl<<strStr(d, c)<<endl;

	return 0;
}

/* solution (2) */
int strStr(char *haystack, char *needle)
{
	int m=strlen(needle);
	int n=strlen(haystack);
	
	/* remember to check corner cases!! */
	if(m==0)	return 0;
	if(n==0)	return -1;

	vector<int> lps=LPS(needle);
	int i=0; // index for haystack
	int j=0; // index for needle
	while(i<n)
	{
		if(needle[j]==haystack[i])
		{
			i++;
			j++;
		}
		if(j==m)
			return i-m;
		else if(i<n && needle[j]!=haystack[i])
		{
			if(j!=0)	j=lps[j-1];
			else	i++;
		}
	}
	return -1;
}

vector<int> LPS(char* pattern)
{
	int len=0;  // lenght of the previous longest prefix suffix
	int n=strlen(pattern);
	vector<int> lps(n, 0);
	int i=1;
	while(i<n)
	{
		if(pattern[i]==pattern[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0) // This is tricky. Consider the example AAACAAAA and i = 7, len=3.
			           // Now pattern[7]!=pattern[3], so len=lps[len-1]=lps[2]=2;
			           // i remains same, pattern[7]=pattern[2], then len=3, lps[7]=3
				len=lps[len-1]; // Also, note that we do not increment i here
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
	return lps;
}

/* solution (1) 
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
} */
