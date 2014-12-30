// reference: http://fisherlei.blogspot.com/2012/12/leetcode-next-permutation.html
/* case(1): 1-2-4-5-3   step1: index1=2, since from right to left, 4-5 is not ascending sequence, num[2]=4
 * 		        step2: index2=3, since from right to index1, 5 (num[3]=5) is the first elem greater than 4
 *	    1-2-5-4-3   step3: swap num[index1] and num[index2]
 *	    1-2-5-3-4   step4: reverse the elems after index1
 * case(2): 5-4-3-2-1   step1: from right to left, no elem pairs violate ascending sequence, reverse the whole vector
 *          1-2-3-4-5
 * case(3): 2-3-5-6-6-4   here we assume that there will be NO duplicate sequence
 *          	          so we DO NOT assume that 6-6 violate the ascending sequence from right to left, 5-6 first to violate
 *          2-3-6-4-5-6
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

void nextPermutation(vector<int> &num);
int main()
{
	vector<int> num={2, 3, 5, 6, 6, 4}; // case (3) ---> 2-3-6-4-5-6
	cout<<"Before reverse: ";
	for(int i=0; i<num.size(); i++)
		cout<<num[i]<<" ";
	nextPermutation(num);
	cout<<endl<<"After  reverse: ";
	for(int i=0; i<num.size(); i++)
		cout<<num[i]<<" ";

	return 0;
}

void nextPermutation(vector<int> &num)
{
        if(num.size()<=1)
            return;
	/* step1 */
        int index1=-1;
        for(int i=num.size()-2; i>=0; i--)
        {
            if(num[i]<num[i+1]) // deal with case(3), be careful here is < rather than <=
            {
                index1=i;
                break;
            }
        }
        if(index1==-1) // check case (2)
        {
            reverse(num.begin(), num.end());
            return;
        }
        
	/* step2 */
        int index2=-1;
        for(int i=num.size()-1; i>=0; i--)
        {
            if(num[i]>num[index1])
            {
                index2=i;
		/* step3 */
                swap(num[index1], num[index2]);
		/* step4 */
                reverse(num.begin()+index1+1, num.end()); // here it is index1 rather than index2 !!
                break;
            }
        }
}

