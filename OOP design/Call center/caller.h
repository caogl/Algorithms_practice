#ifndef CALLER_H
#define CALLER_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Caller
{
public: 
	Caller(int rank1, const string& name1):rank(rank1), name(name1){}
	~Caller(){}
	int getRank() const	{return rank;}
	string getName() const	{return name;}
private:
	int rank;
	string name;
};

#endif
