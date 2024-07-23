class Solution {
public:
    int minPathSum(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        // vector<vector<int>> dp(m, vector<int> (n, 0));
        vector<int> prev(n, 0);
        prev[0] = points[0][0];

        for(int row=0; row<m; row++){
            vector<int> curr(n, 0);
            for(int col=0; col<n; col++){
                if(row == 0 && col == 0) continue;
                curr[col] = points[row][col] + min(((row>=1) ? prev[col] : 1e9), ((col>=1 ? curr[col-1] : 1e9)));
            }
            prev = curr;
        }
        return prev[n-1] + points[0][0];
    }

  // Memoization
    int dfs(int row, int col, vector<vector<int>>& points, vector<vector<int>>& dp){

        if(row == 0 && col == 0) return points[0][0];

        else if(row < 0 || col < 0) return 1e9;

        if(dp[row][col] != -1) return dp[row][col];

        int up = dfs(row-1, col, points, dp);
        int left = dfs(row, col-1, points, dp);

        return dp[row][col] = points[row][col] + min(left, up);
    }
};