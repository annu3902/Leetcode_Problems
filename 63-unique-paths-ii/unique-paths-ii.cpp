class Solution {
private:
    // int dfs(int x, int y, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){



    // }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // build up
        // dp[x][y] -> No. of ways to reach to (m-1, n-1).
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        // if(obstacleGrid[m-1][n-1] == 0) dp[m-1][n-1] = 1;

        for(int i=m-1; i>=0 && obstacleGrid[i][n-1] == 0; i--){
            dp[i][n-1] = 1;
        }

        for(int j=n-1; j>=0 && obstacleGrid[m-1][j] == 0; j--){
            dp[m-1][j] = 1;
        }

        for(int i=m-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                if(obstacleGrid[i][j] == 0){
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};