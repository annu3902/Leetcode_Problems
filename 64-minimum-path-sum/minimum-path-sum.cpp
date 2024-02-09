class Solution {
private:
    int f(int i, int j, vector<vector<int>> & grid, vector<vector<int>> &dp){
        int m = grid.size();
        int n = grid[0].size();
        // Base Case
        if(i >= m || j >= n){
            return INT_MAX;
        }

        if(i == m-1 && j == n-1){
            return dp[i][j] = grid[m-1][n-1];
        }

        // else{
            if(dp[i][j] != -1){
                return dp[i][j];
            }
            // else{
                dp[i][j] = grid[i][j] + min(f(i, j+1, grid, dp), f(i+1, j, grid, dp));
                return dp[i][j];
            // }
        // }
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return f(0,0,grid,dp);
        // dp[m-1][n-1] = grid[m-1][n-1];

        // for(int i = 0; i <= m-2; i++){
        //     for(int j = 0; j <= n-2; j++){
        //         dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j]);
        //     }
        // }
        // return dp[0][0];
    }
};