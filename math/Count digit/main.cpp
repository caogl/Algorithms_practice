// cracking the coding interview 18.4
// reference: http://www.hawstein.com/posts/20.4.html
 
/* Write a method to count the number of 2s between 0 and n. */

#include<iostream>
using namespace std;

/* solution (1): brute and force: runtime--> O(nlogn) */
int Count2(int n);
int Count2s(int n);

/* solution (2): O(1) runtime */
int count2s(int n, int k);

int main()
{
	cout<<Count2s(12013)<<endl;
	cout<<count2s(12013, 2)<<endl;        
	return 0;
}

int count2s(int n, int k)
{
    int count = 0;
    int factor = 1;
    int low = 0, cur = 0, high = 0;

    while(n/factor != 0)
    {
        low = n - (n/factor) * factor;//¿?¿?¿?¿?
        cur = (n/factor) % 10;//¿?¿?¿?¿?¿?
        high = n / (factor*10);//¿?¿?¿?¿?

        if(cur < k)
            count += high * factor;
        else if(cur == k)
            count += high * factor + low + 1;
        else
            count += (high + 1) * factor;
        factor *= 10;
    }
    return count;
}

int Count2(int n)
{
    int count = 0;
    while(n > 0)
    {
        if(n%10 == 2)
            ++count;
        n /= 10;
    }
    return count;
}

int Count2s(int n)
{
    int count = 0;
    for(int i=0; i<=n; ++i)
        count += Count2(i);
    return count;

}
