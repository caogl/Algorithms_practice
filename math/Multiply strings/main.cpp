#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

/* cannot pass leetcode largest cases, time limit exceed, no care, as long as result is right, this question just make u pay attention to details*/

string multiply(string num1, string num2);
/* it is very easy to cause errors to pass string by & in helper functions since the multiply function is by value! */
string multiply(string num, string single, int j);
string add(string num1, string num2);

int main()
{
	string num1="120";
	string num2="12";
	string result=multiply(num1, num2);
	//reverse(result.begin(), result.end());
	cout<<result<<endl;
}


string add(string num1, string num2)
{
	int i=0, j=0;
	int carry=0;
	string result;
	while(i!=num1.size() && j!=num2.size())
	{
		int tmp=(num1[i]-'0')+(num2[j]-'0')+carry;
		if(tmp>=10)
		{
			carry=1;
			tmp-=10;
			result=result+to_string(tmp);
		}
		else
		{
			carry=0;
			result=result+to_string(tmp);
		}
		i++;
		j++;
	}
	while(i!=num1.size())
	{
		int tmp=(num1[i]-'0')+carry;
		if(tmp>=10)
		{
			carry=1;
			tmp-=10;
			result=result+to_string(tmp);
		}
		else
		{
			carry=0;
			result=result+to_string(tmp);
		}
		i++;
	}
	while(j!=num2.size())
	{
		int tmp=(num2[j]-'0')+carry;
		if(tmp>=10)
		{
			carry=1;
			tmp-=10;
			result=result+to_string(tmp);
		}
		else
		{
			carry=0;
			result=result+to_string(tmp);
		}
		j++;
	}
	if(carry)
		result=result+'1';
	return result;
}

string multiply(string num, string single, int j)
{
	int carry=0;
	int singleN=single[0]-'0';
	string result;
	for(int i=0; i<num.size(); i++)
	{
		int tmp=(num[i]-'0')*singleN+carry;
		carry=tmp/10;
		tmp=tmp%10;
		result=result+to_string(tmp);
	}

	/* dont't forget! */
	if(carry!=0)
		result=result+to_string(carry);

	for(int i=0; i<j; i++)
		result='0'+result;	
	return result;
}

string multiply(string num1, string num2)
{
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	string result="0";
	for(int j=0; j<num2.size(); j++)
	{
		string tmp=multiply(num1, num2.substr(j, 1), j);
		result=add(result, tmp);
	}	
	reverse(result.begin(), result.end());
	return result;
}

/* overflow even using unsigned long long 
string multiply(string num1, string num2) 
{
        unsigned long long n1=0;
        unsigned long long n2=0;
        unsigned long long multi=1;
        for(int i=num1.size()-1; i>=0; i--)
        {
            n1+=multi*(num1[i]-'0');
            multi*=10;
        }
        multi=1;
        for(int i=num2.size()-1; i>=0; i--)
        {
            n2+=multi*(num2[i]-'0');
            multi*=10;
        }
        unsigned long long n3=n1*n2;
        ostringstream ss;
        ss<<n3;
        return ss.str();
}
*/
