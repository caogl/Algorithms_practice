#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
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
	string a1=a;
	string b1=b;
	sort(a1.begin(), a1.end());
	sort(b1.begin(), b1.end());
	if(a1.compare(b1)==0)
		cout<<a<<" and "<<b<<" are anagram"<<endl;
	else
		cout<<a<<" and "<<b<<" are not anagram"<<endl;
	return;
}
