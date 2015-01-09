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
        if(s.size()==0)
            return 0;
        
        int maxV=0;
        unordered_map<char, int> hashMap; // the size of the hashMap tracks the appearance
        int lasPos=0;
        for(int i=0; i<n; i++)
        {
            if(hashMap.find(s[i])==hashMap.end())
            {
                if(hashMap.size()<2)    hashMap[s[i]]=i;
                else
                {
                    auto itr2=hashMap.begin();
                    auto itr1=itr2++;
                    if(itr1->second<itr2->second)
                    {
                        maxV=max(maxV, i-lasPos);
                        lasPos=itr1->second+1; // be careful about lasPos , both initialization and update
                        hashMap.erase(itr1);
                    }
                    else
                    {
                        maxV=max(maxV, i-lasPos);
                        lasPos=itr2->second+1;
                        hashMap.erase(itr2);
                    }
                    hashMap[s[i]]=i;
                }
            }
            else
                hashMap[s[i]]=i;
        }
        
        return max(maxV, n-lasPos); // important check, error prone!
}
