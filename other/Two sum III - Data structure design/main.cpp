class TwoSum 
{
public:
	void add(int number) 
	{
	    hashMap[number]++;
	}

	bool find(int value) 
	{
	    for(auto itr=hashMap.begin(); itr!=hashMap.end(); itr++)
	    {
	        int tmp=value-itr->first;
	        if(hashMap.find(tmp)!=hashMap.end()) // deal with self duplicate
	        {
	            if(tmp==itr->first)
	            {
	                if(hashMap[tmp]>1)
	                    return true;
	                continue;
	            }
	            return true;
	        }
	    }
	    return false;
	}
private:	
	unordered_map<int, int> hashMap;
};
