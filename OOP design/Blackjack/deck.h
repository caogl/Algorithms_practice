#ifndef DECK_H
#define DECK_H
#include"player.h"

class Deck // all the cards available
{
public:
	Deck();
	~Deck(){};
	void issueCard(Player& player);
	void additionalCard(Player& player);
private:
	vector<Card> cards_available;	
};


#endif
