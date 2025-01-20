#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int minimumLength(string s) {
    int left = 0, right = s.length() - 1;
    
    while (left < right && s[left] == s[right]) {
        char currentChar = s[left];
        while (left <= right && s[left] == currentChar) {
            left++;
        }
        while (left <= right && s[right] == currentChar) {
            right--;
        }
    }
    
    return right - left + 1;
}


// ----my solution----------------
class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        int res=0;
        for(int i=0;i<mp.size();i++)
        {
           if(mp[i]<3)res+=mp[i];
           else if(mp[i]>=3) {
            // res=min(res,func(mp[i]));
            if(mp[i]%2==0)
            res+=2;
            else res+=(mp[i]%2);
           }
        }

        return res;
    }
};