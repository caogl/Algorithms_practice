// reference: http://fisherlei.blogspot.com/2012/12/leetcode-gray-code.html
/*
[解题思路]
看到这个题时，首先做了一个模拟，当n=3时，gray code应该是
000
001
011
010
110
100
101
111
看了半天，也没看出来什么规律。后来上网一查GrayCode(http://en.wikipedia.org/wiki/Gray_code)才发现原来推导的gray code顺序错了。第六个应该是111。
n=3时，正确的GrayCode应该是
000
001
011
010
110
111 //如果按照题意的话，只是要求有一位不同，这里也可以是100
101
100

这样的话，规律就出来了，n=k时的Gray Code，相当于n=k-1时的Gray Code的逆序 加上 1<<k。
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> grayCode(int n);
void printVec(const vector<int>& vec);

int main()
{
	vector<int> result=grayCode(5);
	printVec(result);
	return 0;
}

void printVec(const vector<int>& vec)
{
	for(int i=0; i<vec.size(); i++)
		cout<<vec[i]<<" ";
	cout<<endl; 
}

vector<int> grayCode(int n)
{
	vector<int> result;
	result.push_back(0);
	for(int i=0; i<n; i++) // iteratively, generate vector<int> for length=1,2, 3...n
	{
		int highestBit=(1<<i);
		for(int j=result.size()-1; j>=0; j--)
			result.push_back(highestBit+result[j]);
	}
	return result;
}


