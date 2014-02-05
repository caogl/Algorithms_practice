#include <iostream>
#include<string>
using namespace std;

int search(string s[], int left, int right, string x)
{

	int mid=(left+right)/2;
	if(s[mid]==x)
		return mid;
	if(s[mid]=="")
	{
		int t=mid;
		while(s[t]=="")
		{
			t++;
			if(t>right)
				return search(s, left, mid-1, x);
		}
		mid=t;
		if(s[mid]==x)
			return mid;
	}
	if(x>s[mid])
		return search(s, mid+1, right, x);
	else
		return search(s, left, mid-1, x);
}
int main()
{
    string s[13] = {
        "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""
    };
    cout<<search(s, 0, 12, "ball")<<endl;
	system("PAUSE");
    return 0;
}
