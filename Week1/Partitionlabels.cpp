#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        vector<int>v;
        int l=0;int r=0;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]] =i ;
        }
        for(int i=0;i<s.length();i++)
        {
            l=max(l,mp[s[i]]);
            if(i==l)
            {
                v.push_back(i-r+1);
                r=i+1;
            }
        }
        return v;        
    }
};