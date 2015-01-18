#include<vector>
#include<iostream>
using namespace std;

vector<int> plusOne(vector<int> &digits) 
{
        int extra=1;
        for(int i=digits.size()-1; i>=0; i--)
        {
            if(digits[i]+extra==10)
            {
                extra=1;
                digits[i]=0;
            }
            else
            {
                digits[i]=digits[i]+extra;
                extra=0; // don't forget this line, without this cannot pass cases (2) --> easy to bug!!
                break;
            }
        }
        if(extra==1)
            digits.insert(digits.begin(), 1);
        return digits;
}

int main()
{
	vector<int> vec1={9,9,9}; // case (1)
	vector<int> result=plusOne(vec1);
	for(int i=0; i<result.size(); i++)	cout<<result[i];
	cout<<endl;

	vector<int> vec2={1};
	result=plusOne(vec2); // case (2)
	for(int i=0; i<result.size(); i++)	cout<<result[i];
	cout<<endl;

}
