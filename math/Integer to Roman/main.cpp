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
using namespace std;

string intToRoman(int num);

int main()
{
	cout<<intToRoman(3923)<<endl;
	return 0;
}

string intToRoman(int num)
{
        string result;
        int digit=(int)(num/1000);
        for(int i=0; i<digit; i++)
            result+='M';
       
        num=num%1000;
        digit=(int)(num/100);
        if(digit!=0)
        {
            if(digit<4)
                for(int i=0; i<digit; i++)
                    result+='C';
            else if(digit==4)
                result+="CD";
            else if(digit<=8)
            {
                result+='D';
                for(int i=5; i<digit; i++)
                    result+='C';
            }
            else // digit==9
                result+="CM";
        }
        
        num=num%100;
        digit=(int)(num/10);
        if(digit!=0)
        {
            if(digit<4)
                for(int i=0; i<digit; i++)
                    result+='X';
            else if(digit==4)
                result+="XL";
            else if(digit<=8)
            {
                result+='L';
                for(int i=5; i<digit; i++)
                    result+='X';
            }
            else // digit==9
                result+="XC";
        }
        
        num=num%10;
        digit=num;
        if(digit!=0)
        {
            if(digit<4)
                for(int i=0; i<digit; i++)
                    result+='I';
            else if(digit==4)
                result+="IV";
            else if(digit<=8)
            {
                result+='V';
                for(int i=5; i<digit; i++)
                    result+='I';
            }
            else // digit==9
                result+="IX";
        }
        
        return result;
}
