/* reference: http://yucoding.blogspot.com/2013/04/leetcode-question-83-restore-ip.html */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> restoreIpAddresses(string s);
void help(string& s, string& tmp, vector<string>& result, int kth); // kth number in the ip address
bool valid(string s);

int main()
{
	string s1="25525511135";
	string s2="11111111111111111111111111111111111111111111111111111111111";
	vector<string> result1=restoreIpAddresses(s1);
	for(int i=0; i<result1.size(); i++)
		cout<<result1[i]<<" ";
	cout<<endl;
	return 0;
}

bool valid(string s)
{
	if(s.size()==3 && (atoi(s.c_str())>255 || atoi(s.c_str())<100) )
		return false;
	if(s.size()==2 && atoi(s.c_str())<10)
		return false;
	return true;
}

vector<string> restoreIpAddresses(string s)
{
	string tmp;
	vector<string> result;
	int kth=0;
	help(s, tmp, result, kth);
	return result;
}

/* notice the reference and intermediate variable!!! */
void help(string& s, string& tmp, vector<string>& result, int kth)
{
	if(kth==4) 
	{
		if(s.empty()) // all the numbers are explored and string is splited throughly
			result.push_back(tmp);
		return;
	}
	for(int i=1; i<=3; i++)
	{
		if(s.size()>=i && valid(s.substr(0, i)))
		{
			if(kth>0)
			{
				string tmp1=tmp+"."+s.substr(0, i);
				string s1=s.substr(i);
				help(s1, tmp1, result, kth+1);
			}
			else
			{
				string tmp1=tmp+s.substr(0, i);
				string s1=s.substr(i);
				help(s1, tmp1, result, kth+1);
			}
		}
	}
}
