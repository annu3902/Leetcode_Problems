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

        // Space Optimization 
        vector<int> prev(n, 0);
        for(int col=0; col<n; col++){
            prev[col] = grid[m-1][col];
        }

        for(int i=m-2; i>=0; i--){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){

                int mini = 1e9;
                int u = grid[i][j];
                for(int k=0; k<n; k++){
                    mini = min(u + moveCost[u][k] + prev[k], mini);
                }

                curr[j] = mini;
            }
            prev = curr;
        }

        return *min_element(begin(prev), end(prev));
        // return mini;
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