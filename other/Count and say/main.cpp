#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string countAndSay(int n);

int main()
{
	string result1=countAndSay(1);
	string result2=countAndSay(2);
	string result3=countAndSay(3);
	string result4=countAndSay(4);
	string result5=countAndSay(5);
	string result6=countAndSay(6);
	cout<<result1<<" "<<result2<<" "<<result3<<" "<<result4<<" "<<result5<<" "<<result6<<endl;
	return 0;
}

string countAndSay(int n) 
{
        string result="1";
        for(int i=1; i<n; i++)
        {
            ostringstream ss;
            char say=result[0];
            int count=0;
            for(int j=0; j<result.size(); j++)
            {
                if(result[j]==say)
                    count++;
                else
                {
                    ss<<count<<say;
                    say=result[j];
                    count=1;
                }
            }
            ss<<count<<say;
            result=ss.str();
        }
        return result;
}
