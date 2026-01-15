class Solution {
private:
    int dfs(int x, int y, int m, int n, vector<vector<int>>& dungeon, vector<vector<int>>& dp){

        if(x >= m || y >= n){
            return 1e8;
        }
        // Base Case
        if(x == m-1 && y == n-1){
            if(dungeon[x][y] <= 0){
                dp[x][y] = abs(dungeon[x][y]) + 1;
            }else{
                dp[x][y] = 1;
            }
        }

        if(dp[x][y] != -1) return dp[x][y];

        int op1 = dfs(x+1, y, m, n, dungeon, dp);
        int op2 = dfs(x, y+1, m, n, dungeon, dp);

        int minHealth = min(op1, op2);

        int accessHealth = minHealth - dungeon[x][y];
        if(accessHealth <= 0){
            dp[x][y] = 1;
        }else{
            dp[x][y] = accessHealth;
        }
        return dp[x][y];
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // dp[i][j] -> min health requ. to survive at (i, j);
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(0, 0, m, n, dungeon, dp);
        //  Build Up
        // for(int i=m-1; i>=0; i--){
        //     for(int j=n-1; j>=0; j--){
        //         if(i == m-1 && j == n-1){
        //             if(dungeon[m-1][n-1] <= 0){
        //                 dp[m-1][n-1] = abs(dungeon[m-1][n-1]) + 1;
        //             }else{
        //                 dp[m-1][n-1] = 1;
        //             }
        //         }
        //         else{
        //             int op1 = (i+1 <= m-1) ? dp[i+1][j] : 1e8;
        //             int op2 = (j+1 <= n-1) ? dp[i][j+1] : 1e8;
        //             int minHealth = min(op1, op2);

        //             int requiredHealth = minHealth - dungeon[i][j];
        //             if(requiredHealth <= 0){
        //                 dp[i][j] = 1;
        //             }else{
        //                 dp[i][j] = requiredHealth;
        //             }
        //         }                
        //     }
        // }
        // return dp[0][0];

    }
};