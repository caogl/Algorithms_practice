// reference: http://fisherlei.blogspot.com/2013/01/leetcode-add-binary.html
#include<iostream>
#include<string>
#include<algorithm> // for std::reverse && std::min
#include<sstream>
using namespace std;

string addBinary(string a, string b) 
{
        if(a=="0")  return b;
        if(b=="0")  return a;
        
        string result;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n=max(a.size(), b.size());
        int carry=0;
        for(int i=0; i<n; i++)
        {
            int tmp1=i<a.size()?    a[i]-'0':0;
            int tmp2=i<b.size()?    b[i]-'0':0;
            int val=(tmp1+tmp2+carry)%2;
            carry=(tmp1+tmp2+carry)/2;	    
            result+=(val+'0');
        } 
        if(carry)   result+="1";
        reverse(result.begin(), result.end());
        return result;
}
    
int main()
{
	string a="1";
	string b="1";
	cout<<addBinary(a, b)<<endl;

	string c="10001011";
	string d="101110";
	cout<<addBinary(c, d)<<endl;

	return 0;
}
