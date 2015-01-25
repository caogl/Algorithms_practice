// reference: http://fisherlei.blogspot.com/2012/12/leetcode-longest-substring-without.html
// 从左往右扫描，当遇到重复字母时，以上一个重复字母的index +1，作为新的搜索起始位置, 直到扫描到最后一个字母。

#include<vector>
#include<string>
#include<iostream>
using namespace std;

int lengthOfLongestSubstring(string s);

int main()
{
	string s1="abcdacdejhulmnsabdes";
	string s2="bbbbbb";
	cout<<"The length of LSWRC of "<<s1<<" is "<<lengthOfLongestSubstring(s1)<<endl;
	cout<<"The length of LSWRC of "<<s2<<" is "<<lengthOfLongestSubstring(s2)<<endl;
	return 0;
}

int lengthOfLongestSubstring(string s) 
{
         int dp[256];
         memset(dp, -1, sizeof(dp));
         int startPos=0;
         int result=0;
         for(int i=0; i<s.size(); i++)
         {
             	if(dp[s[i]]>=startPos)
             	{
             		// ordering of there two lines important!!!
                	startPos=dp[s[i]]+1;
                 	dp[s[i]]=i;
             	}
             	else
             	{
                	dp[s[i]]=i;
                	result=max(result, i-startPos+1);
             	}
         }
         return result;
}
