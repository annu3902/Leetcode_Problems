class Solution {
public:
    int dfs(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){

        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]){
            return 1 + dfs(i-1, j-1, text1, text2, dp);
        }

        return dp[i][j] = max(dfs(i-1, j, text1, text2, dp), dfs(i, j-1, text1, text2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){

                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }

                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }

            }
        }

        return dp[m][n];
        // return dfs(m-1, n-1, text1, text2, dp);
    }
};