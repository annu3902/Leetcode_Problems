class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();

        // Tabulation
        // vector<vector<int>> dp(m,vector<int>(n, 0));
        // 0 health is showing that i am easily sail at this value

        /*for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i == m-1 && j == n-1){
                    dp[i][j] = min(0, dungeon[i][j]);
                }

                else if(i == m-1){
                    dp[i][j] = min(0, dungeon[i][j] + dp[i][j+1]);
                }

                else if(j == n-1){
                    dp[i][j] = min(0, dungeon[i][j] + dp[i+1][j]);
                }

                else{
                    dp[i][j] = min(0, dungeon[i][j] + max(dp[i][j+1], dp[i+1][j]));
                }
            }
        }

        return abs(dp[0][0]) + 1;*/

        vector<vector<int>> dp(m, vector<int> (n, -1));

        return abs(dfs(0, 0, m, n, dungeon, dp)) + 1;
    }

    int dfs(int row, int col, int m, int n, vector<vector<int>>& dungeon, vector<vector<int>>& dp){

        if(row==m-1 && col==n-1){
            return min(0, dungeon[row][col]);
        }

        else if(row >= m || col >= n){
            return -1e9;
        }

        if(dp[row][col] != -1) return dp[row][col];

        return dp[row][col] = min(0, dungeon[row][col] + max(dfs(row+1, col, m, n, dungeon, dp), dfs(row, col+1, m, n, dungeon, dp)));

    }

};