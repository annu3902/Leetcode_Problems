class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(); // Number of rows
        int m = grid[0].size(); // Number of columns
        vector<vector<int>> dp(n, vector<int>(m, -1)); // Table to remember results
        int ans = 0; // To track the longest path

        // Try starting from each row in the first column
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(grid, i, 0, n, m, dp)); // Find the longest path from (i, 0)
        }

        return ans; // Return the longest path found
    }

    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<int>>& dp) {
        // If out of bounds, return 0 (no more moves)
        if (i < 0 || i >= n || j >= m) {
            return 0;
        }

        // If already calculated, return the stored result
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0; // Max steps from this cell

        // Check possible moves to the right
        if (j + 1 < m) {
            // Up-right move
            if (i - 1 >= 0 && grid[i - 1][j + 1] > grid[i][j]) {
                ans = max(ans, 1 + dfs(grid, i - 1, j + 1, n, m, dp));
            }
            // Right move
            if (grid[i][j + 1] > grid[i][j]) {
                ans = max(ans, 1 + dfs(grid, i, j + 1, n, m, dp));
            }
            // Down-right move
            if (i + 1 < n && grid[i + 1][j + 1] > grid[i][j]) {
                ans = max(ans, 1 + dfs(grid, i + 1, j + 1, n, m, dp));
            }
        }

        // Save and return the result for this cell
        dp[i][j] = ans;
        return ans;
    }
};