#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=1;
        int maxi=1;
        if(nums.size()==0)return 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1] +1==nums[i])
            {
                count++;
            }
            else if(nums[i]==nums[i-1])
            {
                continue;
            }
            else {
                maxi=max(maxi,count);
                count=1;
            }
  
        }
        
        return max(maxi,count);
        
    }
};
