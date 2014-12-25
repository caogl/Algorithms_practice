/* dropbox interview question:
   pattern = 'abba',    data = 'redbluebluered'       true
   pattern = 'abba',    data = 'redblueyellowred'     false
   pattern = 'aaaa',    data = 'redredredred'         true
   pattern = 'abba',    data = redredredred'          false
*/

#include<unordered_set>
#include<unordered_map>
#include<iostream>
#include<string>
using namespace std;

bool match(string pattern, string data);
void match(string& pattern, string& data, unordered_map<char, string>& map1, unordered_set<string>& matched, bool &find);

int main()
{
	cout<<match("abba", "redbluebluered")<<endl; // test1
	cout<<match("abba", "redblueyellowred")<<endl; // test2
	cout<<match("abca", "redblueyellowred")<<endl; //test3
	cout<<match("aaaa", "redredredred")<<endl; //test4
	cout<<match("abba", "redredredred")<<endl; //test5 !!! important, cannot create map1[b]==map1[a]
	return 0;
}

bool match(string pattern, string data)
{
	string pattern1=pattern;
	string data1=data;
	bool find=false;
	unordered_map<char, string> map1;
	unordered_set<string> matched;
	match(pattern1, data1, map1, matched, find);
	return find;
}

void match(string& pattern, string& data, unordered_map<char, string>& map1, unordered_set<string>& matched, bool &find)
{
	/* base case */
	if(pattern.size()==0 && data.size()==0)
	{
		find=true;
		return;
	}
	else if(pattern.size()==0 || data.size()==0)
	{
		return;
	}

	/* recursive */
	if(map1.find(pattern[0])==map1.end())
	{
		for(int i=1; i<=data.size(); i++) // notice the <=!!!
		{
			if(matched.find(data.substr(0, i))==matched.end()) // for test4 and test5
			{
				string data1=data.substr(0, i);
				string data2=data.substr(i, data.size()-i);
				map1[pattern[0]]=data1;
				matched.insert(data1);
				string pattern1=pattern.substr(1, pattern.size()-1);
				match(pattern1, data2, map1, matched, find);
				matched.erase(data1);
				map1.erase(pattern[0]);
			}
		}
	}
	else
	{
		for(int i=1; i<=data.size(); i++) // notice the <=!!
		{
			if(data.substr(0, i)==map1[pattern[0]])
			{
				data=data.substr(i, data.size()-i);
				pattern=pattern.substr(1, pattern.size()-1);
				match(pattern, data, map1, matched, find);
			}
		}
	}
}

