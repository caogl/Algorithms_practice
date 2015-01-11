// reference: http://blog.csdn.net/cinderella_niu/article/details/42554843

#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

string fractionToDecimal(int numerator, int denominator);

int main()
{
	cout<<"(-1)/13 = "<<fractionToDecimal(-1, 13)<<endl;
	cout<<"(-1)/(-2147483648) = "<<fractionToDecimal(-1, -2147483648)<<endl; //(a)
	cout<<"(-2147483648)/1 = "<<fractionToDecimal(-2147483648, 1)<<endl; //(b)
	cout<<"(-2147483648)/(-1) = "<<fractionToDecimal(-2147483648, -1)<<endl; //(c)
/*
 * 	int a=-2147483648;
	int b=-1;
	cout<<a/b<<endl;
	---> if run, would cause float point exception !!!
 */
	return 0;
}

string fractionToDecimal(int numerator, int denominator)
{
	// (1): check whether numerator or denominator is 0
	if(numerator==0)	return "0";
	if(denominator==0)	return "";
	
	string result;
	// (2): adjust the sign
	if((numerator>0) ^ (denominator>0))	result+="-";
	// (3): change to long type to avoid overflow
	long num=numerator;
	long denom=denominator;
	num=abs(num);
	denom=abs(denom);
	// (4): deal with integral part
	long intPart=num/denom; // must set to long, deal with corner case (a)(b)(c)
	result+=to_string(intPart);
	long reminder=num%denom; // must set to long, deal with corner case (a)(b)(c)
	if(!reminder)
		return result;
	// (5): deal with decimal part
	result+=".";
	unordered_map<int, int> lastPos;
	while(reminder)
	{
		if(lastPos.find(reminder)!=lastPos.end())
		{
			result.insert(lastPos[reminder], 1, '(');
			result=result+")";
			return result;
		}
		lastPos[reminder]=result.size();
		reminder*=10;
		result+=to_string(reminder/denom);
		reminder%=denom;
	}
	return result;
}
