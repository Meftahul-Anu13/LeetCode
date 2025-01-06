#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        istringstream iss(s);
        string word; 
        vector<string>wcount;
        int maxwlen=0;
        while(iss>>word)
        {
            wcount.push_back(word); //split the word
            maxwlen = max(maxwlen, (int)word.length()); //max word length
        }

        vector<string>ans(maxwlen, string(wcount.size(), ' '));
        for(int i=0;i<wcount.size();i++)
        {
            for(int j=0;j<wcount[i].length();j++)
            {
                ans[j][i] = wcount[i][j]; //vertically adding the words 
            }
        }

        for(string& s:ans)
        {
            while(!s.empty() && s.back()==' ')
            {
                s.pop_back();// removing trailing space
            }
        }

        return ans ;

    }
};