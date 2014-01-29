#include <iostream>
#include<string>
using namespace std;

int search(string s[], int low, int high, string x)
{
	int mid=(low+high)/2;
	if(s[mid]==x)
		return mid;
	int t=mid;
	while(s[t]=="")
		t++;
	if(t>high)
		return search(s, low, mid-1, x);
	else 
	{
		if(s[t]>x)
			return search(s, low, mid-1, x);
		else
			return search(s, mid+1, high, x);
	}
}
int main(){
    string s[13] = {
        "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""
    };
    cout<<search(s, 0, 12, "ball")<<endl;
	system("PAUSE");
    return 0;
}