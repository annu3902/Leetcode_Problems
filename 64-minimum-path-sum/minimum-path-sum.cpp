class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        for(int i=m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i+1 >= m || j+1 >= n){
                    dp[i][j] = grid[i][j] + max(dp[i][j+1], dp[i+1][j]);
                }
                else
                    dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};