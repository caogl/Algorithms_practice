// reference: https://oj.leetcode.com/discuss/18704/a-concise-c-version

#include<iostream>
#include<string>
using namespace std;

int compareVersion(string version1, string version2);

int main()
{
	cout<<compareVersion("1.0.0.0", "1")<<endl; // 0
	cout<<compareVersion("1.0.0.2", "1.0.1.0")<<endl; // -1	
	cout<<compareVersion("1.0.0.3", "1.0.0.3")<<endl; // 0
	cout<<compareVersion("1.1.0.3", "1.1.0.3.2")<<endl; // -1

	return 0;
}

int compareVersion(string version1, string version2)
{
        int pos1 = 0, pos2=0; 
	int v1, v2;
        string delimiter = ".";
        pos1 =version1.find(delimiter, 0); 
        pos2 =version2.find(delimiter, 0);
        if(pos1>=0) v1 = stoi(version1.substr(0,pos1));
        else	v1=stoi(version1);
        if(pos2>=0) v2 = stoi(version2.substr(0,pos2));
        else	v2=stoi(version2);
        
        if(v1==v2)
	{
        	if(pos1<0 && pos2<0) // reached the end of the position 
                	return 0;

		if(pos1>=0)	version1=version1.substr(pos1+1, version1.size()-1-pos1);
	    	else	version1="0";
		if(pos2>=0)	version2=version2.substr(pos2+1, version2.size()-1-pos2);
	    	else	version2="0";

        	return compareVersion(version1, version2);
        }
        else if(v1>v2)	return 1;
	else	return -1;
}
