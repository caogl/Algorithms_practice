#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

struct stringComp
{
	bool operator()(const string& s1, const string& s2)
	{
		string ss1=s1;
		string ss2=s2;
		sort(ss1.begin(), ss1.end());
		sort(ss2.begin(), ss2.end());
		return(ss1<ss2);
	}
};
int main()
{
	stringComp comp;
	string s[]={"axyz","gf","abc","yzax","bac","zyxa","fg"};
	sort(s, s+7, comp); // Notice the expression for the first and second 
	                    //parameter in the sort when the object is an array!!!
	                    //Also notice the number of the second index
	for(int i=0; i<7; i++)
		cout<<s[i]<<" ";
	cout<<endl;
	system("PAUSE");
    return 0;
}