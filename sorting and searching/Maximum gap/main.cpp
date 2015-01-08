// reference: http://yucoding.blogspot.com/2014/12/leetcode-question-maximum-gap.html
// radix sort analysis: http://www.geeksforgeeks.org/radix-sort/

/* idea: using radix sort in O(N) time, which requires the use of counting sorting for each digit from the least significant digit to most
 *       since counting sort is stable, radix sort succeed
 * {demo}:
 * input:	 [2,113,504,55,39,98,8,79]
 * counting sort: 
 *		 Sort 1st digit: A = [2, 113, 504, 55, 36, 98, 8, 79]
 *		 Sort 2nd digit: A = [2, 504, 8, 113, 36, 55, 79, 98]
 *		 Sort 3rd digit: A = [2, 8, 36, 55, 79, 98, 113, 504]
 *
 * {demo for counting sorting on least significant digit}:
 * 		digitCount: [0,0,1,1,1,1,0,0,2,2]-->[0,0,1,2,3,4,4,4,6,8], then:
 *			[2,113,504,55,39,98,8,79]-->[2,113,504,55,36,98,8,79]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maximumGap(vector<int>& num);
void radixSort(vector<int>& num);
void countingSort(vector<int>& num, int digit);

int main()
{
	vector<int> num={2,113,504,55,39,98,8,79};
	cout<<maximumGap(num)<<endl;
	return 0;
} 

int maximumGap(vector<int>& num)
{
	if(num.size()<2)
		return 0;
	radixSort(num);
	int result=num[1]-num[0];
	for(int i=2; i<num.size(); i++)
		result=max(result, num[i]-num[i-1]);
	return result;
}

void radixSort(vector<int>& num)
{
	int maxV=*max_element(num.begin(), num.end());
	for(int digitNum=1; maxV/digitNum>0; digitNum*=10)
		countingSort(num, digitNum);
	cout<<endl;
}

void countingSort(vector<int>& num, int digitNum)
{
	vector<int> digitCount(10, 0);
	vector<int> buffer(num.size());
	for(int i=0; i<num.size(); i++)
		digitCount[(num[i]/digitNum)%10]++;
	for(int i=1; i<digitCount.size(); i++)
		digitCount[i]+=digitCount[i-1];

	/* must follow this order !!!*/
	for(int i=num.size()-1; i>=0; i--)
	{
		int orderedIndex=digitCount[(num[i]/digitNum)%10];
		buffer[orderedIndex-1]=num[i]; // notice the -1 here!
		digitCount[(num[i]/digitNum)%10]--;
	}
	num=buffer;

}

