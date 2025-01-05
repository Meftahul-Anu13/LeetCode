#include<bits/stdc++.h>
using namespace std;

/*
Think like 2 sum problem and then take target as -ve of first element and then find 2 sum in rest of the array
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int tar=0;
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int t=-nums[i];
            if (i > 0 && nums[i] == nums[i - 1]) continue; //1st duplicates
            int l=i+1;int r=nums.size()-1;
            while(l<r)
            {
                int sum =nums[l]+nums[r];
                if(t==sum)
                {
                    v.push_back({nums[i],nums[l],nums[r]});
                    while(l<r && nums[l]==nums[l+1])l++;//2nd and 3rd dupl
                    while(l<r && nums[r]==nums[r-1])r--;//2nd and 3rd dupl
                    l++;
                    r--;
                }
                else if(sum<t)
                {
                    l++;
                }
                else r--;
            }
        }

        return v;
        
    }
};