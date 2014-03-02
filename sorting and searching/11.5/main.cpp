#include <iostream>
#include<string>
using namespace std;

int search(string s[], int left, int right, string x)
{
	if(left>right)
	{
		return -1;
	}
	int mid=(left+right)/2;
	if(s[mid]=="")
	{
		int t=mid;
		while(t<right && s[++t]==""){}
		if(t==right)
		{
			return search(s, left, mid-1, x);
		}
		else
		{
			mid=t;
		}
	}
	if(s[mid]==x)
	{
		return mid;
	}
	else if(s[mid]>x)
		return search(s, left, mid-1, x);
	else
		return search(s, mid+1, right, x);
}

int main()
{
    string s[27] = {
        "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""
    };
    cout<<search(s, 0, 26, "ball")<<endl;
	cout<<search(s, 0, 26, "car")<<endl;
	cout<<search(s, 0, 26, "dad")<<endl;
	cout<<search(s, 0, 26, "chunlei")<<endl;
	system("PAUSE");
    return 0;
}
