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
        stack<int> stack1;
        int lasPos=0; // the valid start position
        int maxP=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
                stack1.push(i);
            else
            {
                if(stack1.size()==1) // the stack will be empty
                {
                    stack1.pop();
                    maxP=max(maxP, i-lasPos+1);
                }
                else if(stack1.size()>1) // will now more '(' from than valid start position
                {    
		    // must pop first to deal with if s="((()()"
                    stack1.pop();
                    maxP=max(maxP, i-stack1.top());
                }
                else // the stack is empty-> ')' cannot be a valid start position
                    lasPos=i+1;
            }
        }
        return maxP;
    }
