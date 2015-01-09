// (1) keep a sliding window of 2 different chars substring
// (2) keep the lasPos, the char position before the sliding window
// (3) keep the most recent appeared position of two chars in the sliding window,
//     if needs to change these two chars, update the lasPos to the smaller most recent update 
//     position of the two chars, then update the two chars and most recent positions

#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;

int lengthOfLongestSubstringTwoDistinct(string s);

int main()
{
	string s1="abaccc";
	cout<<lengthOfLongestSubstringTwoDistinct(s1)<<endl;
	string s2="abacd";
	cout<<lengthOfLongestSubstringTwoDistinct(s2)<<endl;
	string s3="abccbbcccaaacaca";
	cout<<lengthOfLongestSubstringTwoDistinct(s3)<<endl;

	return 0;
}

int lengthOfLongestSubstringTwoDistinct(string s)
{
	int n=s.size();
        if(n==0)
            return 0;
        unordered_map<char, int> hashMap;
        int i=0;
	int lasPos=-1;
        for(i=0; i<n; i++)
        {
            if(hashMap.find(s[i])!=hashMap.end() || hashMap.size()<2)
                hashMap[s[i]]=i;
            else
                break;
        }

	int maxLen=i;        
        if(i==n)
            return maxLen;

	auto itr=hashMap.begin();
	char c1=itr->first;
	char c2=(++itr)->first;

        for(int j=i; j<n; j++)
        {
            if(hashMap.find(s[j])==hashMap.end())
            {
		maxLen=max(maxLen, j-lasPos-1);
		lasPos=min(hashMap[c1], hashMap[c2]);
                if(hashMap[c1]==lasPos) // to erase c1
		{
			hashMap.erase(c1);
			hashMap[s[j]]=j;
			c1=s[j];
		}
		else
		{
			hashMap.erase(c2);
			hashMap[s[j]]=j;
			c2=s[j];
		}
            }
            else
            {
		hashMap[s[j]]=j;
            }
        }
        
        maxLen=max(maxLen, n-lasPos-1); // remember to check, mistake prone !!!
	return maxLen;
}
