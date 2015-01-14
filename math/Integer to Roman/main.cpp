/* reference: leetcode cleancode official handbook
The subtractive notation:
Four characters are avoided being repeated in succession (such as IIII). Instead, the 
symbol I could appear before V and X to signify 4 (IV) and 9 (IX) respectively. Using the 
same pattern, we observe that X could appear before L and C to signify 40 (XL) and 90 
(XC) respectively. The same pattern could be applied to C that is placed before D and M.

Using the additive notation, we convert to roman numerals by breaking it so each chunk 
can be represented by the symbol entity. For example, 11 = 10 + 1 = “X” + “I”. Similarly, 
6 = 5 + 1 = “V” + “I”. Let’s take a look of an example which uses the subtractive
notation: 49 = 40 + 9 = “XL” + “IX”. Note that we treat “XL” and “IX” as one single 
entity to avoid dealing with these special cases to greatly simplify the code.
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string intToRoman(int num);

int main()
{
	cout<<intToRoman(49)<<endl; // XLIX
	return 0;
}

string intToRoman(int num)
{
	vector<int> values={1000,900,500,400,100,90,50,40,10,9,5,4,1};
	vector<string> symbols={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	string result;
	int i=0;
	while(num>0)
	{
		int k=num/values[i];
		for(int j=0; j<k; j++)
		{
			result+=symbols[i];
			num-=values[i];
		}
		i++;
	}
	return result;
        return result;
}
