#include<iostream>
#include<vector>
using namespace std;

void transpose(int image[][4], int dim);
void swap(char& a, char& b);
void zerolize(int image[][4], int dim); // Notice that this function runs in O(n^2) rather than O(n^4) time

int main()
{
	int a[4][4]={{1,2,3,4}, {5,6,7,8}, {9,10,11,12},{13,14,15,16}};
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	transpose(a, 4);
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	int b[4][4]={{1,2,3,4}, {5,0,7,8}, {9,10,11,12},{13,14,15,0}};
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
			cout<<b[i][j]<<" ";
		cout<<endl;
	}
	zerolize(b, 4);
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
			cout<<b[i][j]<<" ";
		cout<<endl;
	}
	system("PAUSE");
	return 0;
}

void swap(int& a, int& b)
{
	int c=a;
	a=b;
	b=c;
}

void transpose(int image[][4], int dim)
{
	for(int i=0; i<dim; i++)
	{
		for(int j=i; j<dim; j++)
		{
			swap(image[i][j], image[j][i]);
		}
	}
	for(int i=0; i<dim; i++)
	{
		for(int j=0; j<dim; j++)
			swap(image[i][j], image[dim-i-1][j]);
	}
}

void zerolize(int image[][4], int dim)
{
	vector<bool> row;
	vector<bool> col;
	row.assign(dim, false);
	col.assign(dim, false);
	for(int i=0; i<dim; i++)
	{
		for(int j=0; j<dim; j++)
		{
			if(image[i][j]==0)
			{
				row[i]=true;
				col[j]=true;
			}
		}
	}
	for(int i=0; i<dim; i++)
	{
		for(int j=0; j<dim; j++)
		{
			if(row[i]==true || col[j]==true)
				image[i][j]=0;
		}
	}

}