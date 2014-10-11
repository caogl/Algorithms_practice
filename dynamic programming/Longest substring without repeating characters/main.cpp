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
	vector<int> lasPos(26, -1);
	int start=-1; // the start place of the non-repeated sequence
	int maxLength=0;
	int n=s.size();
	for(int i=0; i<n; i++)
	{
		if(lasPos[s[i]-'a']>start) // repeated found
		{
			start=lasPos[s[i]-'a'];
			maxLength=max(maxLength, i-start);
			lasPos[s[i]-'a']=i;
		}
		else
		{
			lasPos[s[i]-'a']=i;
			maxLength=max(maxLength, i-start);
		}
	}
	return maxLength;
}
