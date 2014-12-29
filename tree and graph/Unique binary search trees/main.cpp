// reference: http://fisherlei.blogspot.com/2013/03/leetcode-unique-binary-search-trees.html
// use the property of BST, all the left nodes must be smaller than the current node while right nodes bigger
// then get the dp function: dp[i]=dp[j]*dp[i-j-1]

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
