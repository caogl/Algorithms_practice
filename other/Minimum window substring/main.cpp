// This code cannot pass the largest test case in leetcode, time exceeded
// The reason is the use of hash table, to pass that case, must use array as a hash table
// But the idea and result is right 
// For correct code, refer to http://fisherlei.blogspot.com/2012/12/leetcode-minimum-window-substring.html
// ¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?T¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?¿?
#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;

string minWindow(string S, string T);

int main()
{	
	string s1="ADOBECODEBANC";
	string t1="ABC";
	//string s1="aa";
	//string t1="aa";
	cout<<"The minimum window substring is: "<<minWindow(s1, t1)<<endl;
	return 0;
}

string minWindow(string S, string T) 
{
	string result="";
	if(S.size()==0 || T.size()==0 || S.size()<T.size())
		return result;

        unordered_map<char, int> times, times1, times2;
        for(int i=0; i<T.size(); i++)
        {
		if(times.find(T[i])==times.end())
			times[T[i]]=1;
		else
		{
			times[T[i]]++;
		}
        }
	times1=times;
	for(unordered_map<char, int>::iterator itr=times.begin(); itr!=times.end(); itr++)
		times2[itr->first]=0;
        string tmp;
        int start=0;

        while(start<S.size())
	{
		// move start position so that S[start] is a part of T
		int i=start;
		while(times.find(S[i])==times.end())  
		{
			i++;
			if(i==S.size())
				return result;
		}
		start=i;

		// find a substring meet the requirement
		while(true)
            	{
                	if(times.find(S[i])!=times.end())
                	{
                    		times2[S[i]]++;
                    		if(times1.find(S[i])!=times1.end())
                    		{	
                       			if(times1[S[i]]==1)
					{
						times1.erase(S[i]);
						if(times1.empty())
							break;
					}
					else
					{
						times1[S[i]]--;
					}
                    		}
                	}
                	i++;
                	if(i>=S.size())
                    		return result;
            	}

		// move the start position forward to squeeze the width of the substring, still valid
		while(true)
		{
			if(times2.find(S[start])==times2.end())
				start++;
			else if(times2[S[start]]>times[S[start]])
			{
				times2[S[start]]--;
				start++;
			}
			else
				break;
		}

            	tmp=S.substr(start, i-start+1);
		if(result=="")
			result=tmp;
		else if(tmp.size()<result.size())
		{
                	result=tmp;
		}

		times1=times;
		for(unordered_map<char, int>::iterator itr=times.begin(); itr!=times.end(); itr++)
			times2[itr->first]=0;
            	start=start+1;
        }
        return result;
}
