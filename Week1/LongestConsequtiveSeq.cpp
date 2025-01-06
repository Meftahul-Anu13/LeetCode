#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle empty input

        sort(nums.begin(), nums.end()); // Sort the array

        int longest = 1; // To track the length of the longest sequence
        int current = 1; // To track the length of the current sequence

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue; // Skip duplicates
            }
            if (nums[i] == nums[i - 1] + 1) {
                current++; // Increment current sequence length
                cout<<nums[i]<<endl;
            } else {
                longest = max(longest, current); // Update longest sequence
                current = 1; // Reset current sequence length
            }
        }

        return max(longest, current); // Ensure the final sequence is considered
    }
};

int main() {
    Solution s;
    vector<int> v = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    cout << s.longestConsecutive(v) << endl;
}
