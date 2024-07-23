class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return dfs(m-1, n-1, grid, dp);
    }

    int dfs(int row, int col, vector<vector<int>>& points, vector<vector<int>>& dp){

        if(row == 0 && col == 0) return points[0][0];

        else if(row < 0 || col < 0) return 1e9;

        if(dp[row][col] != -1) return dp[row][col];

        int up = dfs(row-1, col, points, dp);
        int left = dfs(row, col-1, points, dp);

        return dp[row][col] = points[row][col] + min(left, up);
    }
};