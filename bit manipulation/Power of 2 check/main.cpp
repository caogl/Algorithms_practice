/*If the number we are checking is a power of two, the binary representation will be a one followed by
  zeros. If we subtract one from a power of two, it is equivalent to fliping every to the right of the 1,
  including the 1 itself. Bitwise anding these two numbers together will always result in zero if x is a
  power of two, and will always result in a non-zero number if x is not a power of two.
*/

#include<iostream>
using namespace std;

bool isPow2(int x)
{
	return (x & (x-1))==0;
}

int main()
{
	cout<<isPow2(64)<<endl<<isPow2(96)<<endl;
	return 0;
}
