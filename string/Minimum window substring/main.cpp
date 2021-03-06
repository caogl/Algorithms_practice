// reference: http://fisherlei.blogspot.com/2012/12/leetcode-minimum-window-substring.html
// 双指针，动态维护一个sliding window。尾指针不断往后扫，当扫到有一个窗口包含了所有T的字符后,
// 然后再收缩头指针，直到不能再收缩为止。最后记录所有可能的情况中窗口最小的

/* redo: 01/25/2015: use an array as hashMap because the keys are chars, runtime: 13ms
string minWindow(string S, string T) 
{
        if(S.size()==0 || T.size()==0)    return "";
        
        int expected[256];
        memset(expected, 0, sizeof(expected));
        for(int i=0; i<T.size(); i++)
            expected[T[i]]++;
        int minLen=INT_MAX;
        int matched[256];
        memset(matched, 0, sizeof(matched));
        int slow=0;
        int appeared=0;
        string result;
        
        for(int fast=0; fast<S.size(); fast++)
        {
            matched[S[fast]]++;
            if(matched[S[fast]]<=expected[S[fast]]) // contribute to match, notice the "<=" !!!
            {
                appeared++;
                if(appeared==T.size())
                {
                    while(matched[S[slow]]>expected[S[slow]]) 
                    {
                        matched[S[slow]]--;
                        slow++;
                    }
                    appeared--;
                    
                    if(fast-slow+1<minLen)
                    {
                        minLen=fast-slow+1;
                        result=S.substr(slow, minLen);
                    }
                    matched[S[slow]]--;
                    slow++;
                }
            }
        }
        return result;
}*/

#include<unordered_map>
#include<string>
#include<climits>
#include<iostream>
using namespace std;

// runtime 137ms
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
                    	// 收缩尾指针，直到不能再收缩为止
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
