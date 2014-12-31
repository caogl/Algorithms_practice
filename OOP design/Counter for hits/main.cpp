// from: http://nuttynanaus.wordpress.com/2014/03/09/software-engineer-interview-questions/
/*
 * uestion:

Write a counter for hits received in the past 15 minutes.

My Answer:

The first thing is to choose granularity. Here is an example to explain what is granularity: 
if there were three hits, happened at 0.5s,  900s, 900.6s, (900s == 15min), then, at 900s,
there are 2 hits in the past 15min, but at 900.6s, the first hit (happened at 0.5s) is happened before 15min, 
so the answer is still 2. However, in real-life, counter are usually for monitoring purpose, 
we probably only query the result every 1 second (and very likely the frequency is lower than this), 
so we don퓍 have to be that accurate about the time. Also it usually doesn퓍 matter if one hit is 0.1s off,
or even 1 second off for a 15min counter: assume the data are randomly generated,
1 second off will only contribute to about 1/900 error. In most of the case that is ignorable.

We could have lower than 1 second granularity, however, in Software Engineer, there are lot of trade offs. 
If we support full accuracy of time and granularity, then we퓄l lose efficiency, we퓄l use more memory, 
and it may cause more complicate logic that is harder to maintain. So the first thing is to understand the real problem and constrains 
(e.g. what is it used for, do we care more on accuracy, or 0.1% of error is acceptable but we want better efficiency, etc). 
In real-life, assume a 1 second granularity is a good trade off in most of the cases. At the end of this blog I퓄l describe a solution if we want the full accuracy.

Suppose we only need 1 second granularity, then the thing become simpler.
We can have a rolling window array of 900 elements to store the hit in each second. We also need to maintain some metadata. Here is the code
 */

#include<iostream>
#include<unistd.h>
#include<ctime>
using namespace std;

template <int N=900>
class Counter
{
public:
 	Counter()
	{
		memset(count, 0, sizeof(count));
  		lastPosition = 0;
  		sum = 0;
  		lastTime = time(nullptr);
	}
	void hit()
	{
  		move();
  		count[lastPosition]++;
  		sum++;
 	}
	int getcount() 
	{
  		move();
  		return sum;
 	}
private:
	int count[N];
	int lastPosition;
 	int lastTime;
 	int sum;

 	void move() 
	{
		int t = time(NULL);
		int gap = min(t - lastTime, N);
		for (int k = 0; k < gap; ++k)
		{
   			lastPosition = (lastPosition + 1) % N;
   			sum -= count[lastPosition];
   			count[lastPosition] = 0;
  		}
  		lastTime = t;
 	}

};

/*
 * What if we want full accuracy? Actually this is simpler, as we don퓍 have much room for optimization. 
 * What we need is to record all the raw data. We can use a queue for the purpose.
 */

class Counter 
{
public:
  	void hit()
	{
    		move();
    		hits.push(now);
  	}

  	void getcounter()
	{
    		move();
    		return hits.size();
  	}
private:
	queue hits; // the float is the timestamp (in seconds)
	float now;

  	void move()
	{
    		now = getCurrentTime(); // in seconds in float number to support full accuracy
    		while (!hits.empty() && hits.front() < now - 900)
      			hits.pop();
    	}
};

/*
This is simpler, accurate, but cost more memory and less efficient. for example, if we use the counter for QPS, 
and suppose the QPS is around 1k, the first version requires to store about 900 integers, the second 
version requires to store 900k floats. When updating, in 15min, the first version will call move 900 times, 
the second version will call pop() 900k times. For high-frequent counter, the second version will introduce 
a lot more overhead, while only gives very little benefit (full accuracy instead of 0.1% of error).

we may design more complicated logic that will be more efficient, but then the code will be much 
longer and the logic will be harder to maintain (think of in multi-threading environment, for example).

So there is no perfect solution, everything is just a trade off between different aspect. 
Know the resources and constrainswill help you to make the right trade offs.
*/
