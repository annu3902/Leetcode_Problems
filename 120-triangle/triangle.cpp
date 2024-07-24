class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        /*vector<vector<int>> dp(m, vector<int> (triangle[m-1].size(), 1e9));

        // Tabulation or Real Dynamic Programming in which we build the solution from the base case that we already known.
        for(int j=0; j<triangle[m-1].size(); j++){
            dp[m-1][j] = triangle[m-1][j];
        }

        for(int i=m-2; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                int first = dp[i+1][j];
                int second = dp[i+1][j+1];

                dp[i][j] = min(first, second) + triangle[i][j];
            }
        }

        return dp[0][0];*/


        vector<vector<int>> dp(m, vector<int>(triangle.size(), -1));

        return dfs(0, 0, triangle, dp);

    }

    int dfs(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(row == triangle.size()) return 0;
        if(dp[row][col] != -1) return dp[row][col];

        int first = dfs(row+1, col, triangle, dp);
        int second = dfs(row+1, col+1, triangle, dp);

        return dp[row][col] = min(first, second) + triangle[row][col];
    }
};