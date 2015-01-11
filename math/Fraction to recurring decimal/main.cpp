// reference: http://blog.csdn.net/cinderella_niu/article/details/42554843
/*
思路：手写计算除法方法
    0.16  
  ______
6 ) 1.00
    0 
    1 0  <-- Remainder=1, mark 1 as seen at position=0.
    - 6 
      40 <-- Remainder=4, mark 4 as seen at position=1.
    - 36 
       4 <-- Remainder=4, seen before at position=1, so the fractional part 
                          ,which is16 starts repeating at position=1 => 1(6).
                          
关键点就是如何确定循环体？
我们用一个hashmap记录每一个余数，以及该余数出现的位置，当出现重复的余数时，
说明除法开始进入循环，两个重复余数之间的部分就是循环体。
示例：1/13=0.076923076923076923...，当小数部分第二次出现0时，就意味着开始了循环，
那么需要把076923用括号括起来，结果为0.(076923)。
*/
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
	unordered_map<long, int> lastPos;
	while(reminder)
	{
		//如果这个余数出现过，说明分数除法开始循环 停止计算,在第一次出现的位置插入‘（’，在最后插入‘）’  
		if(lastPos.find(reminder)!=lastPos.end())
		{
			result.insert(lastPos[reminder], 1, '(');
			result=result+")";
			return result;
		}
		//记录此时的余数和位置 
		lastPos[reminder]=result.size();
		//如果没有出现循环，按照手写计算除法的方法计算除法: 补零，做除法；然后取余数，作为下一次计算分子  
		reminder*=10;
		result+=to_string(reminder/denom);
		reminder%=denom;
	}
	return result;
}
