#include<unordered_set>
#include<string>
#include<iostream>
using namespace std;

string minWindow(string S, string T);

int main()
{	string s1="ADOBECODEBANC";
	string t1="ABC";
	cout<<"The minimum window substring is: "<<minWindow(s1, t1)<<endl;
	return 0;
}

string minWindow(string S, string T) 
{
        unordered_set<char> all; //put T in a hash table
        unordered_set<char> unfilled; 
        //unordered_map<char, int> times;
        for(int i=0; i<T.size(); i++)
        {
            //times.insert(make_pair(T[i], 0));
            all.insert(T[i]);
        }
        unfilled=all;
        string result="";
        string tmp;
        int start=0;

        while(start<S.size())
        {
	    //cout<<"here1"<<start<<" "<<S.size()<<endl;
            int i=start;
            while(unfilled.find(S[i])==unfilled.end())  
            {
	        i++;
                if(i==S.size())
                    return result;
            }
            start=i;
            while(true)
            {
                if(unfilled.find(S[i])!=unfilled.end())
                {	
	            cout<<i<<"haha"<<endl;
		    cout<<unfilled.size()<<endl;    
                    unfilled.erase(S[i]);
	            if(unfilled.empty())
	                break;
                }
                i++;
                if(i>=S.size())
                    return result;
            }
	    cout<<"hahahaha"<<" "<<i<<" "<<start<<endl;
            tmp=T.substr(start, i-start+1);
	    if(result=="")
	        result=tmp;
            else if(tmp.size()<result.size())
	    {
                result=tmp;
		//cout<<"haha"<<endl;
	    }
            unfilled=all;
            start=start+1;
        }
        return result;
}
