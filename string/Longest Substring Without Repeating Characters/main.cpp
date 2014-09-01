#include<iostream>
#include<string>
#include<vector>
using namespace std;

int longestSubstring(string s);

int main()
{
	string a="ccccghcbazxc";
	cout<<"string is: "<<a<<endl;
	cout<<"The length of the longest non-repeated substring is: "<<longestSubstring(a)<<endl;
	return 0;
}

int longestSubstring(string s)
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
