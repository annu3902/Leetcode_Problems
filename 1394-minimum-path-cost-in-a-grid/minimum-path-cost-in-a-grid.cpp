class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>> dp(m, vector<int>(n, -1));

        // int mini = 1e9;
        // for(int j=0; j<n; j++){
        //     mini = min(mini, dfs(0, j, m, n, grid, moveCost, dp));
        // }

        // Tabulation
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int col=0; col<n; col++){
            dp[m-1][col] = grid[m-1][col];
        }

        for(int i=m-2; i>=0; i--){
            for(int j=0; j<n; j++){

                int mini = 1e9;
                int u = grid[i][j];
                for(int k=0; k<n; k++){
                    mini = min(u + moveCost[u][k] + dp[i+1][k], mini);
                }

                dp[i][j] = mini;
            }
        }

        int mini = 1e9;
        for(int j=0; j<n; j++){
            mini = min(mini, dp[0][j]);
        }

        return mini;
    }

    // Memoization
    /*int dfs(int row, int col, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& dp){

        if(row == m-1){
            return grid[row][col];
        }

        if(dp[row][col] != -1) return dp[row][col];
        
        int mini = 1e9;

        int u = grid[row][col];
        for(int k=0; k<n; k++){
            mini = min(mini, u + moveCost[u][k] + dfs(row+1, k, m, n, grid, moveCost, dp));
        }
        
        return dp[row][col] = mini;
    }*/
};