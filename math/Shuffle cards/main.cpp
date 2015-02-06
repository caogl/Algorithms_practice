// reference: http://www.hawstein.com/posts/20.2.html
/* 我们先假设一个5维数组：1，2，3，4，5。如果第1次随机取到的数是4， 那么我们希望参与第2次随机选取的只有1，2，3，5。
   既然4已经不用， 我们可以把它和1交换，第2次就只需要从后面4位(2,3,1,5)中随机选取即可。
   同理， 第2次随机选取的元素和数组中第2个元素交换，然后再从后面3个元素中随机选取元素， 依次类推。*/

#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;

void shuffle(vector<int>& cards)
{
	int n=cards.size();
	for(int i=0; i<n; i++)
	{
		/* swap the indexes, not actual card */
		int j=rand()%(n-i)+i;
		swap(cards[i], cards[j]);
	}
}

int main()
{
	srand((unsigned)time(0));
	vector<int> cards(52);
	for(int i=0; i<52; i++)
		cards[i]=i+1;
	shuffle(cards);
	cout<<"After the shuffle: "<<endl;
	for(int i=0; i<52; i++)
		cout<<cards[i]<<" ";
	return 0;
}
