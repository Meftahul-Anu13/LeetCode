#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to calculate LCM of two numbers
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// Function to calculate the product of elements in a subarray
long long product(const vector<int>& nums, int start, int end) {
    long long prod = 1;
    for (int i = start; i <= end; ++i) {
        prod *= nums[i];
    }
    return prod;
}

// Function to find the length of the longest product equivalent subarray
int longestProductEquivalentSubarray(const vector<int>& nums) {
    int n = nums.size();
    int maxLength = 0;

    for (int i = 0; i < n; ++i) {
        int currentGCD = nums[i];
        int currentLCM = nums[i];
        long long currentProd = nums[i];

        for (int j = i; j < n; ++j) {
            if (j > i) {
                currentGCD = gcd(currentGCD, nums[j]);
                currentLCM = lcm(currentLCM, nums[j]);
                if (currentProd > LLONG_MAX / nums[j]) {
                    break; // Prevent overflow
                }
                currentProd *= nums[j];
            }

            if (currentProd == currentLCM * currentGCD) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums1 = {1, 2, 1, 2, 1, 1, 1};
    vector<int> nums2 = {2, 3, 4, 5, 6};
    vector<int> nums3 = {1, 2, 3, 1, 4, 5, 1};

    cout << "Example 1: " << longestProductEquivalentSubarray(nums1) << endl; // Output: 5
    cout << "Example 2: " << longestProductEquivalentSubarray(nums2) << endl; // Output: 3
    cout << "Example 3: " << longestProductEquivalentSubarray(nums3) << endl; // Output: 5

    return 0;
}

