#include<iostream>
#include<string>
#include<vector>
using namespace std;

void checkAnagram(string& a, string& b); 
void replaceSpace(string& a);

int main()
{
	string s1="caoguanglei loves weichunlei";
	string s2="weichunlei loves caoguanglei";
	string s3="weichunlei is a sb";
	string s4="caoguanglei is a sb";
	checkAnagram(s1, s2);
	checkAnagram(s3, s4);
	replaceSpace(s1);
	replaceSpace(s3);
	cout<<s1<<"        "<<s3<<endl;
	system("PAUSE");
	return 0;
}

void replaceSpace(string& a)
{
	string replaced="";
	for(unsigned int i=0; i<a.length(); i++)
	{
		if(a[i]==' ')
			replaced+="%20";
		else
			replaced+=a[i];
	}
	a=replaced;
}

void checkAnagram(string& a, string& b)
{
	if(a.length()!=b.length())
	{
		cout<<"These two strings are not anagrams"<<endl;
		return;
	}
	vector<int> buffer(256);
	int n=a.length();
	for(int i=0; i<n; i++)
	{
		buffer[(int)a[i]]++;
		buffer[(int)b[i]]--;
	}
	for(int i=0; i<n; i++)
	{
		if(buffer[i]!=0)
		{
			cout<<"These two strings are not anagrams"<<endl;
			return;
		}
	}
	cout<<"These two strings are anagrams"<<endl;
	return;
}