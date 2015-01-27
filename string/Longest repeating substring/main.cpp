// Google interview question: http://www.careercup.com/question?id=13227715
// reference: http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/

/* Using the preprocessing from the KMP algorithm to solve the problem: 
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
   
   --> runtime: O(n^2)
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string longestRepeatingSubstring(string pattern);
string LPS(string pattern);

int main()
{
	string pattern1="DCAAAACAACAAAC";
	string pattern2="cababab";
	cout<<longestRepeatingSubstring(pattern1)<<endl<<longestRepeatingSubstring(pattern2)<<endl;
	return 0;
}

string longestRepeatingSubstring(string pattern)
{
	string result="";
	int maxLen=0;
	for(int i=0; i<pattern.size(); i++)
	{
		string tmp=LPS(pattern.substr(i));
		if(tmp.size()>maxLen)
		{
			result=tmp;
			maxLen=tmp.size();
		}
	}
	return result;
}

string LPS(string pattern)
{
	int len=0;  // lenght of the previous longest prefix suffix
	vector<int> lps(pattern.size(), 0);
	int i=1;
	while(i<pattern.size())
	{
		if(pattern[i]==pattern[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0) // This is tricky. Consider the example AAACAAAA and i = 7.
				len=lps[len-1]; // Also, note that we do not increment i here
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
	int maxLen=*max_element(lps.begin(), lps.end());
	return pattern.substr(0, maxLen);
}
