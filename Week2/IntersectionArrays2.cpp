#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int> res;
        if(m>n)
        {
            for(int i=0;i<n;i++)
            {
                auto it=find(nums1.begin(),nums1.end(),nums2[i]);
                if(it!=nums1.end())
                {
                    res.push_back(nums2[i]);
                    nums1.erase(it);
                }
            }
        }
        else
        {
            for(int i=0;i<m;i++)
            {
                auto it=find(nums2.begin(),nums2.end(),nums1[i]);
                if(it!=nums2.end())
                {
                    res.push_back(nums1[i]);
                    nums2.erase(it);
                }
            }
        }

        return res;
    }
};