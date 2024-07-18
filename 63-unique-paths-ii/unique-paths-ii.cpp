class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1] == 1) return 0;

        // vector<vector<int>> dp(m, vector<int> (n, 0));
        // dp[0][0] = 1;
        vector<int> prev(n, 0);
        bool flag = false;

        for(int i=0; i<n; i++){
            while(i < n && obstacleGrid[0][i] == 0 && flag == 0) {
                prev[i] = 1;
                i++;
            }
            flag = true;
            if(flag && i < n) prev[i] = 0;
        }

        for(int i=1; i<m; i++){

            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                curr[j] = ((i>=1 && obstacleGrid[i-1][j] == 0) ? prev[j] : 0) + ((j>=1 && obstacleGrid[i][j-1] == 0) ? curr[j-1] : 0);
            }

            prev = curr;
        }

        return prev[n-1];

        // return f(m-1, n-1, obstacleGrid, dp);
    }

    int f(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return dp[0][0] = 1;

        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int left = 0;
        int up = 0;

        if(i >= 1 && obstacleGrid[i-1][j] == 0) up = f(i-1, j, obstacleGrid, dp);
        if(j >= 1 && obstacleGrid[i][j-1] == 0) left = f(i, j-1, obstacleGrid, dp);

        return dp[i][j] = up + left;
    }   
};