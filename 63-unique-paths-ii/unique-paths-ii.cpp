class Solution {
public:
int dp[101][101];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1] == 1) return 0;

        return dfs(obstacleGrid, 0, 0, m, n);
    }

    int dfs(vector<vector<int>> &obstacleGrid, int i, int j, int m, int n){

        if(i==m-1 && j==n-1) return 1;

        if(i >= m || j >= n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int op1 = 0;
        int op2 = 0;
        if(obstacleGrid[i][j] == 0){
            op1 = dfs(obstacleGrid, i, j+1, m, n);
            op2 = dfs(obstacleGrid, i+1, j, m, n);
        }

        return dp[i][j] = (op1 + op2);

    }
};