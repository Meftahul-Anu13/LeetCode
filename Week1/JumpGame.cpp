#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach=0;
        for(int i=0;i<nums.size();i++)
        {
            reach=max(reach,nums[i]+i);
            if(i>reach) return false;
            if(reach>=nums.size()-1) return true;
        }
        return false;
    }
};