// Write a method to generate a random number between 1 and 7, given a method that generates a random number between 1 and 5 (i.e., implement rand7() using rand5()).
// reference: http://hawstein.com/posts/19.10.html

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<map>
#include<climits>
using namespace std;

int rand5();
int rand7(); // given a random number generator which will generate number from 1 to a, generate random
			// number from 1 to b

int main()
{
	srand(time(NULL));

	map<int, int> map1;
	for(int i=1; i<=7; i++)
		map1[i]=0;
	for(int i=0; i<1000; i++)
	{
		int tmp=rand7();
		map1[tmp]++;
	}
	for(auto itr=map1.begin(); itr!=map1.end(); itr++)
	{
		cout<<itr->first<<" "<<itr->second<<endl;
	}
	return 0;
}

int rand5()
{
	return rand()%5+1;
}

int rand7()
{
	int x=INT_MAX;
	while(x>21)
	{
		x=5*(rand5()-1)+rand5(); // evely distributed between 1 and 25
	}
	return x%7+1;
}

