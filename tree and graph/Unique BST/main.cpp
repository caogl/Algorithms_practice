#include<iostream>
#include<vector>
using namespace std;

int numTrees(int n)
{
        if(n==0 || n==1)
            return 1;
        
        // base
        vector<int> vec(n+1, 0);
        vec[0]=1;
        vec[1]=1;

        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<i; j++)
                vec[i]+=vec[j]*vec[i-j-1];
        }
        return vec[n];
}

int main()
{
	cout<<"The unique BST for 3 node is: "<<numTrees(3)<<endl;
	return 0;
}
