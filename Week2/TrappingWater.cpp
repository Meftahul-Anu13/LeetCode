#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>l,r;
        l.push_back(0);
        r.push_back(height[n-1]);
        for(int i=1;i<n;i++){
            l.push_back(max(l[i-1],height[i-1]));
            r.push_back(max(r[i-1],height[n-i]));
        }
        reverse(r.begin(),r.end());
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(0,min(l[i],r[i])-height[i]);
        }
        return ans;

    }
};