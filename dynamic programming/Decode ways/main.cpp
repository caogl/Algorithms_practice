#include<string>
#include<iostream>
using namespace std;

/* dp: for substring s[1:i], the number of decode ways depend on the decode ways of s[1:(i-1)] and s[1:(i-2)]
 * (1) if s[i]==0 and s[i-1]==1 or 2, then only s[i] is a valid number, no new number added else,
 *     the decode ways of s[1:i] is same as s[1:(i-1)]
 * (2) if s[i-1]==1 or 2, then s[i-1]+s[i] is a valid number, also s[i] is valid, so decode ways of s[1:i]=decode
 *     ways of s[1:(i-1)] plus s[i:(i-2)]
 * (3) for other conditions, decode ways same as that of s[i-1]
*/

int numDecodings(string s);

int main()
{	
	string s1="102";
	string s2="1251";
	string s3="3121402";
	cout<<"The number of ways to decode "<<s1<<" is: "<<numDecodings(s1)<<endl;
	cout<<"The number of ways to decode "<<s2<<" is: "<<numDecodings(s2)<<endl;
	cout<<"The number of ways to decode "<<s3<<" is: "<<numDecodings(s3)<<endl;

	return 0;
}

int numDecodings(string s)
{
        if(s.size()==0)
            return 0;
        int dp[s.size()+1];
        dp[0]=1;
        if(s[0]!='0')
            dp[1]=1;
        else
            dp[1]=0;
	string s1=" "+s;
        for(int i=2; i<=s.size(); i++) // notice the index!!!!
        {
	    if(s1[i]=='0')
	    {
		if(s1[i-1]=='1' || s1[i-1]=='2')
			dp[i]=dp[i-2];
		else
			return 0; //no way to decode
	    }
            else if(s1[i-1]=='1' || (s1[i-1]=='2' && s1[i]>'0' && s1[i]<='6'))
	    {
                dp[i]=dp[i-1]+dp[i-2];
	    }
            else
	    {
                dp[i]=dp[i-1];
	    }
        }
        
        return dp[s.size()];
}
