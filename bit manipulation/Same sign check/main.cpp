#include<iostream>
using namespace std;

bool sameSign(int x, int y)
{
	return ((x^y)>=0); // bit operator has low priority, should be put in ()!!!, or will produce different result;
}

int main()
{
	cout<<sameSign(3,-100)<<endl<<sameSign(-9, -99)<<endl<<sameSign(1000, 2)<<endl;
	return 0;
}
