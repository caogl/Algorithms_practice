#include"deck.h"

class Game
{
public:
	Game(){};
	Game(const vector<string>& names);
	void play();
	~Game(){}
private:
	Deck deck;
	Home homePlayer;
	vector<Guest> guestPlayer;	
};


int main()
{
	cout<<"Welcome to the Blackjack game, now let's begin to play!"<<endl;
	int playerNum=0;
	while(playerNum<1 || playerNum>7)
	{
		cout<<"How many players wants to play?"<<endl;
		cin>>playerNum;
	}
	vector<string> playerNames;
	string name;
	for(int i=0; i<playerNum; i++)
	{
		cout<<"Please enter player name: "<<endl;
		cin>>name;
		playerNames.push_back(name);
	}	

	Game game(playerNames);

	char again='y';
	while(again!='n' && again!='N')
	{
		game.play();
		cout<<"play again?"<<endl;
		cin>>again;
	}

	return 0;
}

Game::Game(const vector<string>& names)
{
	for(int i=0; i<names.size(); i++)
		guestPlayer.push_back(Guest(names[i]));	
}

void Game::play()
{
	// Issue 2 cards to home and every guest player
	deck.issueCard(homePlayer);	
	for(int i=0; i<guestPlayer.size(); i++)
	{
		deck.issueCard(guestPlayer[i]);
	}
	
	// Show the cards for home and guest player
	homePlayer.showCards();
	cout<<endl;
	for(int i=0; i<guestPlayer.size(); i++)
	{
		guestPlayer[i].showCards();
		cout<<endl;
	}

	// Each guest players begin to hit, then home player
	for(int i=0; i<guestPlayer.size(); i++)
	{
		deck.additionalCard(guestPlayer[i]);
	}
	deck.additionalCard(homePlayer);
	
	// Display the result of the game
	cout<<endl<<"The result of the game is:"<<endl;
	homePlayer.showCards();
	if(homePlayer.isBusted()) // if home player busted
	{
		cout<<"Busted"<<endl;
		for(int i=0; i<guestPlayer.size(); i++)
		{	
			guestPlayer[i].showCards();
			if(!guestPlayer[i].isBusted())
				cout<<"	Wins"<<endl;
			else
				cout<<"	Busted"<<endl;
		}
	}
	else // if home player not busted
	{
		cout<<endl;
		for(int i=0; i<guestPlayer.size(); i++)
		{
			guestPlayer[i].showCards();
			if(!guestPlayer[i].isBusted())
			{
				if(guestPlayer[i].getScore()>homePlayer.getScore())
					cout<<"	Wins"<<endl;
				else if(guestPlayer[i].getScore()==homePlayer.getScore())
					cout<<"	Pushes"<<endl;
				else
					cout<<"	Loses"<<endl;
			}
			else
			cout<<"	Busted"<<endl;
		}
	}

	//remove everyone's card for a new game
	homePlayer.clear();
	for(int i=0; i<guestPlayer.size(); i++)
	{
		guestPlayer[i].clear();
	}
}
