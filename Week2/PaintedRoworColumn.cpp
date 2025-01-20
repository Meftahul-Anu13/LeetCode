#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> pos(m * n+1);
        vector<int> row(m, 0), col(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[mat[i][j]] ={i,j} ;
            }
        }

        for (int i = 0; i < arr.size(); ++i) {
            int val = arr[i];
            int r = pos[val].first;
            int c = pos[val].second;
            row[r]++;
            col[c]++;
            if (row[r] == n || col[c] == m) {
                return i;
            }
        }
        return -1;
    }
};
