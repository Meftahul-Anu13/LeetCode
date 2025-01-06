#include<bits/stdc++.h>
using namespace std;

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    
    string prefix = strs[0]; // take 1st string as prefix
    for (int i = 1; i < strs.size(); ++i) {
        while (strs[i].find(prefix) != 0) { // if prefix is not present 
            prefix = prefix.substr(0, prefix.size() - 1); // remove last char
            if (prefix.empty()) return "";
        }
    }
    return prefix;    
}

int main() {
    vector<string> strs1 = {"flower", "flow", "flight"};
    vector<string> strs2 = {"dog", "racecar", "car"};
    
    cout << " Example 1: " << longestCommonPrefix(strs1) << endl; // Output: "fl"
    cout << " Example 2: " << longestCommonPrefix(strs2) << endl; // Output: ""
    
    return 0;
}