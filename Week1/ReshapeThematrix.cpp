#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>>ans(r,vector<int>(c)); //take ans 2d vector with r row and column oc c vector
        int m = mat.size();
        int n = mat[0].size();//1 vector column size
    
        if (m * n != r * c) {
        return mat; // if dont match then just the same matrix
        }
        for (int i = 0; i < m * n; ++i) {
        ans[i / c][i % c] = mat[i / n][i % n]; // 1d to 2d shapping
        }
    return ans;
        
    }
};