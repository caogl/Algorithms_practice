// cracking the coding interview 18.4
// reference: http://www.hawstein.com/posts/20.4.html
 
/* Write a method to count the number of 2s between 0 and n. */

#include<iostream>
using namespace std;

/* solution (1): brute and force: runtime--> O(nlogn) */
int Count2(int n);
int Count2s(int n);

/* solution (2): O(1) runtime
假设一个5位数N=abcde，我们现在来考虑百位上出现2的次数，即，从0到abcde的数中， 有多少个数的百位上是2。分析完它，
就可以用同样的方法去计算个位，十位，千位， 万位等各个位上出现2的次数。
当百位c为0时，比如说12013，0到12013中哪些数的百位会出现2？我们从小的数起， 200~299, 1200~1299, 2200~2299, … , 
11200~11299, 也就是固定低3位为200~299，然后高位依次从0到11，共12个。再往下12200~12299 已经大于12013，因此不再往下。
所以，当百位为0时，百位出现2的次数只由更高位决定， 等于更高位数字(12)x当前位数(100)=1200个。
当百位c为1时，比如说12113。分析同上，并且和上面的情况一模一样。 最大也只能到11200~11299，所以百位出现2的次数也是
1200个。
上面两步综合起来，可以得到以下结论：
当某一位的数字小于2时，那么该位出现2的次数为：更高位数字x当前位数
当百位c为2时，比如说12213。那么，我们还是有200~299, 1200~1299, 2200~2299, … , 11200~11299这1200个数，他们的百位为2。
但同时，还有一部分12200~12213， 共14个(低位数字+1)。所以，当百位数字为2时， 百位出现2的次数既受高位影响也受低位影响,

结论如下：
(1)当某一位的数字等于2时，那么该位出现2的次数为：更高位数字x当前位数+低位数字+1
   当百位c大于2时，比如说12313，那么固定低3位为200~299，高位依次可以从0到12， 这一次就把12200~12299也包含了，
(2)同时也没低位什么事情。因此出现2的次数是： (更高位数字+1)x当前位数。结论如下：
(3)当某一位的数字大于2时，那么该位出现2的次数为：(更高位数字+1)x当前位数

如果我们把问题一般化一下：写一个函数，计算0到n之间i出现的次数，i是1到9的数。 这里为了简化，i没有包含0，
因为按以上的算法计算0出现的次数， 比如计算0到11间出现的0的次数，会把1，2，3，4…视为01，02，03，04… 
从而得出错误的结果。所以0是需要单独考虑的，为了保持一致性，这里不做讨论。 将上面的三条结论应用到这就是：
(1)当某一位的数字小于i时，那么该位出现i的次数为：更高位数字x当前位数
(2)当某一位的数字等于i时，那么该位出现i的次数为：更高位数字x当前位数+低位数字+1
(3)当某一位的数字大于i时，那么该位出现i的次数为：(更高位数字+1)x当前位数 */

int count2s(int n, int k);

int main()
{
	cout<<Count2s(12013)<<endl;
	cout<<count2s(12013, 2)<<endl;        
	return 0;
}

int count2s(int n, int k)
{
    if(k<1 || k>9) return -1; //k只能是1到9
    
    int count = 0;
    int factor = 1;
    int low = 0, cur = 0, high = 0;
    while(n/factor != 0)
    {
        low = n - (n/factor) * factor; //低位数字
        cur = (n/factor) % 10; //当前位数字
        high = n / (factor*10); //高位数字

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
