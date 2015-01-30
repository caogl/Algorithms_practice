// reference: leetcode cleancode official handbook
/* The input string does not contain leading or trailing spaces and the words are always
separated by a single space.
Could you do it in-place without allocating extra space? */

#include<iostream>
#include<string>
using namespace std;

void reverse(string& str);
void reverse(string& str, int left, int right);

int main()
{
	string str="cao guanglei loves wei chunlei";
	reverse(str);
	cout<<str<<endl;
	return 0;
}

void reverse(string& str)
{
	reverse(str, 0, str.size()-1);
	int lasPos, pos;
	lasPos=str.find_first_not_of(" ", 0);
	pos=str.find_first_of(" ", lasPos);
	while(lasPos>=0 && pos>=0)
	{
		reverse(str, lasPos, pos-1);
		lasPos=str.find_first_not_of(" ", pos);
		pos=str.find_first_of(" ", lasPos);
	}
	reverse(str, lasPos, str.size()-1); // important line, the 3rd parameter cannot be pos! (-1 now)
}

void reverse(string& str, int left, int right)
{
	for(int i=0; i<=(right-left)/2; i++) // must be "<=" here !!!
		swap(str[left+i], str[right-i]);
}
