// reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-text-justification.html
/* example:
 * words={"cao", "guanglei", "loveslovesloves", "wei", "chunlei"}
 * cao     guanglei
   loveslovesloves 
   wei chunlei 
   words={"This", "is", "an", "example", "of", "text", "justification."}
   This    is    an
   example  of text
   justification
*/
  
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> fullJustify(vector<string> &words, int L);
string createLine(vector<string> &words, int L, int start, int end, int totalLen, bool lastLine);

int main()
{
	vector<string> words={"cao", "guanglei", "loveslovesloves", "wei", "chunlei"};
	vector<string> result=fullJustify(words, 16);
	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<endl;
	cout<<endl;
	vector<string> words1={"This", "is", "an", "example", "of", "text", "justification."};
	result=fullJustify(words1, 16);
	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<endl;
	cout<<endl;

	return 0;
}

vector<string> fullJustify(vector<string> &words, int L)
{
	vector<string> result;
	int n=words.size();
	int totalLen=0; // the length summation of all the words in current line
	int start=0; // the first word in the line
	for(int i=0; i<n; i++)
	{
		/* the condition in if an important trick, cannot maintain the siz of spaces
 		   because if the added word is first one, no space needed, others one space */
		if(totalLen+i-start+words[i].size()>L) // word[i-1] is the end of the line
		{
			result.push_back(createLine(words, L, start, i-1, totalLen, false));
			start=i;
			totalLen=words[i].size();
		}
		else // word[i] can be added to the current line;
			totalLen+=words[i].size();
	}
	result.push_back(createLine(words, L, start, n-1, totalLen, true));
	return result;
}

string createLine(vector<string> &words, int L, int start, int end, int totalLen, bool lastLine)
{
	string result=words[start];
	if(start==end || lastLine) // at most one space between each word
	{
		for(int i=start+1; i<=end; i++)
			result.append(" "+words[i]);
		int extraSpace=L-result.size();
		result.append(extraSpace, ' ');
	}
	else
	{
		int k=(L-totalLen)/(end-start);
		int m=(L-totalLen)%(end-start);
		for(int i=start+1; i<=end; i++)
		{
			int numSpace=k+((i-start)<=m);
			result.append(numSpace, ' ');
			result.append(words[i]);
		}
	}
	return result;
}


// redo 01/14/2015
vector<string> fullJustify(vector<string> &words, int L) 
{
        vector<string> result;
	if(words.size()==0)
		return result;
        int start=0; 
        int totalLen=words[0].size(); //initialized to 0, then error and easy to make!
        			      //if like this, words[0] goes to else and add one addition " "
        int n=words.size();
        for(int i=1; i<n; i++)
        {
            if(totalLen+words[i].size()>=L)
            {
                add(words, result, start, i-1, totalLen, false, L);
                totalLen=words[i].size();
                start=i;
            }
            else    totalLen+=words[i].size()+1;
        }
        add(words, result, start, n-1, totalLen, true, L);
        return result;
}
    
void add(vector<string>& words, vector<string>& result, int start, int end, int totalLen, bool lastLine, int L)
{
        if(start>end)   return;
        string s=words[start];
        if(start==end || lastLine)
        {
            for(int i=start+1; i<=end; i++)
                s+=(" "+words[i]);
            s.append(L-totalLen, ' ');
        }
        else
        {
            int n=(L-totalLen)/(end-start);
            int m=(L-totalLen)%(end-start);
            for(int i=start+1; i<=end; i++)
            {                
		s.append(1+n+(i-start<=m), ' ');
                s+=words[i];
            }
        }
        result.push_back(s);
}
