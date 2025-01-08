#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSuffix(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2)
            return false;
        for (int i = 0; i < n1; i++)
            if (s1[n1 - i - 1] != s2[n2 - i - 1])
                return false;
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int c=0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i < j && words[j].find(words[i]) == 0 &&isSuffix(words[i],words[j])) {
                    c++;
                }
            }
        }
    return c;
    }
};