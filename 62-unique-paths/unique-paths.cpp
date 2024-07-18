class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return totalWays(m-1, n-1, dp);
    }

    int totalWays(int i, int j, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up, left = 0;
        if(i >= 0) up = totalWays(i-1, j, dp);
        if(j >= 0) left = totalWays(i, j-1, dp);

        return dp[i][j] = up + left;
    }
};