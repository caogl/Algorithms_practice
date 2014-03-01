#include<iostream>
#include<string>
#include<vector>
using namespace std;

void printP(int num); // number of parenthesis
void printP(string& out, int num, int left, int right);

int main()
{
	printP(3);
	return 0;
}

void printP(int num)
{
	string out;
	printP(out, num, 0, 0);
}

void printP(string& out, int num, int left, int right)
{
	if(left<right || left>num)
	{
		return;
	}
	if(out.size()==num*2)
	{
		cout<<left<<" "<<right<<" "<<out<<endl;
		return;

	}
	out+='{';
	left++;
	printP(out, num, left, right);
	left--;
	out=out.substr(0, out.size()-1);
	out+='}';
	right++;
	printP(out, num, left, right);
	right--;
	out=out.substr(0, out.size()-1);
}
