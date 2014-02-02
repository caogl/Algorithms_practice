#include<iostream>
using namespace std;

void outputBracket(char *out, int left, int right, int total, bool isLeft, int num);

int main()
{
	char out[6];
	outputBracket(out, 1, 0, 1, true, 3); // Notice here the starting value for right must be -1, or there will be one less right bracket
	system("PAUSE");
	return 0;
}

void outputBracket(char *out, int left, int right, int total, bool isLeft, int num)
{
	// check that the number of left barcket is greater than the number of right bracket, left bracket does not
	// exceed the possible maximum value
	if(right>left || left>num)
		return;
	if(isLeft==true)
		out[total-1]='{';
	else
		out[total-1]='}';
	if(right==num)
	{
		for(int i=0; i<total; i++)
			cout<<out[i];
		cout<<endl;
	}
	else
	{
		outputBracket(out, left+1, right, total+1, true, num);
		outputBracket(out, left, right+1, total+1, false, num);
	}
}
