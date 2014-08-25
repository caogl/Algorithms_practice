#include "player.h"

Player::Player()
{
	sum=0;
}

void Player::add(Card& card)
{
	cardsNow.push_back(card);
	int cardValue=card.getValue();
	if(cardValue==11 && (sum+cardValue)>21)
		cardValue=1;
	sum+=cardValue;
}

int Player::getScore()
{
	return sum;
}

void Player::clear()
{
	sum=0;
	cardsNow.clear();
}

void Home::clear()
{
	Player::clear();
	visible=false;
}

bool Guest::hit()
{
	cout<<name<<", do you want to hit?"<<endl;
	char answer;
	cin>>answer;
	return(answer=='y' || answer=='Y');
}

Guest::Guest(const string& playerName)
{
	sum=0;
	name=playerName;
}

void Guest::showCards()
{
	cout<<name<<": ";
	for(int i=0; i<cardsNow.size(); i++)
	{
		cout<<getCardInfo(cardsNow[i], true)<<"	";
	}
	cout<<sum;
}

Home::Home():Player(),visible(false){}


bool Home::hit()
{
	visible=true;
	return (sum<=16);
}

void Home::showCards()
{
	cout<<"Home player: ";
	for(int i=0; i<cardsNow.size(); i++)
	{
		if(i==0)
			cout<<getCardInfo(cardsNow[i], visible)<<"	";
		else
			cout<<getCardInfo(cardsNow[i], true)<<"	";
	}
	if(visible)
		cout<<sum;
	else
		cout<<"XX";
}
	
bool Player::isBusted()
{	
	return (sum>21);
}
