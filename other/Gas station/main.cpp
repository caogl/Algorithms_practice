// Reference: http://www.2cto.com/kf/201401/275467.html

#include <iostream>
#include <vector>
using namespace std;
 
int canCompleteCircuit(vector<int> &gas, vector<int> &cost);
 
int main() 
{
    int result;
    vector<int> gas =  {4,0,5,6,3,2};
    vector<int> cost = {1,2,6,8,1,2};
    result = canCompleteCircuit(gas,cost);
    cout<<"Result is: "<<result<<endl;
    return 0;
}

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
	int total=0;
	int sum=0;
	int start=0;
	for(int i=0; i<gas.size(); i++)
	{
		total+=(gas[i]-cost[i]);
		sum+=(gas[i]-cost[i]);
		if(sum<0)
		{
			start=i+1;
			sum=0;
		}
	}
	if(total<0)
		return -1;
	else
		return start;
}
