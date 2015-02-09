#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


/* solution (1): maintain circular buffer, while use string as hash key, memory limit exceed
 * ------------> if using string as hash key, each char actually has 256 possibilities!
 *               allocated space for hash function of strings char by char, more hash spaces than really needed !!! */
/* solution (2): maintain circular buffer, while use int as hash key */
vector<string> findRepeatedDnaSequences(string s);
int strToInt(string s);
string intToStr(int n);

int main()
{
	string s="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	vector<string> vec=findRepeatedDnaSequences(s);
	for(int i=0; i<vec.size(); i++)
		cout<<vec[i]<<endl;
	return 0;
}


vector<string> findRepeatedDnaSequences(string s)
{
	vector<string> result;
        if(s.size()<10) return result;
	
        string window=s.substr(0, 10);
        unordered_map<int, bool> hashMap;
	int hashKey=strToInt(window);
	for(int i=10; i<s.size(); i++)
	{
		if(hashMap.find(hashKey)!=hashMap.end())	hashMap[hashKey]=true;
		else	hashMap[hashKey]=false;
		window=window.substr(1);
		window+=s[i];
		hashKey=strToInt(window);
	}
	if(hashMap.find(hashKey)!=hashMap.end())        hashMap[hashKey]=true;
        else    hashMap[hashKey]=false;
	
	for(auto itr=hashMap.begin(); itr!=hashMap.end(); itr++)
		if(itr->second)
			result.push_back(intToStr(itr->first));
	return result;
}

int strToInt(string s)
{
	int result=0;
	for(int i=0; i<10; i++)
	{
		if(s[i]=='T')	result=result | 3;
		else if(s[i]=='G')	result=result | 2;
		else if(s[i]=='C')	result=result | 1;
		
		result=(result<<2);
	}
	return (result>>2);
}

string intToStr(int n)
{
	string result;
	int mask=3;
	for(int i=0; i<10; i++)
	{
		int tmp=(mask & n);
		if(tmp==3)	result="T"+result;
		else if(tmp==2)	result="G"+result;
		else if(tmp==1)	result="C"+result;
		else		result="A"+result;
		n>>=2;
	}
	return result;
}

/* solution (1)
vector<string> findRepeatedDnaSequences(string s) 
{
        vector<string> result;
        if(s.size()<10) return result;
        
        unordered_map<string, bool> hashMap;
        string tmp=s.substr(0, 10);
        for(int i=10; i<s.size(); i++)
        {
            if(hashMap.find(tmp)!=hashMap.end())    hashMap[tmp]=true;
            else    hashMap[tmp]=false;
            tmp=tmp.substr(1);
            tmp+=s[i];
        }
        if(hashMap.find(tmp)!=hashMap.end())    hashMap[tmp]=true;
        else    hashMap[tmp]=false;
        
        for(auto itr=hashMap.begin(); itr!=hashMap.end(); itr++)
            if(itr->second)
                result.push_back(itr->first);
        return result;
} */
