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
        if(s.size()==0)	return 0;
        
        unordered_map<char, int> hashMap; // the size tracks the number of unique chars in sliding window
        int slow=0;
        int result=0;
        for(int fast=0; fast<s.size(); fast++)
        {
            	if(hashMap.find(s[fast])!=hashMap.end() || hashMap.size()<2)
            	{
                	hashMap[s[fast]]=fast;
                	result=max(result, fast-slow+1);
            	}
            	else
            	{
                	auto itr1=hashMap.begin();
                	auto itr2=hashMap.begin();
                	itr2++;
                	hashMap[s[fast]]=fast;
                	if(itr1->second<itr2->second)
                	{
                    		slow=itr1->second+1;
                    		hashMap.erase(itr1);
                	}
                	else
                	{
                    		slow=itr2->second+1;
                    		hashMap.erase(itr2);
                	}
            	}
        }
        return result;
}
