#include <bits/stdc++.h>
using namespace std;
// 1894. Find the Student that Will Replace the Chalk

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        

        for(int i=0;i<chalk.size();i++)
        {
            sum+=chalk[i];
        }
        int div=k%sum;
        int result=0;
        for(int i=0;i<chalk.size();i++)
        {
            if(div>=chalk[i])div-=chalk[i];
            else 
            {
                result=i;
                return result;
            }
        }
        return result;
    }
};