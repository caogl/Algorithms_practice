// (1) http://www.geeksforgeeks.org/swap-two-nibbles-byte/ (2) Coding interview solutions mannual 50
// Question: Write a function that takes a byte and swaps the the first 4 bits with the last 4 bits.
/*
eg: if x=01011010
(1) x1 = (00001111 & x)<<4 = 10100000
(2) x2 = (11110000 & x)>>4 = 00000101
(3) x3 = x1|x2             = 10100101
*/

#include<iostream>
using namespace std;

unsigned char swapNibbles(unsigned char x)
{
    return ( (x & 0x0F)<<4 | (x & 0xF0)>>4 );
}
 
int main()
{
    unsigned char x = 100;
    printf("%u\n", swapNibbles(x));
    return 0;
}
