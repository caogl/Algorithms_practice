/* two passes: (1) first pass: ajust all the ascending sequence
 * 	       (2) second pass: adjust all the descending sequence */

#include<vector>
#include<iostream>
using namespace std;

int candy(vector<int> &ratings);

int main()
{
	vector<int> ratings={3,2,1,2,3,4,3,2,3};
	// after first pass: 1 1 1 2 3 4 1 1 2
	// after second pass:3 2 1 2 3 4 2 1 2

	for(int i=0; i<ratings.size(); i++)
		cout<<ratings[i]<<" ";
	cout<<endl;
	cout<<candy(ratings)<<endl;

	vector<int> ratings1={1,2,6,5,4,3};
	// after first pass:  1 2 3 1 1 1
	// after second pass: 1 2 4 3 2 1 

	for(int i=0; i<ratings1.size(); i++)
		cout<<ratings1[i]<<" ";
	cout<<endl;
	cout<<candy(ratings1)<<endl;
	return 0;
}

int candy(vector<int> &ratings)
{
        if(ratings.size()==0)
            return 0;
        vector<int> candy(ratings.size(), 1);
	// all the non-decreasing sequence are now correct and start from 1
        for(int i=1; i<ratings.size(); i++)
        {
            if(ratings[i]>ratings[i-1])
                candy[i]=candy[i-1]+1;
        }

	// adjust the decreasing sequence
        for(int i=ratings.size()-1; i>=1; i--)
        {
            if(ratings[i]<ratings[i-1] && candy[i]>=candy[i-1]) // the seond if condition is important!
                candy[i-1]=candy[i]+1;
        }
	
        int result=0;
        for(int i=0; i<candy.size(); i++)
            result+=candy[i];
        return result;
}
