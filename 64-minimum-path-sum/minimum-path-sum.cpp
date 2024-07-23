class Solution {
public:
    int minPathSum(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        
        dp[0][0] = points[0][0];

        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if(row == 0 && col == 0) continue;
                dp[row][col] = points[row][col] + min(((row>=1) ? dp[row-1][col]: 1e9), ((col>=1) ? dp[row][col-1] : 1e9));
            }
        }

        return dp[m-1][n-1];

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