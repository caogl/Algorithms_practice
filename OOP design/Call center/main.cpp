#include"callhandler.h"
#include<fstream>
//#include<string>
//using namespace std;

int main()
{
	string fileName;
	cout<<"Please enter the caller file name: "<<endl;
	cin>>fileName;
	ifstream in;
	in.open(fileName);
	while(in.fail())
	{
		cout<<"Please enter the caller file name again: "<<endl;
		cin>>fileName;
		in.open(fileName);
	}
	string line;
	string::size_type lasPos, pos;
	vector<string> vec;
	string delimiter="	 ";
	
	getline(in, line); // the label line
	while(getline(in, line))
	{
		lasPos=line.find_first_not_of(delimiter, 0);
		pos=line.find_first_of(delimiter, lasPos);
		while(lasPos!=string::npos || pos!=string::npos)
		{
			vec.push_back(line.substr(lasPos, pos-lasPos));
			lasPos=line.find_first_not_of(delimiter, pos);
			pos=line.find_first_of(delimiter, lasPos);
		}
		int timestamp=atoi(vec[0].c_str());
		if(timestamp!=Callhandler::getInstance()->getTimestamp())
		{
			Callhandler::getInstance()->setTimestamp(timestamp);
			Callhandler::getInstance()->freeEmployee();
			Callhandler::getInstance()->serveQueue();
		}
		
		int rank=atoi(vec[2].c_str());
		string name=vec[1];
		Callhandler::getInstance()->dispatch(Caller(rank, name));
		vec.clear();
	} 
	
	return 0;
}
