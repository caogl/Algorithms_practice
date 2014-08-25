#include"deck.h"

Deck::Deck()
{
	vector<int> temp(52);
	for(int i=0; i<52; i++)
		temp[i]=i+1;
	random_shuffle(temp.begin(), temp.end());

	for(int i=0; i<52; i++)
	{
		Card card(temp[i]);
		cards_available.push_back(card);
	}
}

void Deck::issueCard(Player& player)
{
	if(cards_available.size()<2)
	{
		cout<<"Not enough cards to play the game"<<endl;
		exit(1);
	}

	// issue two cards initially
	player.add(cards_available.back());
	cards_available.pop_back();
	player.add(cards_available.back());
	cards_available.pop_back();
}

void Deck::additionalCard(Player& player)
{
	// As long as the player is not busted and the player wants to hit, add more card
	while(!player.isBusted() && player.hit())
	{
		if(cards_available.size()<1)
		{
			cout<<"Not enough cards to play the game"<<endl;
			exit(1);
		}
		player.add(cards_available.back());
		cards_available.pop_back();
		player.showCards();
		cout<<endl;
	}
}
