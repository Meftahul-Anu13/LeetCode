#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int prefixsum=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        int count=0;
        for(int i=0;i<n;i++)
        {
            prefixsum+=nums[i];
            //cout<<prefixsum<<" "<<i<<endl;
            if(mp.find(prefixsum-k)!=mp.end())
            {
                count+=mp[prefixsum-k];
                //cout<<count<<" " <<mp[prefixsum-k]<<" "<<i<<endl;
            }
           mp[prefixsum]++;// if prefixsum is already present in map then increment its count
            //cout<<val<<" "<<i<<endl;
         
        }

        // for(int i=0;i<mp.size();i++)
        // {
        //     cout<<mp[i]<<" ";
        // }
        return count;


    }
};
int main() {
    Solution s;
    vector<int> nums={1,2,2};
    int k=2;
    cout<<s.subarraySum(nums,k)<<endl;
    return 0;
}