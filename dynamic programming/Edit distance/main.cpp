#include<string>
#include<vector>
#include<iostream>
using namespace std;

// 2-dimensional dynamic programming
int minDistance(string word1, string word2);

int main()
{
	string s1="caoguanglei";
	string s2="weichunlei";
	cout<<"Distance is: "<<minDistance(s1, s2)<<endl;

	return 0;
}

int minDistance(string word1, string word2) 
{
        int s1=word1.size();
        int s2=word2.size();
        if(s1==0)
            return s2;
        if(s2==0)
            return s1;
        vector<int> vec1(s2+1);
	// the minimum distance of transforming from word1[0:i] to word2[0:j]
        vector<vector<int> > vec(s1+1, vec1); 
        for(int i=0; i<s1+1; i++)
            vec[i][0]=i;
        for(int i=0; i<s2+1; i++)
            vec[0][i]=i;
        int m1, m2, m3;
        for(int i=1; i<s1+1; i++)
        {
            for(int j=1; j<s2+1; j++)
            {
                if(word1[i-1]==word2[j-1]) // state transformation 1
                    m1=vec[i-1][j-1];
                else
                    m1=vec[i-1][j-1]+1;
                m2=vec[i-1][j]+1; // state transformation 2
                m3=vec[i][j-1]+1; // state transformation 3
                vec[i][j]=min(min(m1, m2), m3);
            }
        }
        return vec[s1][s2];
}
