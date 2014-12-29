#include<string>
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

vector<int> findSubstring(string S, vector<string> &L);

int main()
{
	vector<string> L={"a", "a"};
	string S="a";
	vector<int> result=findSubstring(S, L);
	for(int i=0; i<result.size(); i++)
		cout<<result[i]<<" ";
	cout<<endl;
	return 0;
}

vector<int> findSubstring(string S, vector<string> &L)
{
        vector<int> result;
        unordered_map<string, int> hashMap;
        for(int i=0; i<L.size(); i++)
            hashMap[L[i]]++;
        int len1=L[0].size();
        int len2=L.size();
        
	int n=S.size();
        for(int i=0; i<=n-len1*len2; i++) // cannot do substraction for unsigned && signed, if use S.size instead of n, error !!!
					  // also, notice the <= rathen than <
        {
		unordered_map<string, int> hashTmp; // avoid the copy of the unordered_set, down substract element-->expensive
		int j=0;
		while(j<len2)
		{
			string strTmp=S.substr(i+j*len1, len1);
			if(hashMap.find(strTmp)==hashMap.end())
				break;
			else
			{
				hashTmp[strTmp]++;
				if(hashTmp[strTmp]>hashMap[strTmp])
					break;
			}
			j++;
		}
		if(j==len2)
			result.push_back(i);
        }
        return result;
}
