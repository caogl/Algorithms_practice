#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

struct CacheObj
{
	CacheObj(int key1, int value1):key(key1), value(value1){}
	int key;
	int value;
};

class LRUCache
{
public:
	LRUCache(int capacity1):capacity(capacity1){}
	int get(int key1); // return the value
	void set(int key1, int value1);
private:
	void moveToHead(int key1);

	//unorder_map<int, int> hashTable;---bad design, cannot find and replace in O(1) time!
	unordered_map<int, list<CacheObj>::iterator> hashMap;
	list<CacheObj> cacheQueue; // most recently used from head, least recently used from the tail
	int capacity;
};


int main()
{
	LRUCache cache(5);
	cache.set(1, 101);
	cache.set(2, 102);
	cache.set(3, 103);
	cache.set(4, 104);
	cache.set(5, 105);
	cout<<"the key 2: "<<cache.get(2)<<"the key 7:"<<cache.get(7)<<endl;
	//order should now be 25431
	cache.set(6, 106);
	cache.set(7, 107);
	cout<<"the key 1: "<<cache.get(1)<<" the key 2:"<<cache.get(2)<<" the key 3: "<<cache.get(3)<<" the key 4: "<<cache.get(4)<<" the key 7: "<<cache.get(7)<<endl;	
	// order should now be 76254
	return 0;
}

void LRUCache::moveToHead(int key1)
{
	list<CacheObj>::iterator itr=hashMap[key1];
	CacheObj temp=*itr;
	cacheQueue.erase(itr);
	cacheQueue.push_front(temp);
	hashMap[key1]=cacheQueue.begin();
}

int LRUCache::get(int key1)
{
	if(hashMap.find(key1)==hashMap.end())
		return -1;
	else
	{
		moveToHead(key1);
		return hashMap[key1]->value;
	}
}

void LRUCache::set(int key1, int value1)
{
	if(hashMap.find(key1)==hashMap.end())
	{
		if(cacheQueue.size()==capacity)
		{
			//remove from tail
			hashMap.erase(cacheQueue.back().key);
			cacheQueue.pop_back();
		}
		
		//insert in head
		cacheQueue.push_front(CacheObj(key1, value1));
		hashMap[key1]=cacheQueue.begin();
	}
	else
	{
		hashMap[key1]->value=value1;
		moveToHead(key1);
	}
}
