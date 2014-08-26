#include<iostream>
using namespace std;

int next(int x);
int previous(int x);
int count_one(int x);

int main()
{
    	int a = -976756;//(1<<31)+(1<<29);//-8737776;
    	cout<<next(a)<<" "<<previous(a)<<endl;
	return 0;
}

int next(int x)
{
	int max_int= ~(1<<31);
	int num=count_one(x);
	if(x==max_int)
		return -1;
	for(int i=(x+1); i<max_int; i++)
		if(count_one(i)==num)
			return i;
	return -1;
}

int previous(int x)
{
	int min_int=(1<<31);
	int num=count_one(x);
	if(x==min_int)
		return -1;
	for(int i=(x-1); i>min_int; i--)
		if(count_one(i)==num)
			return i;
	return -1;

}

int count_one(int x)
{
	int num=0;
	int num_bit=8*sizeof(x);
	for(int i=0; i<num_bit; i++)
	{
		if(x & 1)
			num++;
		x=(x>>1);
	}
	return num;
}
