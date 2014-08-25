#ifndef CALLHANDLER_H
#define CALLHANDLER_H

#include"employee.h"
#include<sstream>
#include<queue>

static const int resNum=10;
static const int dirNum=4;
static const int manNum=2;

class Callhandler
{
public:
	static	Callhandler* getInstance(); // get instance of the class
	Callhandler(const Callhandler&)=delete;
	Callhandler& operator=(const Callhandler&)=delete;

	Employee* assignEmployee(const Caller& caller, const int rank);// assign employee to serve caller
	void addToQueue(const Caller& caller); // add caller to waitingQueue
	void dispatch(const Caller& caller); //dispatch callers
	void freeEmployee(); // in next timestamp, free all the employee 
	void serveQueue(); // serve the callers in the waitingQueue	
	int getTimestamp(){return timestamp;}
	void setTimestamp(int timestamp1){timestamp=timestamp1;}
private:
	Callhandler(); // make constructors virtual to prevent creating object
	~Callhandler();
	static Callhandler* ptr;
	vector<vector<Employee*> > employees;// first vector is respondent, second director, third manager
	queue<Caller> waitingQueue;	
	int timestamp;
};


#endif
