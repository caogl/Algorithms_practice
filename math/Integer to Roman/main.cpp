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
