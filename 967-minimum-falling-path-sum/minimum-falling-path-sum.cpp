class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));

        for(int j=0; j<n; j++){
            dp[n-1][j] = matrix[n-1][j];
        }

        for(int i=n-2; i>=0; i--){

            for(int j=0; j<n; j++){
                dp[i][j] = 1e9;
                for(int p=0; p<3; p++){
                    int sum = 1e9;
                    if(j+p-1 >= 0 && j+p-1 < n) sum = dp[i+1][j+p-1];
                    dp[i][j] = min(dp[i][j] , sum + matrix[i][j]);
                }

            }

        }

        return *min_element(begin(dp[0]), end(dp[0]));

        // int mini =1e9;
        // for(int j=0; j<n; j++){
        //     mini = min(mini, dfs(0, j, n, matrix, dp));
        // }

        // return mini;
    }


    int dfs(int row, int col, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(row == n)return 0;

        else if(col < 0 || col >= n) return 1e9;

        if(dp[row][col] != -1) return dp[row][col];

        int mini = 1e9;
        for(int p=0; p<3; p++){
            mini = min(mini, matrix[row][col] + dfs(row+1, col+p-1, n, matrix, dp));
        }

        return dp[row][col] = mini;
    }
};