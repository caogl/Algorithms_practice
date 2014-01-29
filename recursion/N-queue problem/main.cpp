#include<iostream>
using namespace std;

void search(int *c, int dim, int r, int& count);
void print(int *c, int dim);

int main()
{
	int c[8];
	int r=0, count=0, dim=5;
	search(c, dim, r, count);
	cout<<"There are "<<count<<" possible solutions";
	system("PAUSE");
	return 0;
}

void print(int *c, int dim)
{
	for(int i=0; i<dim; i++)
	{
		for(int j=0; j<dim; j++)
		{
			if(c[i]==j)
				cout<<"1 ";
			else
				cout<<"0 ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void search(int *c, int dim, int r, int& count)
{
	if(r==dim)
	{
		count++;
		print(c, dim);
		return;
	}
	for(int i=0; i<dim; i++)
	{
		c[r]=i;
		bool prune=false;
		for(int j=0; j<r; j++)
		{
			if(c[j]==c[r] || abs(j-r)==abs(c[j]-c[r]))
			{
				prune=true;
				break;
			}
		}
		if(prune==false)
			search(c, dim, r+1, count);
	}
}
