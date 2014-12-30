#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/* recursive solution, run time
 * T(n) = n*T(n-1) + O(n)
   If G(n) = T(n)/n! we get
   G(n) = G(n-1) + O(1/(n-1)!)
   which gives G(n) = O(n).
   Thus T(n) = O(n*n!).
*/
string kthPermute(int n, int k);
void help(int n, int k, string& result, string& tmp, vector<bool>& visited, int& rank);

/* O(n) time, mathematics */
string getPermutation(int n, int k);

int main()
{
	cout<<"The 54495th permutation when n=9 is: "<<kthPermute(9, 54494)<<endl;
	cout<<"The 54495th permutation when n=9 is: "<<getPermutation(9, 54494)<<endl;
	return 0;
}

string kthPermute(int n, int k)
{
	vector<bool> visited(n, false);
	string tmp="";
	string result="";
	int rank=0;
	help(n, k, result, tmp, visited, rank);
	return result;
}

void help(int n, int k, string& result, string& tmp, vector<bool>& visited, int& rank)
{
	if(tmp.size()==n)
	{
		rank++;
		if(rank==k)
			result=tmp;
		return;
	}
	for(int i=0; i<n; i++)
	{
		if(visited[i]){}
		else
		{
			visited[i]=true;
			tmp+=to_string(i+1);
			help(n, k, result, tmp, visited, rank);
			tmp=tmp.substr(0, tmp.size()-1);
			visited[i]=false;
		}
	}
}

string getPermutation(int n, int k)
{
	vector<int> factorial(n);
	vector<int> digits(n);
	int fac=1;
	
	/* logic: starting with any digit, there are (n-1)! combinations, then can calculate the first digit...follow this logic 
         * so for the 1st position, should store (n-1)!......n-1 th and nth store 1 
         */
	for(int i=1; i<=n; i++)
	{
		factorial[i-1]=fac;
		digits[i-1]=i;
		fac=fac*i;
	}
	reverse(factorial.begin(), factorial.end());

	k--; // very important, because count actually start from 0!!! 
	     // if not, for k=1 to (n-1)!, the first sequence char should be 0
	     // but then for (n-1)! , (n-1)!/[(n-1)!]=1, the first sequence char is 1 !!!
	string result;
	for(int i=0; i<n; i++)
	{
		int digit=k/factorial[i];
		result=result+to_string(digits[digit]);
		digits.erase(digits.begin()+digit);
		k=k%factorial[i];
	}
	return result;
}
