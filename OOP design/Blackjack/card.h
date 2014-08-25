#ifndef CARD_H
#define CARD_H	
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//enum Suit{Spade(0), Heart, Club, Diamond};
//enum Rank{Ace(1), Two, Three, Four, Seven, Eight, Nine, Ten, Jack, Queen, King};

class Card // individual card in poker
{
public:
	Card(){};
	Card(int num); // generate the card from random number
	~Card(){};
	int getValue();
	friend string getCardInfo(const Card& card, bool visible);
private:
	int cardNum;
};

#endif
