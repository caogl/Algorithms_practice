// reference: http://www.hawstein.com/posts/20.2.html

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
