#include"callhandler.h"

Callhandler::Callhandler()
{
	vector<vector<Employee*> > temp(3);
	// initiate respondents
	for(int i=0; i<resNum; i++)
	{
		ostringstream ss;
		ss<<(i+1);
		string name1="Respondent"+ss.str();
		temp[0].push_back(new Respondent(name1));
	}
	
	// initiate directors	
	for(int i=0; i<dirNum; i++)
	{
		ostringstream ss;
		ss<<(i+1);
		string name1="Director"+ss.str();
		temp[1].push_back(new Director(name1));
	}

	// initiate managers
	for(int i=0; i<manNum; i++)
	{
		ostringstream ss;
		ss<<(i+1);
		string name1="Manager"+ss.str();
		temp[2].push_back(new Manager(name1));
	}
	employees=temp;
	timestamp=1;
}

Callhandler::~Callhandler()
{
	for(int i=0; i<employees.size(); i++)
		for(int j=0; j<employees[i].size(); j++)
			delete employees[i][j];
}

Callhandler* Callhandler::ptr=nullptr;

Callhandler* Callhandler::getInstance()
{
	if(!ptr)
		ptr=new Callhandler;
	return ptr;
}

Employee* Callhandler::assignEmployee(const Caller& caller, const int rank)
{
	for(int i=0; i<employees[rank-1].size(); i++)
		if(employees[rank-1][i]->isFree())
			return employees[rank-1][i];
	return nullptr;
}

void Callhandler::addToQueue(const Caller& caller)
{
	cout<<caller.getName()<<" is waiting to be serviced"<<endl;
	waitingQueue.push(caller);
}

void Callhandler::dispatch(const Caller& caller)
{
	Employee* temp=assignEmployee(caller, 1);
	if(!temp)
	{	
		addToQueue(caller);
	}
	else
	{
		if(temp->service(caller))
		{
			return;
		}
		else
		{
			temp=assignEmployee(caller, 2);
			if(!temp)
			{
				addToQueue(caller);
			}
			else
			{
				if(temp->service(caller))
					return;
				else
				{
					temp=assignEmployee(caller, 3);
					if(!temp)
						addToQueue(caller);
					else
						temp->service(caller);
				}
			}
		}
	}
}

void Callhandler::freeEmployee()
{
	for(int i=0; i<employees.size(); i++)
		for(int j=0; j<employees[i].size(); j++)
			employees[i][j]->setFree();
}

void Callhandler::serveQueue() // serve the callers in the waitingQueue
{
	int num=waitingQueue.size();
	while(num>0)
	{
		dispatch(waitingQueue.front());
		waitingQueue.pop();
		num--;
	}
}
