#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "caller.h"

class Employee
{
public:
	Employee(){}
	Employee(const string& name1):name(name1), free(true){}
	virtual ~Employee(){}
	bool isFree(){return free;}
	void setFree(){free=true;}
	//serve the caller, if cannot handle, escalate to next level 
	virtual bool service(const Caller& caller) = 0;
protected:
	string name;
	bool free; // busy or not
};

class Respondent : public Employee
{
public:
	Respondent(const string& name1):Employee(name1){}
	virtual bool service(const Caller& caller)
	{
		int rank=caller.getRank();
		if(rank>1)
		{
			cout<<"The respondent "<<name<<" cannot handle the call from "<<caller.getName()<<", escalate to director"<<endl;
			return false;
		}
		else
		{
			cout<<"The respondent "<<name<<" is answering the call from "<<caller.getName()<<endl;
			free=false;
			return true;
		}		
	}
};

class Director : public Employee
{
public:
	Director(const string& name1):Employee(name1){}
	virtual bool service(const Caller& caller)
	{
		int rank=caller.getRank();
		if(rank>2)
		{
			cout<<"The director "<<name<<" cannot handle the call from "<<caller.getName()<<", escalate to manager"<<endl;
			return false;
		}
		else
		{
			cout<<"The director "<<name<<" is answering the call from "<<caller.getName()<<endl;
			free=false;
			return true;
		}		
	}
};

class Manager : public Employee
{
public:
	Manager(const string& name1):Employee(name1){}
	virtual bool service(const Caller& caller)
	{
		cout<<"The manager "<<name<<" is answering the call from "<<caller.getName()<<endl;
		free=false;
		return true;
	}
};

#endif
