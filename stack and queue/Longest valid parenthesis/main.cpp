#include<string>
#include<stack>
#include<string>
#include<iostream>
using namespace std;

int longestValidParentheses(string s);

int main()
{
	string s1="(()(((()";
	string s2="()(()";
	string s3="(()(((()()())))";

	cout<<"The number of longest valid parenthesis in s1 is: "<<longestValidParentheses(s1)<<endl;
	cout<<"The number of longest valid parenthesis in s2 is: "<<longestValidParentheses(s2)<<endl;
	cout<<"The number of longest valid parenthesis in s2 is: "<<longestValidParentheses(s3)<<endl;

	return 0;
}

int longestValidParentheses(string s) 
{
        int last=-1; // last invalid position impossible to start with
        int maxLen=0;
        stack<int> stack1;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
                stack1.push(i);
            else 
            {
                if(!stack1.empty())
                {
                    stack1.pop();
                    if(stack1.empty())
                        maxLen=max(maxLen, i-last);
                    else
                        maxLen=max(maxLen, i-stack1.top());
                }
                else
                    last=i;
            }
        }
        return maxLen;
}
