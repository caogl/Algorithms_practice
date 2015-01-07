#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> findMissingRanges(int A[], int n, int lower, int upper);
void addRange(vector<string>& result, int prev, int next);

int main()
{
	int A1[]={0,1,3,50,75};
	vector<string> result1=findMissingRanges(A1, 5, 0, 99);
	for(int i=0; i<result1.size(); i++)
		cout<<result1[i]<<" ";
	cout<<endl;

	int A2[]={};
	vector<string> result2=findMissingRanges(A2, 0, 0, 99);
	for(int i=0; i<result2.size(); i++)
		cout<<result2[i]<<" ";
	cout<<endl;

	/* time limit exceed for solution (2)*/
	int A3[]={-1000000000,-9999,0,1,2,10,100,1000,999999999,1000000000};
	vector<string> result3=findMissingRanges(A3, 10, -1000000000, 1000000000);
	for(int i=0; i<result3.size(); i++)
		cout<<result3[i]<<" ";
	cout<<endl;

	int A4[]={};
	vector<string> result4=findMissingRanges(A2, 0, 1, 1);
	for(int i=0; i<result4.size(); i++)
		cout<<result4[i]<<" ";
	cout<<endl;

	return 0;
}

/* solution(1): loop throught the array, time O(n) */
/* (a): special treatment of the first and last range
 * (b): not to include in the range A[i], previous need to +1
 * (c): n==0 or A is out of range by lower and upper, return the whole range, also take int consideration lower==upper
 */
vector<string> findMissingRanges(int A[], int n, int lower, int upper)
{
	vector<string> result;
	if(lower>upper)
		return result;

	if(n==0 || lower>A[n-1] || upper<A[0]) // notice the case that lower==upper!
	{
		if(upper!=lower)
		{
			string tmp=to_string(lower)+"->"+to_string(upper);
			result.push_back(tmp);
			return result;
		}
		else
		{
			result.push_back(to_string(lower));
			return result;
		}
	}
	
	// deal with head
	if(lower!=A[0])
		addRange(result, lower-1, A[0]);
	for(int i=1; i<n; i++)
		if(A[i]-A[i-1]>1)
			addRange(result, A[i-1], A[i]);
	// deal with tail
	if(upper>A[n-1])
		addRange(result, A[n-1], upper+1);
	
	return result;
}

void addRange(vector<string>& result, int prev, int next)
{
	if(next-prev==2)
		result.push_back(to_string(prev+1));
	else
	{
		string tmp=to_string(prev+1)+"->"+to_string(next-1);
		result.push_back(tmp);
	}
}



/* solution (2): loop through the range, time O(upper-lower) */
/*
vector<string> findMissingRanges(int A[], int n, int lower, int upper)
{
	vector<string> result;
	int index=0;
	int prev=lower-1; // important initialization
	for(int next=lower; next<=upper && index<n ; next++)
	{
		if(next==A[index])
		{
			if(next-prev>1)
				addRange(result, prev, next);
			prev=next;
			index++;
		}
	}

	if(A[n-1]!=upper)
		addRange(result, prev, upper+1);

	return result;
}

void addRange(vector<string>& result, int prev, int next)
{
	if(next-prev==2)
		result.push_back(to_string(prev+1));
	else
	{
		string tmp=to_string(prev+1)+"->"+to_string(next-1);
		result.push_back(tmp);
	}
}
*/
