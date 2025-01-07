#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int partitionString(string s) {
        set<char>st;
        int p=1;
        for(char c:s)
        {
            if(st.find(c)!=st.end())
            {
                p++;
                st.clear();
            }
            st.insert(c);
        }
        return p;
    }
};