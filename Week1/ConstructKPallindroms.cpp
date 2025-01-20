#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if (n < k)
            return false;
        if (n == k)
            return true;
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        int c = 0;
        for (auto& pair : mp) {
            if (pair.second % 2 != 0)
                c++;
        }

        if (c <= k)
            return true;
            else return false;
    }
};