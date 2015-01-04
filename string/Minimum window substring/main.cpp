// reference: http://fisherlei.blogspot.com/2012/12/leetcode-minimum-window-substring.html

#include<unordered_map>
#include<string>
#include<climits>
#include<iostream>
using namespace std;

string minWindow(string S, string T);

int main()
{	
	string s1="bdab";
	string t1="ab";
	cout<<"The minimum window substring is: "<<minWindow(s1, t1)<<endl;
	return 0;
}

string minWindow(string S, string T)
{
        if(T.size()==0 || T.size()>S.size())
            return "";
        
        int n=T.size();
        unordered_map<char, int> expected;
        for(int i=0; i<T.size(); i++)
            expected[T[i]]++;
        
        unordered_map<char, int> matched;
        for(auto itr=expected.begin(); itr!=expected.end(); itr++)
            matched[itr->first]=0;
        
        int minLen=INT_MAX;
        string result;
        int slow=0;
        int appeared=0;

        for(int fast=0; fast<S.size(); fast++)
        {
            if(expected.find(S[fast])!=expected.end())
            {				
                if(matched[S[fast]]<expected[S[fast]])
                {
                    appeared++;
                    matched[S[fast]]++;
                    if(appeared==n) // sliding window matched T
                    {
                        while(expected.find(S[slow])==expected.end() || matched[S[slow]]>expected[S[slow]])
                        {
                            matched[S[slow]]--;
                            slow++;
                        }
                        if(minLen>fast-slow+1)
                        {
                            minLen=fast-slow+1;
                            result=S.substr(slow, minLen);
                        }

			matched[S[slow]]--;
                        slow++;
                        appeared--;
                    }
                }
                else
                    matched[S[fast]]++;
            }
        }
        return result;
}
