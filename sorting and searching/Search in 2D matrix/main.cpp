// Given a matrix in which each row and each column is sorted, write a method to find an element in it.
// 让我们来看看右上角， 设要查找的元素为x，比如x比右上角元素5大，那么它也会比第一行的其它元素都大。 
// 因此可以去掉第一行；如果它比右上角元素小，那么它也会比最后一列的元素都小， 因此可以去掉最后一列；
// 然后这样不断地比下去，只需要O(m+n)的时间就查找完。
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
