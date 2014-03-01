#include<iostream>
using namespace std;

int countComb(int target);
void countComb(int target, int currentSum, int quant, int& count);

int main()
{
	cout<<"There are totally "<<countComb(26)<<" ways of representing 26";
	return 0;
}

int countComb(int target)
{
	int count=0;
	int quant=25;
	int currentSum=0;
	countComb(target, currentSum, quant, count);
	return count;
}
void countComb(int target, int currentSum, int quant, int& count)
{
	if(currentSum>=target)
	{
		if(currentSum==target)
			count++;
		return;
	}
	if(quant>=25)
		countComb(target, currentSum+25, 25, count);
	if(quant>=10)
		countComb(target, currentSum+10, 10, count);
	if(quant>=5)
		countComb(target, currentSum+5, 5, count);
	if(quant>=1)
		countComb(target, currentSum+1, 1, count);

}
