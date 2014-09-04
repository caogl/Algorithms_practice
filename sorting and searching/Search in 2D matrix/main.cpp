// This is the version in "cracking the coding interview", not the leetcode one, the latter is very easy
#include<iostream>
#include<utility>
using namespace std;

pair<int, int> search(int a[][5], int m, int n, int x);

int main()
{
	int a[][5]={{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30}};
	pair<int, int> result=search(a, 5, 5, 10);
	cout<<"The number 10 locate in the position: "<<result.first<<" "<<result.second<<endl;
	result=search(a, 5, 5, 9);
	cout<<"The number 9 locate in the position: "<<result.first<<" "<<result.second<<endl;
	system("PAUSE");
	return 0;
}

pair<int, int> search(int a[][5], int m, int n, int x)
{
	int i=0, j=n-1;
	while(true)
	{
		if(a[i][j]==x)
			return make_pair(i, j);
		else if(a[i][j]>x)
			j--;
		else
			i++;
	}
}
