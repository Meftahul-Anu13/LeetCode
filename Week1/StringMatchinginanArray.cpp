#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        // vector<string> v;
        set<string>st;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(i != j && words[i].find(words[j]) != std::string::npos)
                {
                    // v.push_back(words[j]);
                    st.insert(words[j]);
                }
            }
        }
        vector<string> v(st.begin(), st.end());
        return v;
        
    }
};