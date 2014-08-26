#include <iostream>
#include <string>
using namespace std;

string print_binary(string val)
{
    	int pos = val.find_first_of('.', 0);
	cout<<pos<<endl;
    	int intpart = atoi(val.substr(0, pos).c_str());
	cout<<intpart<<endl;
    	int decpart = atoi(val.substr(pos+1, val.length()-pos-1).c_str());
	cout<<decpart<<endl;
    	string intstr = "", decstr = "";
    	while(intpart > 0)
	{
        	if(intpart&1) 
			intstr = "1" + intstr;
        	else 
			intstr = "0" + intstr;
        	intpart >>= 1;
    	}
    	while(decpart > 0)
	{
        	if(decstr.length() > 6) 
			return "ERROR";
        	if(decpart&1) 
			decstr = "1" + decstr;
        	else 
			decstr = "0" + decstr;
        	decpart >>= 1;
        }
    	return intstr + "." + decstr;
}

int main()
{
	string val = "19.25";
    	cout<<print_binary(val)<<endl;
    	return 0;
}

