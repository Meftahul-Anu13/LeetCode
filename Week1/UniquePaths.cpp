class Solution {
public:
    int uniquePaths(int m, int n) {
        // if(m==1||n==1)return 1;   
        // return uniquePaths(m-1,n)+uniquePaths(m,n-1);
        // recursive solution casues TLE so use memoisation
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return recursive(m - 1, n - 1, memo);
    }
    int recursive(int m, int n, vector<vector<int>>& memo) {
        if (m == 0 || n == 0)
            return 1;
        if (memo[m][n] != -1)
            return memo[m][n];
        memo[m][n] = recursive(m - 1, n, memo) + recursive(m, n - 1, memo);
        return memo[m][n];
    }
};