#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        vector<pair<int,int>>p;

        for(int i=0;i<nums.size();i++)
        {
            p.push_back({nums[i],i});
        }
        sort(p.begin(),p.end());
        while(l<r)
        {
            int sum = p[l].first+p[r].first;
            if(sum==target)
            {
                return {min(p[l].second,p[r].second),max(p[l].second,p[r].second)};
            }
            else if(sum<target)
            {
                l++;
            }
            else {
                r--;
            }
        }
        return {};
    }
};