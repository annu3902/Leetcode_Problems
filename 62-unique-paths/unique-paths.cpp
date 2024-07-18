class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        vector<int> prev(n, 1);
        // dp[0][0] = 1;

        for(int i=1; i<m; i++){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                // if(i == 0 && j == 0) continue;
                curr[j] = ((i>=1) ? prev[j] : 0) + ((j>=1) ? curr[j-1] : 0);
            }
            prev = curr;
        }

        return prev[n-1];
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