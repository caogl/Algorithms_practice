#include"card.h"

Card::Card(int num)
{
	cardNum=num;
}

int Card::getValue()
{
	int rank=cardNum%13;
	if(rank>10 || rank==0)
		rank=10;
	if(rank==1)
		rank=11; //ACE
	return rank;
}


string getCardInfo(const Card& card, bool visible)
{
	if(visible==false)
		return "XX";
	const string cardName[]={"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	int index1=card.cardNum;
	index1=index1%13-1;
	if(index1==-1)
		index1=12;
	string str1=cardName[index1];
	int index2=card.cardNum%4;
	string str2;
	switch(index2)
	{
		case 0:
			str2="S";
			break;
		case 1:
			str2="H";
			break;
		case 2:
			str2="C";
			break;
		case 3:
			str2="D";
			break;
	}
	return str1+str2;
}



