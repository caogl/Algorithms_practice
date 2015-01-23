// reference: http://blog.xiaohuahua.org/2015/01/01/leetcode-simplify-path/
/* example: /a/./b/../../c/e/../d/
 * output:  /c/d */

#include<iostream>
#include<string>
#include<stack>
using namespace std;

string simplifyPath(string path);

int main()
{
	string path="/a/./b/../../c/e/../d";
	string result=simplifyPath(path);	
	cout<<result<<endl;

	path="/.."; // test case (1)
	result=simplifyPath(path);	
	cout<<result<<endl;

	path="/..."; // test case (2)
	result=simplifyPath(path);	
	cout<<result<<endl;

	return 0;
}

string simplifyPath(string path)
{
	int n=path.size();
	stack<string> s;
	int start=1;
	for(int i=1; i<n; i++)
	{
		if(path[i]=='/')
		{
			string tmp=path.substr(start, i-start);
			if(tmp=="..") // cannot put these two if conditions together by "&&"!, easy error!!
			{
				if(!s.empty())	s.pop();
			}
			else if(tmp.size()>0 && tmp!=".") /* (1) first condition deals with "//" */
				s.push(tmp);
			start=i+1;
		}
	}
	
	/* (2) deal with the final word in the path, if not '/' */	
	string tmp=path.substr(start, n-start);
	if(tmp=="..")
	{
		if(!s.empty())	s.pop(); // check for test case (1), if .. from "/",, still keep in the root position 
	}
	else if(tmp.size()>0 && tmp!=".") /* (1) first condition deals with "//" */
		s.push(tmp);

	/*(3) deal with corner case that the final result is only the root "/" */
	if(s.empty())	return "/";

	string result;
	while(!s.empty())
	{
		result="/"+s.top()+result;
		s.pop();
	}
	return result;
}
