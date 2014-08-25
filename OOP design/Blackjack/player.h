#ifndef PLAYER_H
#define PLAYER_H
#include"card.h"

class Player // abstract class
{
public:
	Player();
	~Player(){};
	int getScore(); // get the score for each player
	void add(Card& card); // give a new card to a player
	virtual void clear(); // clear all the cards at hand for a play and make socre 0 to start a new game
	virtual bool hit() = 0; // return that the player want/should give another hit or not
	virtual void showCards() = 0; // display the card information and total score for the players
	bool isBusted(); // return whether the player has been busted or not 
protected:
	vector<Card> cardsNow; // the cards at hand for each player
	int sum; 
};

class Home : public Player // the banker
{
public:
	Home();
	~Home(){};
	virtual void clear(); //needs to change visible status
	virtual bool hit(); // return whether the home player SHOULD hit or not
	virtual void showCards();
private:
	bool visible; // whether the first card is visible or not
};


class Guest : public Player
{
public:
	Guest(){};
	Guest(const string& playerName);
	~Guest(){};
	virtual bool hit(); // whether the guest player want to hit or not
	virtual void showCards();
private:
	string name; // the name of the guest player
};
#endif
