#include<iostream>
#include<string>
using namespace std;

bool checkRotation(string& s1, string& s2);

int main()
{
	string s1="caoguangleilovesweichunlei";
	string s2="weichunleicaoguangleiloves";
	if(checkRotation(s1, s2))
		cout<<"s2 is a rotation of s1"<<endl;
	else
		cout<<"s2 is not a rotation of s1"<<endl;;
	s1="caoguangleiissb";
	s2="weichunleiissb";
	if(checkRotation(s1, s2))
		cout<<"s2 is a rotation of s1";
	else
		cout<<"s2 is not a rotation of s1";
	system("PAUSE");
	return 0;
}

bool checkRotation(string& s1, string& s2)
{
	s1+=s1;
	if(s1.find(s2)==string::npos)
		return false;
	else 
		return true;
}
