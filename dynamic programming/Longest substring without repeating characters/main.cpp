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
    	vector<int> vec(256, -1);
    	int maxLength=0;
    	int startPos=-1; // the startPos of non-repeated char
    	for(int i=0; i<s.size(); i++)
    	{
        	if(vec[s[i]]>startPos)
        	{
            		startPos=vec[s[i]];
            		vec[s[i]]=i;
        	}
        	else
        	{
            		vec[s[i]]=i;
            		maxLength=max(maxLength, i-startPos);
        	}
    	}
    	return maxLength;
}
