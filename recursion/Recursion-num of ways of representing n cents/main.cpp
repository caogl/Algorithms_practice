#include<iostream>
using namespace std;

void countComb(int sum, int target, int quant, int& count);

int main()
{
	int sum=0, target=26, quant=25, count=0;
	countComb(sum, target, quant, count);
	cout<<"The total possible combination is: "<<count<<endl;
	system("PAUSE");
	return 0;
}

void countComb(int sum, int target, int quant, int& count)
{
	if(sum>=target)
	{
		if(sum==target)
			count++;
		return;
	}
	if(quant>=25)
		countComb(sum+25, target, 25, count);
	if(quant>=10)
		countComb(sum+10, target, 10, count);
	if(quant>=5)
		countComb(sum+5, target, 5, count);
	countComb(sum+1, target, 1, count);
}