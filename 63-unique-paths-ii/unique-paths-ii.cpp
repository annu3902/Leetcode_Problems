class Solution {
private:
    long long dfs(int x, int y, vector<vector<int>>& obstacleGrid, vector<vector<long long>>& dp){
        if(x >= obstacleGrid.size() || y >= obstacleGrid[0].size()) return 0;
        if(obstacleGrid[x][y] == 1) return dp[x][y] = 0;
        if(x == obstacleGrid.size()-1 && y == obstacleGrid[0].size()-1 && obstacleGrid[x][y] == 0) return dp[x][y] = 1;

        if(dp[x][y] != -1) return dp[x][y];

        dp[x][y] = dfs(x+1, y, obstacleGrid, dp) + dfs(x, y+1, obstacleGrid, dp);
        return dp[x][y];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // build up
        // dp[x][y] -> No. of ways to reach to (m-1, n-1).
        vector<vector<long long>> dp(m, vector<long long>(n, -1));

        return dfs(0, 0, obstacleGrid, dp);
    }
};