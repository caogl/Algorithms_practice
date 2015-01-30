#include<iostream>
#include<string>
using namespace std;

string reverse(string& ordered);
//string reverseWord(const string& word);

int main()
{
	string ordered="cao guanglei loves wei chunlei";
	cout<<reverse(ordered);
	system("PAUSE");
	return 0;
}

string reverse(string& ordered)
{
	string result;
	string::size_type pos, lasPos;
	lasPos=ordered.find_last_not_of(" ", ordered.length()-1);
	pos=ordered.find_last_of(" ", lasPos);
	while(string::npos!=pos && string::npos!=lasPos)
	{
		result=result+ordered.substr(pos+1, lasPos-pos);
		result=result+" ";
		lasPos=ordered.find_last_not_of(" ", pos);
		pos=ordered.find_last_of(" ", lasPos);
	}
	result=result+ordered.substr(pos+1, lasPos-pos);
	return result;
}

/*
string reverseWord(const string& word)
{
	string result=word;
	int wordLength= word.length();
	for(int i=wordLength-1; i>=0; i--)
	{
		result[wordLength-1-i]=word[i];
	}
	return result;
}
